/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:58:10 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/02 21:58:21 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	check_path(t_map *map, int i, int j)
{
	if (map->arr_map[i][j] == '1' || map->arr_map[i][j] == 'F')
		return ;
	if (map->arr_map[i][j] == ' ' || (i == map->rows - 1 && map->arr_map[i][j] == '0') || (j == skip_space_bake(map->arr_map[i]) && map->arr_map[i][j] == '0') || (i == 0  && map->arr_map[i][j] == '0')
		|| (j == skip_space_front(map->arr_map[i]) && map->arr_map[i][j] == '0') || map->arr_map[i][j] == '\0')
		map_error(map);
	map->arr_map[i][j] = 'F';
	check_path(map, i - 1, j);
	check_path(map, i, j + 1);
	check_path(map, i + 1, j);
	check_path(map, i, j - 1);
	check_path(map, i - 1, j - 1);
	check_path(map, i + 1, j - 1);
	check_path(map, i + 1, j + 1);
	check_path(map, i - 1, j + 1);
}

void	map_check(t_map *map)
{
	int	i;

	i = 0;
	if (map->player > 1 || map->player == 0)
		map_error(map);
	search_player(map);
	get_cols(map);
	while (map->arr_map[i])
	{
		if (map->y_player == map->rows - 1 || (map->x_player == skip_space_bake(map->arr_map[i]) && i == map->y_player) || map->y_player == 0
			|| (map->x_player == skip_space_front(map->arr_map[i]) && i == map->y_player))
			map_error(map);
		i++;
	}
	
	check_path(map, map->y_player, map->x_player);
}

// static void	check_args(int argc, char **argv)
// {
// 	char	*tmp;
// 	int		fd;

// 	if (argc != 2)
// 	{
// 		ft_printf("Wrong Number of Arguments :(\n");
// 		exit(-1);
// 	}
// 	tmp = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
// 	if (!tmp)
// 		return;
// 	if (ft_strncmp(".cub", tmp, 4))
// 	{
// 		free(tmp);
// 		//malloc_error(2);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		ft_printf("Map File not found :(\n");
// 		free(tmp);
// 		exit(-1);
// 	}
// 	close(fd);
// 	free(tmp);
// }

int	main(void)
{
	t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
    {
        ft_putendl_fd("Error in malloc", 2);
		exit(1);
    }
	// check_args(argc, argv);
	init_map(map);
	map_read("test.cub", map);
    ft_printf("success\n");
	map_save("test.cub", map);
	map_check(map);
	ft_printarr(map->arr_map);
	// ft_printf("%i\n", map->rows);
	//map_error(map);
	return (0);
}