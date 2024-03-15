/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:23:40 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/15 17:59:21 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_print(t_philo *philo, t_states states, t_core *core)
{
	size_t	t;

	//pthread_mutex_lock(&philo->program->check);
	//t = ft_get_time() - philo->program->time_start;
	// if (!philo->program->is_finish)
	// {
	// 	if (states == FORK)
	// 		printf("\e[92m%5li %3li has taken a fork.\e[0m\n", t, philo->id);
	// 	else if (states == EAT)
	// 		printf("\e[32m%5li %3li is eating.\e[0m\n", t, philo->id);
	// 	else if (states == SLEEP)
	// 		printf("\e[94m%5li %3li is sleeping.\e[0m\n", t, philo->id);
	// 	else if (states == THINK)
	// 		printf("\e[33m%5li %3li is thinking.\e[0m\n", t, philo->id);
	// 	else if (states == DEAD)
	// 		printf("\e[31m%5li %3li died.\e[0m\n", t, philo->id);
	// }
	//pthread_mutex_unlock(&philo->program->check);
}