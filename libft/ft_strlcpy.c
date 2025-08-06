/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:05:11 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/28 16:11:08 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <bsd/string.h>
//#include <stdio.h>
#include "libft.h"

static int	length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	le_src;

	i = 0;
	le_src = length((char *)src);
	if (!dst || !src)
		return (0);
	if (!size)
		return (le_src);
	while (src[i] != '\0' && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size <= le_src)
		dst[size - 1] = '\0';
	else if (size != 0)
		dst[i] = '\0';
	return (le_src);
}
/*
int     main()
{
        char *s = "ddd";
        char d[] = "sssss";
        size_t z = 0;
        printf("%li\n", ft_strlcpy(d, s, z));
        printf("%li\n", strlcpy(d, s, z));
        //printf("%li\n", strlcpy(d, s, 0));
	return (0);
}*/
