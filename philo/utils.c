/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:59:32 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/05 18:59:33 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	now(t_main *data)
{
	return (get_tstamp() - data->starttime);
}

int	get_tstamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_msleep(t_philo *phi, int sleeptime)
{
	int				orig_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	orig_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (get_tstamp() < orig_time + sleeptime)
	{
		if ((!phi->meals && now(phi->data) > phi->data->t_death)
		|| (phi->meals && now(phi->data) > phi->lastmeal + phi->data->t_death)
		|| phi->data->nb_philos == 1)
		{
			pthread_mutex_lock(&phi->data->stop);
			phi->data->dead = phi->id;
			pthread_mutex_unlock(&phi->data->stop);
			return ;
		}
		usleep(50);
	}
}
