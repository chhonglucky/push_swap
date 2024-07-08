/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:34:08 by chanhhon          #+#    #+#             */
/*   Updated: 2023/12/27 16:44:13 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, char *base, int *flag)
{
	int	basesize;

	basesize = ft_strlen(base);
	if (nbr >= (unsigned long long)basesize)
	{
		ft_putnbr_base(nbr / basesize, base, flag);
		nbr = nbr % basesize;
	}
	if (nbr < (unsigned long long)basesize)
	{
		if (*flag)
		{
			if (write(1, &base[nbr], 1) == -1)
				*flag = 0;
		}
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;
	int	flag;

	len = 1;
	flag = 1;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	ft_putnbr_base(ptr, "0123456789abcdef", &flag);
	if (flag == 0)
		return (-1);
	while (ptr / 16 > 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int u)
{
	int	len;
	int	flag;

	len = 1;
	flag = 1;
	ft_putnbr_base((unsigned long long)u, "0123456789", &flag);
	if (flag == 0)
		return (-1);
	while (u / 10 > 0)
	{
		u /= 10;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int u, const char format)
{
	int	len;
	int	flag;

	len = 1;
	flag = 1;
	if (format == 'x')
		ft_putnbr_base(u, "0123456789abcdef", &flag);
	else if (format == 'X')
		ft_putnbr_base(u, "0123456789ABCDEF", &flag);
	if (flag == 0)
		return (-1);
	while (u / 16 > 0)
	{
		u /= 16;
		len++;
	}
	return (len);
}
