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

///TODO ensure t_data structure is well allocated before being passed to spawn()

void	*routine(void *arg)
{
	// int		phid;
	t_data	data;

	// phid = ((int *)arg)[0];
	data = ((t_data *)arg)[1];
	// pthread_mutex_lock(&(((pthread_mutex_t **)arg)[4])[0]);
	// pthread_mutex_lock(&data.cutlery[phid]);
	printf("phid %i\n", ((int *)arg)[0]);
	print_tstamp(data.stsec, data.stusec);
	usleep(data.args[1] * 1000);
	usleep(data.args[2] * 1000);
	// pthread_mutex_unlock(&(((pthread_mutex_t **)arg)[4])[0]);
	// pthread_mutex_unlock(&data.cutlery[phid]);
	return (NULL);
}

int	despawn(int nbphilos, pthread_t *tids, pthread_mutex_t *cutlery)
{
	int	i;

	i = 0;
	while (i < nbphilos)
	{
		if (pthread_detach(tids[i]))
			return (1);
		if (pthread_mutex_destroy(&cutlery[i++]))
			return (2);
	}
	return (0);
}

int	spawn(pthread_t tid, t_arg arg)
{
	if (pthread_create(&tid, NULL, routine, &arg))
		return (1);
	return (0);
}

int	spawner(int *args)
{
	int				i;
	t_data			data;
	struct timeval	tv;
	pthread_t		*tids;
	t_arg			*arg;

	i = 0;
	arg = malloc(sizeof(t_arg) * args[0]);
	data.args = args;
	tids = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	data.cutlery = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args[0]);
	gettimeofday(&tv, NULL);
	data.stsec = tv.tv_sec;
	data.stusec = tv.tv_usec;
	while (i < args[0])
	{
		arg[i].data = &data;
		arg[i].phid = i;
		pthread_mutex_init(&(data.cutlery[i]), NULL);
		spawn(tids[i], arg[i]);
		i++;
	}
	despawn(args[0], tids, data.cutlery);
	free(tids);
	free(data.cutlery);
	return (0);
}
