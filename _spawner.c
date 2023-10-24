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

///NOTE error on thread creation, reference is lost

void	*routine(void *arg)
{
	int		phid;
	t_data	data;

	phid = ((int *)arg)[0];
	data = ((t_data *)arg)[1];
	usleep(phid * 1000);
	pthread_mutex_lock(&data.cutlery);
	usleep(10000);
	printf("->%p\n", &data.cutlery);
	pthread_mutex_unlock(&data.cutlery);
	return (NULL);
}

int	despawn(int nbphilos, pthread_t *tids, pthread_mutex_t *cutlery)
{
	int	i;
	int	j;
	(void)cutlery;

	i = 0;
	while (i < nbphilos)
	{
		j = pthread_join(tids[i], NULL);
		if (j)
		{
			printf(">%i\n", j);
			perror("hey");
			exit(1);
		}
		// if (pthread_mutex_destroy(&cutlery[i++]))
		// 	return (2);
	}
	return (0);
}

int	spawn(pthread_t **tids, t_arg arg)
{
	static int	i = 0;
	int			j;

	// i = 0;
	j = pthread_create(tids[i], NULL, routine, &arg);
	i += 1;
	// ptid = tid + i;
	if (j)
		return (1);
	return (0);
}

int	spawner(int *args)
{
	int				i;
	t_data			data;
	struct timeval	tv;
	pthread_t		**tids;
	t_arg			*arg;

	i = 0;
	arg = malloc(sizeof(t_arg) * args[0]);
	data.args = args;
	tids = (pthread_t **)malloc(sizeof(pthread_t **) * args[0]);
	while (tids[i])
		tids[i++] = malloc(sizeof(pthread_t *));
	// data.cutlery = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args[0]);
	pthread_mutex_init(&data.cutlery, NULL);
	gettimeofday(&tv, NULL);
	data.stsec = tv.tv_sec;
	data.stusec = tv.tv_usec;
	while (i < args[0])
	{
		arg[i].data = &data;
		arg[i].phid = i;
		// pthread_mutex_init(&(data.cutlery[i]), NULL);
		spawn(tids, arg[i]);
		i++;
	}
	despawn(args[0], *tids, NULL);
	if (pthread_mutex_destroy(&data.cutlery))
		return (2);
	free(tids);
	free(arg);
	// free(data.cutlery);
	return (0);
}
