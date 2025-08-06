/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:55:04 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/28 16:55:11 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	i = 0;
	pdst = (char *) dst;
	psrc = (char *) src;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (pdst);
}
/*int main(void)
{
	char s[] = "ali hasan";
	printf("%s \n", s);
	ft_memcpy(s + 2, s, 5);
	printf("%s \n", s);
	memmove(s + 4, s, 3);
	printf("%s \n", s);
	return (0);
}*/
