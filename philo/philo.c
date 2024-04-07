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
	int		ret;
	t_main	*data;

	data = (t_main *)malloc(sizeof(t_main) * 1);
	if (parsing(data, argc, argv) == EXIT_FAILURE)
		return (print_error("Error\nbad arguments"));
	else if (parsing(data, argc, argv) == EXIT_FAILURE + 1)
		return (free(data), print_error("Error\nCouldn't initialize philos"));
	ret = philosophers(data);
	if (ret == EXIT_FAILURE)
		return (free_struct(data, 0), print_error("Error"));
	else if (ret == 2)
		return (free_struct(data, 0), EXIT_FAILURE);
	free_struct(data, data->nb_philos);
	return (EXIT_SUCCESS);
}
