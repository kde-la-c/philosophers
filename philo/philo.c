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
	ret = parsing(data, argc, argv);
	if (ret)
		return (print_errno(ret));
	ret = philosophers(data);
	free_struct(data, data->nb_philos);
	return (SUCCESS);
}
