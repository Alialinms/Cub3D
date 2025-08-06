/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:02:28 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/13 15:04:53 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(va_list args, int *count)
{
	unsigned long	p;

	p = (unsigned long)(va_arg(args, void *));
	if (!p)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	ft_putstr_fd("0x", 1);
	*count += 2;
	itoh(args, p, count);
}
