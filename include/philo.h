/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:39:00 by cjouenne          #+#    #+#             */
/*   Updated: 2024/03/18 17:38:10 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <stdbool.h>
# include <stddef.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_arg
{
	size_t					n_philo;
	size_t					n_eat;
	size_t					t_die;
	size_t					t_eat;
	size_t					t_sleep;
	long					start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	size_t					n_philo_finish;
	size_t					stop;
}							t_arg;

typedef struct s_philo
{
	size_t				id;
	pthread_t			thread_id;
	pthread_t			thread_death_id;
	pthread_mutex_t		*right_f;
	pthread_mutex_t		left_f;
	t_arg				*pa;
	struct s_core		*core;	
	long long			last_eat;
	unsigned int		nb_eat;
	bool				is_finish;
}						t_philo;

typedef struct  s_core
{
	struct s_philo	*philo;
	struct s_arg	arg;
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
void	init_philo(t_core *core);
long	get_actual_time(void);
long	get_time(t_core *core);
int		start(t_core *core);
void	philo_print(t_philo *philo, t_states states);

#endif
