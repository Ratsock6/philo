/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:29:47 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/22 17:18:36 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->core->arg.m_finish);
	if ((get_time(philo->core) - philo->last_eat >= philo->core->arg.t_die)
		&& !philo->core->arg.finish)
	{
		philo_print(philo, DEAD);
		philo->core->arg.finish = true;
		pthread_mutex_unlock(&philo->core->arg.m_finish);
		return (true);
	}
	pthread_mutex_unlock(&philo->core->arg.m_finish);
	return (false);
}
