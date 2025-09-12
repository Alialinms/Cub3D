/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rhcrts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:39:43 by amashhad          #+#    #+#             */
/*   Updated: 2025/03/27 22:22:48 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//does the exact opposite of strchr, it returns from the beginning of str
//till the pointer (but not the int itself)
//returns NULL on error or if i doesn't exist in the str
//must be freed from your side
char	*rev_strchr(char *str, int c)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ret = malloc(sizeof(char ) * (c + 1));
	if (!ret)
		return (NULL);
	while (str[i] != '\0')
	{
		if (i >= c)
			break ;
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
