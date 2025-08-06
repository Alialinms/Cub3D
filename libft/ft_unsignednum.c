/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:28:05 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/20 16:28:13 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignednum(va_list args)
{
	unsigned int	n;
	char			*str;
	int				count;

	count = 0;
	n = va_arg(args, unsigned int);
	str = ft_unsigneditoa(n);
	count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
