/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:12:05 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/15 17:55:07 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_core *core)
{
	size_t	i;

	core->arg.stop = 0;
	core->arg.n_philo_finish = 0;
	core->arg.start_t = actual_time();
	i = -1;
	while (++i < core->arg.n_philo)
	{
		core->philo[i].id = i + 1;
		core->philo[i].last_eat = actual_time();
		core->philo[i].nb_eat = 0;
		core->philo[i].is_finish = 0;
		core->philo[i].right_f = NULL;
		pthread_mutex_init(&core->philo[i].left_f, NULL);
		if (i != 0)
			core->philo[i - 1].right_f = &core->philo[i].left_f;
	}
	core->philo[i - 1].right_f = &core->philo[0].left_f;
}
