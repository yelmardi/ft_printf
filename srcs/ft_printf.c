/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:20:21 by yel-mard          #+#    #+#             */
/*   Updated: 2023/01/03 14:18:14 by yel-mard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formats(va_list args, const char format)
{
	int	format_return;

	format_return = 0;
	if (format == 'c')
		format_return += print_char(va_arg(args, int));
	else if (format == 's')
		format_return += print_str(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		format_return += print_nbr(va_arg(args, int));
	else if (format == 'p')
		format_return += print_ptr(va_arg(args, unsigned long));
	else if (format == 'u')
		format_return += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		format_return += print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		format_return += print_percent();
	return (format_return);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_length;
	int		i;

	print_length = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
