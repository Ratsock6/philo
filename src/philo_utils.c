/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:26:43 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/22 16:42:40 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, t_states states)
{
	long	t;

	pthread_mutex_lock(&philo->core->arg.write);
	t = get_time(philo->core);
	if (!philo->is_finish)
	{
		if (states == FORK)
			printf("\e[92m%5li Philosophers %10s[%3li] has taken a fork.\e[0m\n", t, philo->name, philo->id);
		else if (states == EAT)
			printf("\e[32m%5li Philosophers %10s[%3li] is eating.\e[0m\n", t, philo->name, philo->id);
		else if (states == SLEEP)
			printf("\e[94m%5li Philosophers %10s[%3li] is sleeping.\e[0m\n", t, philo->name, philo->id);
		else if (states == THINK)
			printf("\e[33m%5li Philosophers %10s[%3li] is thinking.\e[0m\n", t, philo->name, philo->id);
		else if (states == DEAD)
			printf("\e[31m%5li Philosophers %10s[%3li]died.\e[0m\n", t, philo->name, philo->id);
	}
	pthread_mutex_unlock(&philo->core->arg.write);
}


void	sleep_think(t_philo *philo)
{
	size_t	i;
	
	if (!is_dead(philo))
	{
		philo_print(philo, SLEEP);
		pthread_mutex_lock(&philo->core->arg.time_wait);
		i = philo->core->arg.t_sleep;
		pthread_mutex_unlock(&philo->core->arg.time_wait);
		philo_wait(philo, i);
	}
}

void	eat(t_philo *philo)
{
	size_t	i;

	philo_print(philo, EAT);
	pthread_mutex_lock(&philo->core->arg.time_wait);
	pthread_mutex_lock(&philo->core->arg.m_check);
	philo->nb_eat++;
	if (philo->core->arg.n_eat != -1 && philo->nb_eat == philo->core->arg.n_eat)
	{
		if (!philo->is_finish)
			philo->core->arg.n_philo_finish++;
		philo->is_finish = true;
	}
	philo->last_eat = get_time(philo->core);
	i = philo->core->arg.t_eat;
	pthread_mutex_unlock(&philo->core->arg.time_wait);
	pthread_mutex_unlock(&philo->core->arg.m_check);
	philo_wait(philo, i);
	pthread_mutex_unlock(&philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_f);
	philo_print(philo, FORK);
	pthread_mutex_lock(philo->right_f);
	philo_print(philo, FORK);
}
