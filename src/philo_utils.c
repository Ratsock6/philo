/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:26:43 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/19 18:36:36 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, t_states states)
{
	long	t;

	pthread_mutex_lock(&philo->core->arg.write_mutex);
	t = get_time(philo->core);
	if (!philo->is_finish)
	{
		if (states == FORK)
			printf("\e[92m%5li %3li has taken a fork.\e[0m\n", t, philo->id);
		else if (states == EAT)
			printf("\e[32m%5li %3li is eating.\e[0m\n", t, philo->id);
		else if (states == SLEEP)
			printf("\e[94m%5li %3li is sleeping.\e[0m\n", t, philo->id);
		else if (states == THINK)
			printf("\e[33m%5li %3li is thinking.\e[0m\n", t, philo->id);
		else if (states == DEAD)
			printf("\e[31m%5li %3li died.\e[0m\n", t, philo->id);
	}
	pthread_mutex_unlock(&philo->core->arg.write_mutex);
}


void	sleep_think(t_philo *philo)
{
	philo_print(philo, SLEEP);
	usleep(philo->core->arg.t_sleep);
	philo_print(philo, THINK);
}

void	activity(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_f);
	philo_print(philo, FORK);
	if (!philo->right_f)
	{
		usleep(philo->core->arg.t_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_f);
	philo_print(philo, FORK);
	philo_print(philo, EAT);
	philo->last_eat = get_actual_time();
	pthread_mutex_unlock(&philo->core->arg.time_eat);
	usleep(philo->core->arg.t_eat);
	pthread_mutex_unlock(philo->right_f);
	pthread_mutex_unlock(&philo->left_f);
	sleep_think(philo);
}