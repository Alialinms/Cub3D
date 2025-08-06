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
    int			ciling_red;
    int         ciling_blue;
    int         ciling_green;
	int			players;
}				t_map;

void	ft_farray(char	**arr)
{
	int		i;

	i = 0;
	if (!arr)
		return ;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return ;
}

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
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
    map->ciling_blue = -1;
    map->ciling_red = -1;
    map->ciling_green = -1;
    map->floor_blue = -1;
    map->floor_green = -1;
    map->floor_red = -1;
    map->players = 0;
    map->cols = 0;
    map->rows = 0;
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
    map->ciling_red = ft_atoi(log[0]);
    map->ciling_green = ft_atoi(log[1]);
    map->ciling_blue = ft_atoi(log[2]);
}

int check_form(t_map *map, char *line)
{
    int error;
    char    **log;

    log = NULL;
    error = 0;
    if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && map->int_NO == 0)
    {
        map->img_NO = ft_strdup(line + 3);
        map->int_NO = 1;
        error = 1; 
    }
    if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && map->int_SO == 0)
    {
        map->img_SO = ft_strdup(line + 3);
        map->int_SO = 1;
        error = 1; 
    }
    if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && map->int_WE == 0)
    {
        map->img_WE = ft_strdup(line + 3);
        map->int_WE = 1;
        error = 1; 
    }
    if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && map->int_EA == 0)
    {
        map->img_EA = ft_strdup(line + 3);
        map->int_EA = 1;
        error = 1; 
    }
    if (line[0] == 'F' && line[1] == ' ' && map->floor_red == -1)
    {
        log = ft_split(line + 2, ',');
        if (!log)
            return (1);
        if (is_number(log))
            return (1);
        fill_color_of_floor(map, log);
        error = 1;
        ft_farray(log);
    }
    if (line[0] == 'C' && line[1] == ' ' && map->ciling_red == -1)
    {
        log = ft_split(line + 2, ',');
        if (is_number(log))
            return (1);
        fill_color_of_ciling(map, log);
        error = 1; 
    }
    if (line[0] == '1' && line[ft_strlen(line) - 1] == '1')
        error = 1;
    if (error == 0 && line[0] != '\0')
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
		map->rows++;
		free(line);
		i++;
	}
	close(fd);
}

// void	map_save(char *file, t_map *map)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		map_error(map, 1);
// 	map->arr_map = (char **)malloc(game->map.rows * sizeof(char *));
// 	if (!game->map.map)
// 		map_error(game->map, 1);
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		if (line[ft_strlen(line) - 1] == '\n')
// 			line[ft_strlen(line) - 1] = '\0';
// 		game->map.map[i] = ft_strdup(line);
// 		free(line);
// 		if (!game->map.map[i])
// 			map_error(game->map, 9);
// 		i++;
// 	}
// 	close(fd);
// }

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
    ft_printf("succuse\n");
	// map_save(argv[1], map);
	// map_check(map);
	return (0);
}