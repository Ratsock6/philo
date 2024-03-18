/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:07:46 by aallou-v          #+#    #+#             */
/*   Updated: 2024/03/15 18:57:26 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_core	core;
	char	*error;

	error = parsing(argc, argv, &core);
	if (error)
	{
		ft_putendl_fd(error, 2);
		return (0);
	}
	init_philo(&core);
	if (!start(&core))
	{
		ft_putendl_fd("Thread Error !", 2);
		return (0);
	}
	
}
