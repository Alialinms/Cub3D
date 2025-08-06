/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:13:11 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/27 18:32:59 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
/*int	main()
{
	char	s[5]="ali";
	char	buff = 'm';
	size_t	i = 3;
	ft_memset(s, buff, i);
	printf("%s \n", s);
	char	s1[5]="ali";
	char	buff1 = 'l';
	ft_memset(s1, buff1, i);
	printf("%s \n", s1);
	return (0);
}*/
