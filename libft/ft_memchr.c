/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:51:36 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/27 17:10:00 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)(s1);
	while (i < n)
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char *s = "ali";
	char c = '\0';
	char *d = ft_memchr(s, c, 4);
	printf("%s \n", d);
	char *d1 = ft_memchr(s, c, 4);
	 printf("%s \n", d1);
	 return (0);
}*/
