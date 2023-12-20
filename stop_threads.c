/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:13 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/12/19 19:10:16 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_main *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data->st_fork)
		free(data->st_fork);
	if (data)
		free(data);
}


