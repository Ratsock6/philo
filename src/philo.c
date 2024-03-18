/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:23:40 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/18 19:28:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo_print(philo, FORK);
	return (NULL);
}

int	start(t_core *core)
{
	size_t	i;

	i = -1;
	while (++i < core->arg.n_philo)
	{
		pthread_create(&core->philo[i].thread_id, NULL, routine, &core->philo[i]);
	}
	return (1);
}

