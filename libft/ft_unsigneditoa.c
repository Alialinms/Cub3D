/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigneditoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:28:38 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/20 16:28:43 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	size(unsigned int n, unsigned int i)
{
	unsigned int	div;

	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		i++;
		n = n % div;
		div = div / 10;
	}
	return (i);
}

static void	big_num(char *str, unsigned int n)
{
	unsigned int	div;
	unsigned int	result;
	unsigned int	i;

	div = 1;
	i = 0;
	while (n / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		result = (n / div) + '0';
		str[i] = result;
		i++;
		n = n % div;
		div = div / 10;
	}
}

char	*ft_unsigneditoa(unsigned int n)
{
	unsigned int	i;
	unsigned int	nb;
	char			*str;

	i = 0;
	nb = n;
	i = size(nb, i);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	big_num(str, n);
	str[i] = '\0';
	return (str);
}
