/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:44:22 by alhamdan          #+#    #+#             */
/*   Updated: 2024/10/18 19:44:27 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strjoined(char *s1, char *s2)
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
	free(s1);
	return (jstr);
}

char	*ft_substred(char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	sub = (char *)malloc((len - start + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (start < len)
	{
		sub[i] = s[start + 1];
		start++;
		i++;
	}
	sub[i] = '\0';
	free(s);
	return (sub);
}

int	ft_strchred(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((i));
		}
		i++;
	}
	return (0);
}
