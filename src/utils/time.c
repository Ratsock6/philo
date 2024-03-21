/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:34:03 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/21 23:01:51 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

long	get_time(t_core *core)
{
	return (get_actual_time() - core->arg.start_t);
}

void	philo_wait(t_philo *philo, long wait_time)
{
	long	time_it_die;

	time_it_die =  philo->core->arg.t_die - (get_time(philo->core)
		- philo->last_eat);
	if (time_it_die < wait_time)
		wait_time = time_it_die;
	if (0 < wait_time)
		usleep(wait_time * 1000);
}
