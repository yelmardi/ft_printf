/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:06:39 by yel-mard          #+#    #+#             */
/*   Updated: 2023/01/04 21:06:39 by yel-mard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(int n)
{
	int		size;
	long	nb;

	nb = n;
	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_size(nb) + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	nbr = nb;
	if (nbr < 0)
		nbr = -nbr;
	str[ft_size(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_size(nb) - i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[ft_size(nb) - i++] = (nbr % 10) + '0';
	return (str);
}

int	print_nbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = print_str(num);
	free(num);
	return (len);
}
