/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:41:52 by yel-mard          #+#    #+#             */
/*   Updated: 2023/01/04 18:41:52 by yel-mard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	get_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		get_hex(n / 16, format);
		get_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			print_char((n + '0'));
		else
		{
			if (format == 'x')
				print_char((n - 10 + 'a'));
			else if (format == 'X')
				print_char((n - 10 + 'A'));
		}
	}
}

int	print_hex(unsigned int n, const char format)
{
	if (n == 0)
		print_char('0');
	else
		get_hex(n, format);
	return (hex_len(n));
}
