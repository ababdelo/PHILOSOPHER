/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:58:01 by ababdelo          #+#    #+#             */
/*   Updated: 2023/07/03 15:47:10 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_activities(t_philo *philo, pthread_mutex_t *right,
			pthread_mutex_t *left, int id)
{
	pthread_mutex_lock(right);
	pthread_mutex_lock(&philo->write);
	printf("%ldms philo %d has taken a fork\n", get_time() - philo->start_time,
		id + 1);
	pthread_mutex_unlock(&philo->write);
	pthread_mutex_lock(left);
	pthread_mutex_lock(&philo->write);
	printf("%ldms philo %d has taken a fork\n", get_time() - philo->start_time,
		id + 1);
	pthread_mutex_unlock(&philo->write);
	pthread_mutex_lock(&philo->write);
	printf("%ldms philo %d is eating\n", get_time() - philo->start_time, id
		+ 1);
	pthread_mutex_unlock(&philo->write);
	pthread_mutex_lock(&philo->incr);
	philo->last_time_eat[id] = get_time();
	pthread_mutex_unlock(&philo->incr);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(&philo->incr);
	philo->meals++;
	pthread_mutex_unlock(&philo->incr);
	pthread_mutex_unlock(right);
	pthread_mutex_unlock(left);
}

void	*philo_life(void *arg)
{
	t_philo			*philo;
	int				id;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	philo = (t_philo *)arg;
	right = philo->forks + (philo->id % philo->nb_philo);
	left = philo->forks + ((philo->id + 1) % philo->nb_philo);
	pthread_mutex_lock(&philo->incr);
	id = philo->id;
	pthread_mutex_unlock(&philo->incr);
	while (1)
	{
		philo_activities(philo, right, left, id);
		pthread_mutex_lock(&philo->write);
		printf("%ldms philo %d is sleeping\n", get_time() - philo->start_time,
			id + 1);
		pthread_mutex_unlock(&philo->write);
		ft_usleep(philo->time_to_sleep);
		pthread_mutex_lock(&philo->write);
		printf("%ldms philo %d is thinking\n", get_time() - philo->start_time,
			id + 1);
		pthread_mutex_unlock(&philo->write);
	}
}

int	create_th(t_philo *philo)
{
	int	i;

	i = 0;
	philo->last_time_eat = malloc(sizeof(int *) * philo->nb_philo);
	philo->thread = malloc(sizeof(pthread_t) * philo->nb_philo);
	if (!philo->thread)
		return (get_errors(5));
	while (i < philo->nb_philo)
	{
		pthread_mutex_lock(&philo->incr);
		philo->id = i;
		philo->last_time_eat[i] = get_time();
		pthread_mutex_unlock(&philo->incr);
		if (pthread_create(&philo->thread[i], NULL, &philo_life, philo))
			return (get_errors(3));
		usleep(100);
		i++;
	}
	return (time_to_die(philo));
}

int	ft_atoi(const char *str)
{
	int		index;
	int		sign;
	long	res;

	index = 0;
	res = 0;
	sign = 1;
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if (res > INT_MAX)
			return (-1);
		res = (res * 10) + (str[index] - '0');
		index++;
	}
	return ((int)res * sign);
}

int	get_errors(int err)
{
	if (err)
		printf("\033[1;31m[Error]:\033[0;m ");
	if (err == 1)
		printf("Wrong number of arguments !\n");
	else if (err == 2)
		printf("Invalide value !\n");
	else if (err == 3)
		printf("Threads Creation failed !\n");
	else if (err == 4)
		printf("Mutex Initialization failed !\n");
	else if (err == 5)
		printf("Allocation failed !\n");
	else if (err == 6)
		printf("Number of Philosopher is Invalide\n");
	else if (err == 7)
		printf("Time Parameters is Invalide\n");
	else if (err == 8)
		printf("Number of Meals is Invalide\n");
	return (1);
}
