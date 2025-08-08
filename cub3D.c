# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_map
{
	char		**arr_map;
    char        *img_NO;
    char        *img_SO;
    char        *img_WE;
    char        *img_EA;
    int         int_NO;
    int         int_SO;
    int         int_WE;
    int         int_EA;
	int			rows;
	int			cols;
	int			floor_red;
    int         floor_blue;
    int         floor_green;
    int			ceiling_red;
    int         ceiling_blue;
    int         ceiling_green;
	int			player;
	int			out_border;
}				t_map;



int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

int	is_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_number(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_digit(str[i]))
			return (1);
		if (ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
			return (1);
		i++;
	}
    if (i != 3)
    {

        return (1);
    }
	return (0);
}

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
}

void    map_error(t_map *map)
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
        free (map);
    }
    ft_putendl_fd("map error", 2);
    exit(1);
}

void    fill_color_of_floor(t_map *map, char **log)
{
    map->floor_red = ft_atoi(log[0]);
    map->floor_green = ft_atoi(log[1]);
    map->floor_blue = ft_atoi(log[2]);
}

void    fill_color_of_ciling(t_map *map, char **log)
{
    map->ceiling_red = ft_atoi(log[0]);
    map->ceiling_green = ft_atoi(log[1]);
    map->ceiling_blue = ft_atoi(log[2]);
}

int	skip_space(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (!ft_isspace(line[i]))
		i++;
	while (line[i] != '\0')
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] != '\0')
			return (i);
	}
	return (-1);
}

int check_form(t_map *map, char *line)
{
    int error;
    char    **log;

    log = NULL;
    error = 0;
    if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && map->int_NO == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_NO = ft_strdup(line + skip_space(line));
        map->int_NO = 1;
        error = 1; 
    }
    if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && map->int_SO == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_SO = ft_strdup(line + skip_space(line));
        map->int_SO = 1;
        error = 1; 
    }
    if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && map->int_WE == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_WE = ft_strdup(line + skip_space(line));
        map->int_WE = 1;
        error = 1; 
    }
    if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && map->int_EA == 0 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        map->img_EA = ft_strdup(line + skip_space(line));
        map->int_EA = 1;
        error = 1; 
    }
    if (line[0] == 'F' && line[1] == ' ' && map->floor_red == -1 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        log = ft_split(line + skip_space(line), ',');
        if (!log)
            return (1);
        if (is_number(log))
            return (1);
        fill_color_of_floor(map, log);
        error = 1;
        ft_farray(log);
    }
    if (line[0] == 'C' && line[1] == ' ' && map->ceiling_red == -1 && map->out_border == 0)
    {
		if (skip_space(line) == -1)
			return (1);
        log = ft_split(line + skip_space(line), ',');
        if (is_number(log))
			return (1);
        fill_color_of_ciling(map, log);
        error = 1; 
		ft_farray(log);
    }
    if (line[0] == '1' && line[ft_strlen(line) - 1] == '1')
	{
		map->rows++;
		map->out_border = 1;
        error = 1;
	}
    if ((error == 0 && line[0] != '\0') || (error == 0 && map->out_border == 1))
        return (1);
    return (0);
}

void	map_read(char *file, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error(map);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        if (check_form(map, line))
            map_error(map);
		free(line);
		i++;
	}
	close(fd);
}

void	continue_save(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (line[0] == '1')
		{
			map->arr_map[i] = ft_strdup(line);
			free(line);
			if (!map->arr_map[i])
				map_error(map);
			i++;
		}
		else
			free(line);
	}
	map->arr_map[i] = NULL;
}

void	map_save(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error(map);
	map->arr_map = (char **)malloc((map->rows + 1) * sizeof(char *));
	if (!map->arr_map)
		map_error(map);
	continue_save(fd, map);
	close(fd);
}

int	if_not_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	search(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'N')
			map->player++;
		if (ft_isspace(str[i]))
			str[i] = '0';
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N')
			map_error(map);
		i++;
	}
}

int	many_players(t_map *map)
{
	int	i;

	i = 1;
	while (i < map->rows - 1)
	{
		search(map->arr_map[i], map);
		i++;
	}
	if (map->player == 1)
		return (0);
	else
		return (1);
}

int	road_without_a_wall(char **arr, t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->rows - 1)
	{
		j= 0;
		while (arr[i][j] != '\0')
		{
			while (arr[i][j] != '1')
			{
				if (arr[i - 1][j] == '\0' || arr[i + 1][j] == '\0')
					return (1);
				j++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	map_check(t_map *map)
{
	if (if_not_one(map->arr_map[0]) || if_not_one(map->arr_map[map->rows - 1]) || many_players(map) || road_without_a_wall(map->arr_map, map))
		map_error(map);
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
	// ft_printf("%s\n", map->arr_map[0]);
	// ft_printf("%s\n", map->arr_map[map->rows - 1]);
	map_check(map);
	ft_printarr(map->arr_map);
	//map_error(map);
	return (0);
}