/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:20 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/29 17:56:52 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "libft.h"

static int	length(char *dest)
{
	int	j;

	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	return (j);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	le_dest;
	size_t	le_src;
	size_t	i;

	i = 0;
	le_dest = length((char *)dest);
	le_src = length((char *)src);
	if (size == 0)
		return (le_src);
	if (size < le_dest)
		return (size + le_src);
	if (size > le_dest + 1)
	{
		while ((size-- - le_dest - 1) && src[i] != '\0')
		{
			dest[le_dest + i] = src[i];
			i++;
		}
		dest[le_dest + i] = '\0';
	}
	return (le_dest + le_src);
}
/*int	main()
{
	char *s = "ali";
	char d ;
	d[14] = 'a';
	size_t z = 1;

	char *s2 = "ali";
        char d2[30] = "hasan";
        size_t z2 = 1;
	printf("%li\n", ft_strlcat(d, "lorem ipsum dolor sit amet", 15));
	printf("%li\n", strlcat(d2, s2, z2));
	


}*/
