/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:59:25 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/13 15:01:48 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoh_upper(va_list args, unsigned long p, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	while (p >= 16)
	{
		itoh_upper(args, p / 16, count);
		break ;
	}
	ft_putchar_fd(base[p % 16], 1);
	(*count)++;
}
