/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:39:00 by cjouenne          #+#    #+#             */
/*   Updated: 2024/02/24 19:31:45 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <stdbool.h>
# include <stddef.h>
# include <pthread.h>


typedef struct  s_core
{
	size_t  n_philo;
	size_t  t_eat;
	size_t  t_died;
	size_t  t_sleep;
	size_t	n_eat;
	bool	is_limit;
	
}	t_core;

typedef enum e_states
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_states;

size_t	ft_atoul(char *s);
char	*parsing(int argc, char **argv, t_core *core);

#endif
