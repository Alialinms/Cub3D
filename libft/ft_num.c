/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:52:17 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/13 14:54:34 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num(va_list args)
{
	char	*str;
	int		count;
	int		n;

	count = 0;
	n = va_arg(args, int);
	str = ft_itoa(n);
	count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
