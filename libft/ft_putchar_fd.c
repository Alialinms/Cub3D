/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:02 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/06 14:02:22 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main(void)
{
	int fd;
	
	fd = open("test.txt", O_WRONLY);
	if (fd == -1)
		return 1;
		
   	char c = '0' + fd;
   	ft_putchar_fd(c, fd);
   	return (0);
}*/
