/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 13:08:36 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/04/17 14:50:59 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int		take_forks(t_philo *p)
{
	if (p->lf > p->rf)
	{
		pthread_mutex_lock(&p->data->forks[p->rf]);
		print_timestamp(p, "has taken a fork");
		if (check_death(p))
		{
			pthread_mutex_unlock(&p->data->forks[p->rf]);
			return (STOP);
		}
		pthread_mutex_lock(&p->data->forks[p->lf]);
		print_timestamp(p, "has taken a fork");
		if (check_death(p))
		{
			return_forks(p);
			return (STOP);
		}
	}
	else
	{
		pthread_mutex_lock(&p->data->forks[p->lf]);
		print_timestamp(p, "has taken a fork");
		if (check_death(p))
		{
			pthread_mutex_unlock(&p->data->forks[p->lf]);
			return (STOP);
		}
		pthread_mutex_lock(&p->data->forks[p->rf]);
		print_timestamp(p, "has taken a fork");
		if (check_death(p))
		{
			return_forks(p);
			return (STOP);
		}
	}
	return (CONTINUE);
}

void	return_forks(t_philo *p)
{
	if (p->lf > p->rf)
	{
		pthread_mutex_unlock(&p->data->forks[p->lf]);
		pthread_mutex_unlock(&p->data->forks[p->rf]);
	}
	else
	{
		pthread_mutex_unlock(&p->data->forks[p->rf]);
		pthread_mutex_unlock(&p->data->forks[p->lf]);
	}
}
