/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:51:27 by yel-mard          #+#    #+#             */
/*   Updated: 2023/01/04 13:51:27 by yel-mard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_percent(void)
{
	write (1, "%", 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i = 6;
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}
