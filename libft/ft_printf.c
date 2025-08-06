/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:33:20 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/13 16:33:39 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char chr, va_list args)
{
	int	count;

	count = 0;
	if (chr == 's')
		count += str(args);
	else if (chr == 'i' || chr == 'd')
		count += num(args);
	else if (chr == 'c')
		count += ft_chr(args);
	else if (chr == 'u')
		count += ft_unsignednum(args);
	else if (chr == 'p')
		ft_ptr(args, &count);
	else if (chr == 'x')
		itoh(args, (unsigned long)va_arg(args, unsigned int), &count);
	else if (chr == 'X')
		itoh_upper(args, (unsigned long)va_arg(args, unsigned int), &count);
	else if (chr == '%')
	{
		count++;
		ft_putchar_fd('%', 1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_format(*str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
