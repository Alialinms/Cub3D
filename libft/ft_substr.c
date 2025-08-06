/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:33:12 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/06 14:27:00 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char	*fill(char *s, int i, unsigned int start, int k)
{
	char	*sub;

	sub = (char *)malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && k > 0)
	{
		sub[i] = s[start];
		start++;
		i++;
		k--;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = start;
	k = len;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
		k = len;
	}
	while (s[j] != '\0' && len > 0)
	{
		i++;
		len--;
		j++;
	}
	return (fill((char *)s, i, start, k));
}
/*int main(void)
{
	char s[] = "ali hasan";
	printf("%s \n", ft_substr(s, 7, 4));
	return (0);
}*/
