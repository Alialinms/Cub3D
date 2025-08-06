/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:54:59 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/13 14:56:18 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chr(va_list args)
{
	int		count;
	char	c;

	count = 1;
	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (count);
}
