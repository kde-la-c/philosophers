/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:47:23 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/05 18:47:26 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	read_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parsing(t_main *data, int argc, char **argv)
{
	if (read_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->nb_philos = ft_atoi(argv[1]);
	data->t_death = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->loops = ft_atoi(argv[5]);
	else
		data->loops = 0;
	return (EXIT_SUCCESS);
}
