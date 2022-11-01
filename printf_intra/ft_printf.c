/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:44:34 by phil              #+#    #+#             */
/*   Updated: 2021/10/14 17:18:32 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_main_arg(const char *main_arg, va_list arg)
{
	if (*main_arg == '%')
	{
		write (1, "%%", 1);
		return (1);
	}
	else if (*main_arg == 'c')
		return (ft_print_char(arg));
	else if (*main_arg == 's')
		return (ft_print_string(arg));
	else if (*main_arg == 'p')
		return (ft_print_pointer(arg));
	else if (*main_arg == 'd' || *main_arg == 'i')
		return (ft_print_decimal(arg));
	else if (*main_arg == 'u')
		return (ft_print_unsigned (arg));
	else if (*main_arg == 'X' || *main_arg == 'x')
		return (ft_print_hexadecimal(arg, main_arg));
	else
		return (-1);
}

int	ft_printf(const char *main_arg, ...)
{
	va_list	args;
	int		i[3];

	i[0] = -1;
	i[2] = 0;
	va_start (args, main_arg);
	while (main_arg[++i[0]])
	{
		if (main_arg[i[0]] == '%')
		{
			i[0]++;
			i[1] = ft_check_main_arg (&main_arg[i[0]], args);
			if (i[1] < 0)
				return (i[2]);
			i[2] += i[1];
		}
		else
		{
			write (1, &main_arg[i[0]], 1);
			i[2]++;
		}
	}
	va_end(args);
	return (i[2]);
}
