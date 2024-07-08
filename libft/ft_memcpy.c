/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:03:17 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/14 19:19:52 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*q;
	size_t			i;

	q = dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		*q++ = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
