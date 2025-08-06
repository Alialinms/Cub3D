/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:06:32 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/28 19:06:35 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*pdst;

	i = 0;
	pdst = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if (src > dst)
	{
		while (i < len)
		{
			pdst[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			pdst[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (pdst);
}
/*int main(void)
{
	char s[] = "ali hasan";
	char s1[] = "abcde";
	char s2[] = "abcde";
	printf("%s \n", s);
	//char *d1 = ft_memcpy(s + 4, s, 5);
	//printf("%s \n", d1);
	//char *d = memcpy(s + 4, s, 5);
	//printf("%s \n", d);
	char *d2 = memmove(s1 + 2, s1, 4);
	printf("%s \n", d2);
	char *d3 = ft_memmove(s2 + 2, s2, 4);
	printf("%s \n", d3);
	return (0);
}*/
