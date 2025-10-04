/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:33:11 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 05:07:31 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
void    init_map(t_map *map)
{
    map->arr_map = NULL;
    map->img_EA = NULL;
    map->img_NO = NULL;
    map->img_SO = NULL;
    map->img_WE = NULL;
    map->int_EA = 0;
    map->int_NO = 0;
    map->int_SO = 0;
    map->int_WE = 0;
    map->ceiling_blue = -1;
    map->ceiling_red = -1;
    map->ceiling_green = -1;
    map->floor_blue = -1;
    map->floor_green = -1;
    map->floor_red = -1;
    map->player = 0;
    map->cols = 0;
    map->rows = 0;
	map->out_border = 0;
	map->number_img = 0;
	map->index_map = 0;
	map->index_line = 0;
	map->x_player = 0;
	map->y_player = 0;
}
void    map_error_2(t_map *map)
{
    if (map->img_SO)
    {
        free (map->img_SO);
        map->img_SO = NULL;
    }
    if (map->img_WE)
    {
        free (map->img_WE);
        map->img_WE = NULL;
    }
    if (map->img_EA)
    {
        free (map->img_EA);
        map->img_EA = NULL;
    }
}
void    map_error(t_map *map, int error)
{
    if (map)
    {
        if (map->arr_map)
        {
            ft_farray(map->arr_map);
        }
        if (map->img_NO)
        {
            free (map->img_NO);
            map->img_NO = NULL;
        }
        map_error_2(map);
        free (map);
    }
    if (error)
    {
        ft_putendl_fd("map error", 2);
        exit(-1);
    }
}
