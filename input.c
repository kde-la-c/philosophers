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

int	read_args(int argc, char **argv)
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
				return (-2);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parsing(int *args, int argc, char **argv)
{
	int	i;

	i = 0;
	if (read_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	args = malloc(sizeof(int) * argc);
	while (i + 1 < argc)
	{
		args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (EXIT_SUCCESS);
}
