/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:44:21 by phil              #+#    #+#             */
/*   Updated: 2021/10/13 16:49:23 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list arg)
{
	char	s;

	s = va_arg (arg, int);
	write (1, &s, 1);
	return (1);
}

int	ft_print_string(va_list arg)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg (arg, char *);
	if (s == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write (1, s, i);
	return (i);
}

int	ft_print_pointer(va_list arg)
{
	char			*pointer;
	unsigned long	memory;
	int				i;

	i = 0;
	memory = va_arg (arg, unsigned long);
	if (!memory)
	{
		write (1, "0x0", 3);
		return (3);
	}
	pointer = ft_convert_bases((unsigned long int) memory, 16);
	write (1, "0x", 2);
	while (pointer[i])
		i++;
	write (1, pointer, i);
	if (pointer)
		free (pointer);
	return (i + 2);
}

int	ft_print_decimal(va_list arg)
{
	char			*str_num;
	long long int	number;
	int				i;
	int				trigger;

	i = 0;
	trigger = 0;
	number = va_arg(arg, int);
	if (!number)
	{
		write (1, "0", 1);
		return (1);
	}
	if (number < 0)
	{
		write (1, "-", 1);
		number *= -1;
		trigger++;
	}
	str_num = ft_convert_bases((unsigned long long int) number, 10);
	while (str_num[i])
		i++;
	write (1, str_num, i);
	free (str_num);
	return (trigger + i);
}

int	ft_print_unsigned(va_list arg)
{
	char			*str_num;
	unsigned int	number;
	int				i;

	i = 0;
	number = (long int) va_arg(arg, unsigned int);
	str_num = ft_convert_bases((unsigned long int) number, 10);
	if (!str_num[i])
	{
		if (str_num)
			free (str_num);
		write (1, "0", 1);
		return (1);
	}
	while (str_num[i])
		i++;
	write (1, str_num, i);
	if (str_num)
		free (str_num);
	return (i);
}
