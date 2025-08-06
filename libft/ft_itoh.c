/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:57:15 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/13 14:58:54 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoh(va_list args, unsigned long p, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	while (p >= 16)
	{
		itoh(args, p / 16, count);
		break ;
	}
	ft_putchar_fd(base[p % 16], 1);
	(*count)++;
}
