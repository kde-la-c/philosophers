/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:06:28 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/14 21:06:31 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	int	perror_exit(char *err)
	{
		perror(err);
		exit(1);
	}

int	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

void	print_tstamp(t_inst *inst, char *status)
{
	pthread_mutex_lock(&inst->data->print);
	printf("%ims - %i %s\n", get_tstamp() - inst->data->starttime, inst->id,
		status);
	pthread_mutex_unlock(&inst->data->print);
}
