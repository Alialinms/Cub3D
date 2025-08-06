/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:58:31 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/06 14:28:25 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	size(int n, int i)

{
	int	div;

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

static void	big_num(char *str, int n, int i)
{
	int	div;
	int	result;

	div = 1;
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

static void	print_num(char *str, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		str[i] = '-';
		i++;
		str[i] = '2';
		i++;
		n = 147483648;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -1 * n;
	}
	big_num(str, n, i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		nb;

	i = 0;
	nb = n;
	if (nb == -2147483648)
	{
		i = 2;
		nb = 147483648;
	}
	if (nb < 0)
	{
		i++;
		nb = -1 * nb;
	}
	i = size(nb, i);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	print_num(str, n);
	str[i] = '\0';
	return (str);
}
