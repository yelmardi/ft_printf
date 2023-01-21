/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:56:57 by yel-mard          #+#    #+#             */
/*   Updated: 2023/01/04 20:56:57 by yel-mard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	get_ptr(unsigned long n)
{
	if (n >= 16)
	{
		get_ptr(n / 16);
		get_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			print_char((n + '0'));
		else
			print_char((n - 10 + 'a'));
	}
}

int	print_ptr(unsigned long ptr)
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr == 0)
		ptr_len += write(1, "(nil)", 5);
	else
	{
		ptr_len += write(1, "0x", 2);
		get_ptr(ptr);
		ptr_len += ft_ptr_len(ptr);
	}
	return (ptr_len);
}
