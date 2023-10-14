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
	struct timeval	tv;

	printf("phid? %i\n", ((int *)data)[0]);
	gettimeofday(&tv, NULL);
	// printf(">%ld, %ld\n", tv.tv_sec, tv.tv_usec);
	printf(">%ld, %ld\n", tv.tv_sec - ((long int *)data)[1], tv.tv_usec - ((long int *)data)[2]);
	return (NULL);
}

int	spawn(pthread_t tid, t_data data)
{
	usleep(100000);
	if (pthread_create(&tid, NULL, routine, &data))
		return (1);
	if (pthread_join(tid, NULL))
		return (2);
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
	printf("deb %ld, %ld\n", tv.tv_sec, tv.tv_usec);
	data.stsec = tv.tv_sec;
	data.stusec = tv.tv_usec;
	while (i < args[0])
	{
		data.phid = i;
		pthread_mutex_init(&(data.cutlery[i]), NULL);
		spawn(tids[i], data);
		i++;
	}
	gettimeofday(&tv, NULL);
	printf("fin %ld, %ld\n", tv.tv_sec, tv.tv_usec);
	free(tids);
	free(data.cutlery);
	return (0);
}
