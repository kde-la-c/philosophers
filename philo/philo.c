/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:09:36 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/03 19:09:38 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	*data;

	data = (t_main *)malloc(sizeof(t_main) * 1);
	ft_bzero((void *)data, sizeof(t_main));
	if (parsing(data, argc, argv) == EXIT_FAILURE)
		return (print_error("Error\nInvalid input\n"));
	if (philosophers(data) == EXIT_FAILURE)
		return (print_error("Error\n"));
	free_struct(data);
	return (EXIT_SUCCESS);
}
