/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:07:59 by kde-la-c          #+#    #+#             */
/*   Updated: 2024/02/29 17:08:02 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = (str[i] - 48) + (ret * 10);
		i++;
	}
	return (ret * sign);
}

static void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	unsigned char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
	s = tmp;
}

static int	init_philo(t_main *data, t_philo **philos, int id)
{
	philos[id] = (t_philo *)malloc(sizeof(t_philo));
	if (!philos[id])
		return (ERR_FAILURE);
	ft_bzero((void *)philos[id], sizeof(t_philo));
	philos[id]->thd = (t_thd *)malloc(sizeof(t_thd));
	if (!philos[id]->thd)
		return (free(philos[id]), ERR_FAILURE);
	philos[id]->id = id + 1;
	philos[id]->lfork = &data->forks[id];
	if (id + 1 == data->nb_philos)
		philos[id]->rfork = &data->forks[0];
	else
		philos[id]->rfork = &data->forks[id + 1];
	philos[id]->data = data;
	return (SUCCESS);
}

static int	fill_structure(t_main *data, int argc, char **argv)
{
	int	i;

	i = -1;
	data->nb_philos = ft_atoi(argv[1]);
	data->t_death = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->dead = 0;
	if (argc == 6)
		data->loops = ft_atoi(argv[5]);
	data->forks = (t_mtx *)malloc(sizeof(t_mtx) * data->nb_philos);
	if (!data->forks)
		return (ERR_FAILURE);
	data->philos = (t_philo **)malloc(sizeof(t_philo *) * data->nb_philos);
	if (!data->philos)
		return (free_struct(data, 0), ERR_FAILURE);
	while (++i < data->nb_philos)
		if (init_philo(data, data->philos, i) == ERR_FAILURE)
			return (free_struct(data, i), ERR_FAILURE);
	return (SUCCESS);
}

int	parsing(t_main *data, int argc, char **argv)
{
	if (!data)
		return (ERR_ALLOC);
	ft_bzero((void *)data, sizeof(t_main));
	if (read_args(argc, argv) == ERR_FAILURE)
		return (ERR_ARGS);
	if (fill_structure(data, argc, argv) == ERR_FAILURE)
		return (ERR_ALLOC);
	return (SUCCESS);
}
