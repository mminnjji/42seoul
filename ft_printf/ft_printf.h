/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:16:16 by man               #+#    #+#             */
/*   Updated: 2023/04/15 16:23:01 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	check(char c, va_list list, int *count);
void	print_hex(char c, va_list list, int *count);
void	ft_get_hex(char c, unsigned long long nb, int *count);
void	print_int(char c, va_list list, int *count);
void	ft_putnbr(int n, int *count);
void	print_char(char c, va_list list, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr_rev(unsigned int n, int *count);

#endif
