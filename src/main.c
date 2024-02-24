/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:07:46 by aallou-v          #+#    #+#             */
/*   Updated: 2024/02/24 19:40:58 by aallou-v         ###   ########.fr       */
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
		ft_putendl_fd(error, 1);
		return (0);
	}
}