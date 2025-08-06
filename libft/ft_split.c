/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:15:36 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/30 11:33:00 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	sep(const char *s, char c)
{
	if (*s == c)
		return (1);
	return (0);
}

static int	words_count(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (!sep(s, c) && !word)
		{
			word = 1;
			count++;
		}
		else if (sep(s, c))
			word = 0;
		s++;
	}
	return (count);
}

static void	ft_free(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
}

static int	copy(const char *s, char c, char **array, int count)
{
	int	len;
	int	j;

	len = 0;
	while (!sep(s + len, c) && s[len] != '\0')
	{
		len++;
	}
	array[count] = (char *)malloc((len +1) * sizeof(char));
	if (!array[count])
	{
		ft_free(array, count);
		free(array);
		return (0);
	}
	j = 0;
	while (j < len)
	{
		array[count][j] = s[j];
		j++;
	}
	array[count][j] = '\0';
	return (1);
}

char	**ft_split(char const *s1, char c)
{
	char	**array;
	int		count;
	int		flag;

	count = 0;
	flag = 1;
	array = (char **)ft_calloc((words_count(s1, c) + 1), sizeof(char *));
	if (!array)
		return (NULL);
	while (*s1)
	{
		if (flag == 1 && !sep(s1, c))
		{
			if (!copy(s1, c, array, count++))
				return (NULL);
			flag = 0;
		}
		if (sep(s1++, c))
			flag = 1;
	}
	return (array);
}
/*int main() {
    // Write C code here
    char *s = "hello!";
     char c = ' ';
     char **a = ft_split(s, c);
     int i = 0;
     while (a[i])
     {
        printf("%s\n" ,a[i]);
        i++;
     }

    return 0;
}*/
