/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:22:25 by yel-mard          #+#    #+#             */
/*   Updated: 2023/01/03 14:18:42 by yel-mard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		formats(va_list args, const char format);
int		print_char(char c);
int		print_percent(void);
int		print_str(char *str);
int		ft_ptr_len(unsigned long n);
void	get_ptr(unsigned long n);
int		print_ptr(unsigned long ptr);
int		print_hex(unsigned int n, const char format);
int		hex_len(unsigned int n);
void	get_hex(unsigned int n, const char format);
int		print_unsigned(unsigned int n);
char	*uitoa(unsigned int n);
int		u_len(unsigned int n);
int		print_nbr(int n);
char	*ft_itoa(int nb);

#endif
