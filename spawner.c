/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:21:53 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/09 23:21:55 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	print_tstamp(((long *)data)[1], ((long *)data)[2]);
	usleep(((int **)data)[3][2] * 1000);
	usleep(((int **)data)[3][3] * 1000);
	return (NULL);
}

int	despawn(int nbphilos, pthread_t *tids, pthread_mutex_t *cutlery)
{
	int	i;

	i = 0;
	while (i < nbphilos)
	{
		if (pthread_join(tids[i], NULL))
			return (1);
		if (pthread_mutex_destroy(&cutlery[i++]))
			return (2);
	}
	return (0);
}

int	spawn(pthread_t tid, t_data data)
{
	if (pthread_create(&tid, NULL, routine, &data))
		return (1);
	return (0);
}

int	spawner(int *args)
{
	int				i;
	t_data			data;
	pthread_t		*tids;
	struct timeval	tv;

	i = 0;
	data.args = args;
	tids = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	data.cutlery = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args[0]);
	gettimeofday(&tv, NULL);
	data.stsec = tv.tv_sec;
	data.stusec = tv.tv_usec;
	while (i < args[0])
	{
		data.phid = i;
		pthread_mutex_init(&(data.cutlery[i]), NULL);
		spawn(tids[i], data);
		i++;
	}
	despawn(args[0], tids, data.cutlery);
	gettimeofday(&tv, NULL);
	free(tids);
	free(data.cutlery);
	return (0);
}
