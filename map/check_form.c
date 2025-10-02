/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:39:38 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/02 21:54:06 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int check_form(t_map *map, char *line)
{
    int		error;
	int		i;
    char    **log;

    log = NULL;
    error = 0;
	i = 0;
	line = skip_revers(line);
	if(!line)
		return (1);
	while (is_space(line[i]))
		i++;
    if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ' && map->int_NO == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_NO = ft_strdup(line + skip_space(line));
        map->int_NO = 1;
        error = 1;
		map->number_img++;
    }
    if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ' && map->int_SO == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_SO = ft_strdup(line + skip_space(line));
        map->int_SO = 1;
        error = 1;
		map->number_img++; 
    }
    if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ' && map->int_WE == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_WE = ft_strdup(line + skip_space(line));
        map->int_WE = 1;
        error = 1;
		map->number_img++; 
    }
    if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ' && map->int_EA == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_EA = ft_strdup(line + skip_space(line));
        map->int_EA = 1;
        error = 1;
		map->number_img++; 
    }
    if (line[i] == 'F' && line[i + 1] == ' ' && map->floor_red == -1 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        log = ft_split(line + skip_space(line), ',');
        if (!log)
            return (1);
        if (is_number(log))
		{
			ft_farray(log);
            return (1);
		}
        fill_color_of_floor(map, log);
        error = 1;
		map->number_img++;
        ft_farray(log);
    }
    if (line[i] == 'C' && line[i + 1] == ' ' && map->ceiling_red == -1 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        log = ft_split(line + skip_space(line), ',');
        if (is_number(log))
		{
			ft_farray(log);
			return (1);
		}
        fill_color_of_ciling(map, log);
        error = 1;
		map->number_img++;
		ft_farray(log);
    }
    if (map->number_img == 6 && line[0] != '\0' && error == 0)
	{
		if (map->index_map == 0)
			map->index_map = map->index_line;
		map->rows++;
		map->out_border = 1;
		if (check_char(map, line))
			error = 1;
		else
			error = 0;
	}
    if ((error == 0 && line[0] != '\0') || (error == 0 && map->out_border == 1))
	{
		// free(line);
        return (1);
	}
    return (0);
}
