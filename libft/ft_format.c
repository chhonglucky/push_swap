/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:51:43 by hongchanhye       #+#    #+#             */
/*   Updated: 2023/12/27 16:44:30 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char *format)
{
	int	i;
	int	length;
	int	temp;

	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = ft_parsing(args, format[i + 1]);
			if (temp == -1)
				return (-1);
			length += temp;
			i++;
		}
		else
		{
			if (write(1, (format + i), 1) == -1)
				return (-1);
			length += 1;
		}
		i++;
	}
	return (length);
}

int	ft_parsing(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += ft_print_percent();
	return (length);
}
