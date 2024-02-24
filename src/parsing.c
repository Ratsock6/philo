/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:07:28 by aallou-v          #+#    #+#             */
/*   Updated: 2024/02/24 19:41:05 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	**reformed(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' && ft_strlen(argv[i]) > 1)
			j++;
		while (argv[i][j] == '0')
			j++;
		if (j != '0')
			argv[i] = &argv[i][j];
	}
	return (argv);
}

char	*parsing(int argc, char **argv, t_core *core)
{
	int	i;

	if (argc < 5 || argc > 6)
		return ("./philo <number_of_philo> <time_to_die> <time_to_eat> \
					<time_to_sleep> [number_of_times_each_philo_must_eat]");
	argv = reformed(argc, argv);
	i = 0;
	while (++i < argc)
	{
		if (!ft_isonly(argv[i], "0123456789"))
			return ("Invalide Argument");
	}
	core->n_philo = ft_atoul(argv[1]);
	if (core->n_philo <= 1)
		return ("Number of philosophers incorrect ! (retard)");
	core->t_died = ft_atoul(argv[2]);
	core->t_eat = ft_atoul(argv[3]);
	core->t_sleep = ft_atoul(argv[4]);
	if (argc == 6)
	{
		core->is_limit = true;
		core->n_eat = ft_atoul(argv[5]);
	}
	return (NULL);
}
