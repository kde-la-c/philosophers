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
	if (parsing(data, argc, argv) == EXIT_FAILURE)
		return (free(data), print_error("Error\nCouldn't initialize philos"));
	if (philosophers(data) == EXIT_FAILURE)
		return (free_struct(data, 0), print_error("Error"));
	free_struct(data, data->nb_philos);
	return (EXIT_SUCCESS);
}
