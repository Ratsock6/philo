/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:26:43 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/18 17:37:13 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, t_states states)
{
	long	t;

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
}