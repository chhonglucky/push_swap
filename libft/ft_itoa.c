/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:01:29 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/14 20:02:46 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n);
static size_t	ft_count_digits(int n);

char	*ft_itoa(int n)
{
	char		*return_str;
	char		*decimal;
	size_t		digit;
	long long	nvalue;

	digit = ft_count_digits(n);
	return_str = (char *)malloc(sizeof(char) * digit + 1);
	decimal = "0123456789";
	nvalue = (long long)n;
	if (return_str == 0)
		return (0);
	if (n < 0)
	{
		return_str[0] = '-';
		nvalue *= -1;
	}
	if (n == 0)
		return_str[0] = '0';
	while (nvalue > 0)
	{
		return_str[--digit] = decimal[nvalue % 10];
		nvalue /= 10;
	}
	return_str[ft_count_digits(n)] = '\0';
	return (return_str);
}

static size_t	ft_count_digits(int n)
{
	size_t		digit;
	long long	value;

	digit = 1;
	value = (long long)n;
	if (n < 0)
	{
		digit++;
		value *= -1;
	}
	while (value >= 10)
	{
		digit++;
		value /= 10;
	}
	return (digit);
}
