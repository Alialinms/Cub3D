/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:56:27 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/29 14:19:40 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	jstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!jstr)
		return (NULL);
	while (s1[i])
	{
		jstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		jstr[i] = s2[j];
		i++;
		j++;
	}
	jstr[i] = '\0';
	return (jstr);
}
/*int	main(void)
{
	char *s1 = "\0";
	char *s2 = "hasan";
	printf("%s \n", ft_strjoin(s1, s2));
	return (0);
}*/
