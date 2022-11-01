/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:44:37 by phil              #+#    #+#             */
/*   Updated: 2021/10/13 16:49:26 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *main_arg, ...);
int		ft_check_main_arg(const char *main_arg, va_list arg);
int		ft_print_pointer(va_list arg);
int		ft_print_string(va_list arg);
int		ft_print_char(va_list arg);
char	*ft_convert_bases(unsigned long int number, int base);
char	*ft_calloc(int x, int y);
int		ft_print_decimal(va_list arg);
int		ft_print_unsigned(va_list arg);
int		ft_print_hexadecimal(va_list arg, const char *size);

#endif
