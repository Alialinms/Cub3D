/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:42:21 by alhamdan          #+#    #+#             */
/*   Updated: 2024/10/18 19:42:26 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	is_there_line(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{	
			return (1);
		}
		i++;
	}
	return (0);
}

char	*find_new_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc((sizeof(char) * i) + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i] = '\n';
	else
		line[i] = '\0';
	line[i + 1] = '\0';
	return (line);
}

char	*find_line(char **string, char **line, ssize_t *j, int fd)
{
	if (is_there_line(string[fd]) && *j != 0)
	{
		*line = find_new_line(string[fd]);
		string[fd] = ft_substred(string[fd], ft_strchred(string[fd], '\n'),
				ft_strlen(string[fd]));
	}
	if (string[fd][0] == '\0')
	{
		free(string[fd]);
		string[fd] = NULL;
	}
	return (*line);
}

char	*get_string(char **string, char **line, char *buf, ssize_t *j)
{
	if (!(*string))
		*string = ft_calloc(1, sizeof(char));
	if (*j == 0 && (*string)[0])
	{
		*line = find_new_line(*string);
		if (is_there_line(*string))
		{
			*string = ft_substred(*string, ft_strchred(*string, '\n'),
					ft_strlen(*string));
		}
		else
			(*string)[0] = '\0';
		return (*line);
	}
	else if (*j == 0)
		return (NULL);
	*string = ft_strjoined(*string, buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*string[MAXFD];
	char		*buf;
	char		*line;
	ssize_t		j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	j = read(fd, buf, BUFFER_SIZE);
	if (j < 0)
	{
		if (string[fd])
			free(string[fd]);
		return (free(buf), string[fd] = NULL, NULL);
	}
	buf[j] = 0;
	line = get_string(&string[fd], &line, buf, &j);
	free(buf);
	if (!(is_there_line(string[fd])) && j != 0)
		return (line = get_next_line(fd), line);
	line = find_line(string, &line, &j, fd);
	return (line);
}
