/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:05:51 by chanhhon          #+#    #+#             */
/*   Updated: 2023/10/24 22:05:20 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*p1;
	unsigned const char	*p2;

	i = 0;
	p1 = (unsigned const char *)s1;
	p2 = (unsigned const char *)s2;
	while (*(p1 + i) && *(p1 + i) == *(p2 + i) && i < n)
		i++;
	if (i >= n)
		return (0);
	return (*(p1 + i) - *(p2 + i));
}
