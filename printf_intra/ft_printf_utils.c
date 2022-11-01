/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:44:31 by phil              #+#    #+#             */
/*   Updated: 2021/10/13 16:49:24 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_convert(int number)
{
	if (number >= 0 && number <= 9)
		return ((char)number + '0');
	else
		return ((char) number - 10 + 'a');
}

char	*ft_convert_bases(unsigned long int number, int base)
{
	unsigned long int	temp;
	int					i;
	char				*rtn;

	temp = number;
	i = 1;
	while (number > base - 1)
	{
		i++;
		number /= base;
	}
	rtn = ft_calloc((i + 1), 1);
	while (temp > 0)
	{
		rtn[--i] = ft_convert(temp % base);
		temp /= base;
	}
	return (rtn);
}

char	*ft_calloc(int x, int y)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = (char *)malloc (x * y);
	while (x * y > i)
		rtn [i++] = 0;
	return (rtn);
}

static void	ft_upper(char *rtn)
{
	int	i;

	i = -1;
	while (rtn[++i])
	{
		if (rtn[i] >= 'a' && rtn[i] <= 'z')
			rtn[i] -= 32;
	}
}

int	ft_print_hexadecimal(va_list arg, const char *size)
{
	char			*pointer;
	unsigned long	memory;
	int				i;

	i = 0;
	memory = va_arg (arg, unsigned int);
	if (!memory)
	{
		write (1, "0", 1);
		return (1);
	}
	pointer = ft_convert_bases((unsigned long int) memory, 16);
	while (pointer[i])
		i++;
	if (size[0] == 'X')
		ft_upper (pointer);
	write (1, pointer, i);
	if (pointer)
		free (pointer);
	return (i);
}
