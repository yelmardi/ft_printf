/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:05:44 by yel-mard          #+#    #+#             */
/*   Updated: 2023/01/04 21:05:44 by yel-mard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = u_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	print_unsigned(unsigned int n)
{
	unsigned int	u_len;
	char			*num;

	u_len = 0;
	if (n == 0)
		u_len += write(1, "0", 1);
	else
	{
		num = uitoa(n);
		u_len += print_str(num);
		free(num);
	}
	return (u_len);
}
