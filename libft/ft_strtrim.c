/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:18:19 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/29 16:37:00 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	find_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		while (set[i] == s1[j])
		{
			j++;
			i = 0;
		}
		i++;
	}
	return (j);
}

static int	find_end(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	if (!len)
		return (0);
	while (set[i])
	{
		while (set[i] == s1[len - 1])
		{
			len--;
			i = 0;
		}
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		j;
	int		len;
	int		k;
	int		size;

	j = find_start(s1, set);
	len = find_end(s1, set);
	k = 0;
	size = len - j;
	if (size < 0)
		size = 0;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (j < len)
	{
		str[k] = s1[j];
		k++;
		j++;
	}
	str[k] = '\0';
	return (str);
}
/*int	main(void)
{
	char s[] = "cbatestabc";
	char set[] = "abc";
	printf("%s \n", ft_strtrim(s, set));
	return (0);
}*/
