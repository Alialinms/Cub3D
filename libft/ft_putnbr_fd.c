/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:05:49 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/06 14:06:01 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	result;

	div = 1;
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -1 * n;
	}
	while (n / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		result = (n / div) + '0';
		write(fd, &result, 1);
		n = n % div;
		div = div / 10;
	}
}
/*int	main(void)
{
	int nb = -2-2;
	ft_putnbr_fd(nb, 1);
	return (0);
}*/
