/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:54:20 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 15:54:47 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_realloc(char **original, size_t size)
{
	char	*copy;

	copy = malloc(size * sizeof(char));
	if (copy == NULL)
	{
		free_p(original);
		return (NULL);
	}
	copy = ft_strcpy(copy, *original);
	free_p(original);
	return (copy);
}

void	free_p(char **p)
{
	free(*p);
	*p = NULL;
}
