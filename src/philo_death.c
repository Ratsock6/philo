/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:29:47 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/19 18:31:49 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, size_t i)
{
	pthread_mutex_lock(&philo->core->arg.dead);
	if (i)
		philo->core->arg.stop = i;
	if (philo->core->arg.stop)
	{
		pthread_mutex_unlock(&philo->core->arg.dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->core->arg.dead);
	return (0);
}

void	*is_dead(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	usleep(philo->core->arg.t_die + 1);
	pthread_mutex_lock(&philo->core->arg.time_eat);
	pthread_mutex_lock(&philo->core->arg.finish);
	if (!check_death(philo, 0) && !philo->is_finish && ((get_actual_time() - philo->last_eat) >= (long)(philo->core->arg.t_die)))
	{
		pthread_mutex_unlock(&philo->core->arg.time_eat);
		pthread_mutex_unlock(&philo->core->arg.finish);
		philo_print(philo, DEAD);
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->core->arg.time_eat);
	pthread_mutex_unlock(&philo->core->arg.finish);
	return (NULL);
}