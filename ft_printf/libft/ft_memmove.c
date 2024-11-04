/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:30:05 by nmattos-          #+#    #+#             */
/*   Updated: 2024/10/10 10:22:37 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*start;
	int		i;

	start = dest;
	i = 0;
	if (dest > src)
	{
		dest = (unsigned char *)dest + n - 1;
		src = (unsigned char *)src + n - 1;
		while (n-- > 0)
			*((unsigned char *)dest--) = *((unsigned char *)src--);
	}
	else
		while (n-- > 0)
			*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (start);
}
