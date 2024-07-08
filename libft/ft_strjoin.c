/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:05:05 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/05 17:39:58 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	i = 0;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (s3 == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		*(s3 + i) = *(s1 + i);
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		*(s3 + i) = *(s2 + i - ft_strlen(s1));
		i++;
	}
	*(s3 + i) = '\0';
	return (s3);
}
