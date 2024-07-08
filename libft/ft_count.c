/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:17:40 by hongchanhye       #+#    #+#             */
/*   Updated: 2024/05/24 00:29:13 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char *str, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
