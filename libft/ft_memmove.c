/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:03:23 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/14 19:53:58 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dtmp;
	unsigned char	*stmp;

	if (dst == NULL && src == NULL)
		return (0);
	if (dst <= src)
	{
		dtmp = (unsigned char *)dst;
		stmp = (unsigned char *)src;
		while (len--)
			*dtmp++ = *stmp++;
	}
	else
	{
		dtmp = (unsigned char *)(dst + len);
		stmp = (unsigned char *)(src + len);
		while (len--)
			*--dtmp = *--stmp;
	}
	return (dst);
}
