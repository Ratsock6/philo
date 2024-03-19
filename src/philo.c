/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:23:40 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/19 18:33:20 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(philo->core->arg.t_eat / 10);
	while (!check_death(philo, 0))
	{
		pthread_create(&philo->thread_death_id, NULL, is_dead, data);
		activity(philo);
		pthread_detach(philo->thread_death_id);
		if ((int)++philo->nb_eat == philo->last_eat)
		{
			pthread_mutex_lock(&philo->core->arg.finish);
			philo->is_finish = 1;
			philo->core->arg.n_philo_finish++;
			if (philo->core->arg.n_philo_finish == philo->core->arg.n_philo)
			{
				pthread_mutex_unlock(&philo->core->arg.finish);
				check_death(philo, 2);
			}
			pthread_mutex_unlock(&philo->core->arg.finish);
			return (NULL);
		}
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
		continue ;
	}
	return (1);
}

