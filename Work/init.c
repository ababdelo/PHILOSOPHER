/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:57:41 by ababdelo          #+#    #+#             */
/*   Updated: 2023/06/26 13:55:13 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int ac, char **av, t_philo *philo)
{
	philo->nb_philo = ft_atoi(av[1]);
	if (philo->nb_philo < 1 || philo->nb_philo > 200)
		return (get_errors(6));
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (philo->time_to_die < 60 || philo->time_to_eat < 60
		|| philo->time_to_sleep < 60)
		return (get_errors(7));
	if (ac == 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (get_errors(8));
		philo->nb_meals = ft_atoi(av[5]);
	}
	else
		philo->nb_meals = -1;
	return (0);
}

int	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	philo->meals = 0;
	philo->start_time = get_time();
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!philo->forks)
		return (get_errors(5));
	philo->time = get_time();
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&(philo->forks[i]), NULL))
			return (get_errors(4));
		i++;
	}
	pthread_mutex_init(&philo->write, NULL);
	pthread_mutex_init(&philo->incr, NULL);
	return (0);
}
