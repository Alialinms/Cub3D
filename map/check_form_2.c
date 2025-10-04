/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:15:46 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 04:09:02 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int  check_form_2_compl(t_map *map, char *line, int **i, int **error)
{
	if (line[**i] == 'W' && line[**i + 1] == 'E' && line[**i + 2] == ' ' && map->int_WE == 0 && map->out_border == 0)
    {
		**i = **i + 3;
		while (is_space(line[**i]))
			(*i)++;
        if (line[**i] == '\0')
            return (1);
        map->img_WE = ft_strdup(line + **i);
        map->int_WE = 1;
        **error = 1;
		map->number_img++; 
    }
	return (0);
}

int  check_form_3_compl(t_map *map, char *line, int **i, int **error)
{
	if (line[**i] == 'E' && line[**i + 1] == 'A' && line[**i + 2] == ' ' && map->int_EA == 0 && map->out_border == 0)
    {
		**i = **i + 3;
		while (is_space(line[**i]))
			(*i)++;
        if (line[**i] == '\0')
            return (1);
        map->img_EA = ft_strdup(line + **i);
        map->int_EA = 1;
        **error = 1;
		map->number_img++; 
    }
	return (0);
}

int  check_form_6(t_map *map, char *line, int *error)
{
    if (map->number_img == 6 && line[0] != '\0' && *error == 0)
	{
		if (map->index_map == 0)
			map->index_map = map->index_line;
		map->rows++;
		map->out_border = 1;
		if (check_char(map, line))
			*error = 1;
		else
			*error = 0;
	}
    if ((*error == 0 && line[0] != '\0') || (*error == 0 && map->out_border == 1))
	{
		// free(line);
        return (1);
	}
    return (0);
}