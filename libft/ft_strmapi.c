/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:05:46 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/08 21:42:24 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*return_str;
	size_t	i;

	return_str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (return_str == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		return_str[i] = f(i, s[i]);
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}
