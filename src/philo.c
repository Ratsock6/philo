/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:23:40 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/21 23:27:24 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_alone(t_philo *philo)
{
	bool	is_alone;

	is_alone = false;
	pthread_mutex_lock(&philo->core->arg.m_check);
	if (philo->core->arg.n_philo == 1)
	{
		is_alone = true;
		philo_print(philo, THINK);
		philo_print(philo, FORK);
		usleep(philo->core->arg.t_die * 1000);
		philo_print(philo, DEAD);
	}
	pthread_mutex_unlock(&philo->core->arg.m_check);
	return (is_alone);
}

void	check(t_core *core)
{
	size_t	i;

	pthread_mutex_lock(&core->arg.m_check);
	i = -1;
	while (++i < core->arg.n_philo)
	{
		if (!core->philo[i].is_finish)
		{
			pthread_mutex_unlock(&core->arg.m_check);
			return ;
		}
	}
	core->arg.finish = true;
	pthread_mutex_unlock(&core->arg.m_check);
}

bool	is_finish(t_philo *philo)
{
	bool	is_finish;

	pthread_mutex_lock(&philo->core->arg.m_finish);
	is_finish = philo->core->arg.finish;
	pthread_mutex_unlock(&philo->core->arg.m_finish);
	return (is_finish);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!is_finish(philo))
	{
		if (is_alone(philo))
			return (NULL);
		if (is_dead(philo))
			break ;
		if (!is_dead(philo) && !philo->core->arg.finish)
			take_fork(philo);
		if (!is_dead(philo) && !philo->core->arg.finish)
			eat(philo);
		if (!is_dead(philo) && !philo->core->arg.finish)
			sleep_think(philo);
		if (!is_dead(philo) && !philo->core->arg.finish)
			philo_print(philo, THINK);
		check(philo->core);
	}
	return (NULL);
}

int	start(t_core *core)
{
	size_t	i;
	int		check;

	i = -1;
	while (++i < core->arg.n_philo)
	{
		check = pthread_create(&core->philo[i].thread_id, NULL, routine \
			, &core->philo[i]);
		if (check != 0)
			return (0);
	}
	i = 0;
	while (i < core->arg.n_philo)
	{
		pthread_join(core->philo[i].thread_id, NULL);
		i++;
	}
	return (1);
}
