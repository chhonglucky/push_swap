/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:11:08 by hongchanhye       #+#    #+#             */
/*   Updated: 2023/12/27 16:44:25 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	va_start(args, format);
	length = ft_format(args, format);
	va_end(args);
	return (length);
}

int	ft_print_char(int i)
{
	if (write(1, &i, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = ft_strlen(str);
	if (write(1, str, ft_strlen(str)) == -1)
		return (-1);
	return (len);
}

int	ft_print_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_nbr(int nbr)
{
	char	*n;
	int		len;

	n = ft_itoa(nbr);
	if (n == NULL)
		return (-1);
	len = ft_print_str(n);
	free(n);
	return (len);
}
