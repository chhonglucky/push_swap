/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:04:43 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/14 19:23:24 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	len = 0;
	str = (char *)s;
	while (len < ft_strlen(str))
	{
		if (str[len] == (char)c)
			return (str + len);
		len++;
	}
	if ((char)c == '\0')
		return (str + len);
	else
		return (0);
}
