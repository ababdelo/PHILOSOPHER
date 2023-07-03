/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:51:13 by ababdelo          #+#    #+#             */
/*   Updated: 2023/07/03 15:42:18 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int times)
{
	time_t	start_time;

	start_time = get_time();
	while (get_time() - start_time < times)
		usleep(100);
}

int	time_to_die(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		pthread_mutex_lock(&philo->incr);
		if (philo->nb_meals != -1 && philo->nb_meals
			* philo->nb_philo == philo->meals)
			return (0);
		while (i < philo->nb_philo)
		{
			if (get_time() - philo->last_time_eat[philo->id]
				>= philo->time_to_die)
			{
				pthread_mutex_lock(&philo->write);
				printf("%ldms philo %d is dead\n", get_time()
					- philo->start_time, philo->id + 1);
				return (1);
			}
			i++;
		}
		pthread_mutex_unlock(&philo->incr);
	}
	return (0);
}
