/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:11:07 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 16:11:38 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

void	take_forks(t_philo *p)
{
	sem_wait(p->data->forks);
	sem_wait(p->data->forks);
}

void	return_forks(t_philo *p)
{
	sem_post(p->data->forks);
	sem_post(p->data->forks);
}
