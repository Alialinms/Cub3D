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
	size_t		cols;
	int			floor_red;
    int         floor_blue;
    int         floor_green;
    int			ceiling_red;
    int         ceiling_blue;
    int         ceiling_green;
	int			player;
	int			out_border;
	int			number_img;
	int			index_map;
	int			index_line;
	int			x_player;
	int			y_player;
}				t_map;


int	is_space(int c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	move_space(char *str)
{
	if (!str)
		return (-1);
	int	i;

	i = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	return (i);
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
//dddddddddddddddddddddddddddddddddddddd
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
//ffffffffffffffffffffffffffffffffffffff
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

char	*skip_revers(char *line)
{
	size_t	i;

	i = 0;
	if (line[i] == '\0' || line[i] == '\n')
		return (line);
	i = ft_strlen(line) - 1;
	if (!is_space(line[i]))
		return (line);
	while (is_space(line[i]))
	{
		if (i == 0)
			break;
		i--;
	}
	line = rev_strchr(line, i + 1);
	return (line);
}

int	skip_space(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (!is_space(line[i]))
		i++;
	while (line[i] != '\0')
	{
		while (is_space(line[i]))
			i++;
		if (line[i] != '\0')
			return (i);
	}
	return (-1);
}
//ffffffffffffffffffffffffffffffffffffffff
int	char_valid_player(t_map *map, char c)
{
	if (c == 'N')
	{
		map->player++;
		return (1);
	}
	if (c == 'S')
	{
		map->player++;
		return (1);
	}
	if (c == 'W')
	{
		map->player++;
		return (1);
	}
	if (c == 'E')
	{
		map->player++;
		return (1);
	}
	return (0);
}

int	char_valid(t_map *map, char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == ' ')
		return (1);
	if (char_valid_player(map, c))
		return (1);
	return (0);
}

int	check_char(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!char_valid(map, str[i]))
			return (0);
		i++;
	}
	return (1);
}

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
//dddddddddddddddddddddddddddddddddddddddd
void	map_read(char *file, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error(map);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        if (check_form(map, line))
		{
			free(line);
            map_error(map);
		}
		free(line);
		map->index_line++;
	}
	close(fd);
}

void	continue_save(int fd, t_map *map, char *line, int i)
{
	while (i < map->index_map)
	{
		line = get_next_line(fd);
		free (line);
		i++;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->arr_map[i] = ft_strdup(line);
		free(line);
		if (!map->arr_map[i])
			map_error(map);
		i++;
	}
	map->arr_map[i] = NULL;
}

void	map_save(char *file, t_map *map)
{
	char	*line;
	int		i;
	int		fd;

	line = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error(map);
	map->arr_map = (char **)malloc((map->rows + 1) * sizeof(char *));
	if (!map->arr_map)
		map_error(map);
	continue_save(fd, map, line, i);
	close(fd);
}


void	search(char *str, t_map *map)
{
	int	i;

	i = move_space(str);
	if (i == -1)
		map_error(map);
	while (str[i] != '\0')
	{
		if (direction(str[i]))
			map->player++;
		if (is_space(str[i]))
			str[i] = '0';
		if (!input_map(str[i]))
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
//ddddddddddddddddddddddddddddddddddddd
int	skip_space_front(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	return (i);
}

int	skip_space_bake(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (is_space(str[i]))
	{
		i--;
	}
	return (i);
}
//ddddddddddddddddddddddddddddddddddddddd
void	get_cols(t_map *map)
{
	int	i;
	size_t	great;
	size_t	lower;

	i = 0;
	great = ft_strlen(map->arr_map[i]);
	i++;
	while (map->arr_map[i])
	{
		lower = ft_strlen(map->arr_map[i]);
		if (lower > great)
			great = lower;
		i++;
	}
	map->cols = great;
	return ;
}

void	search_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr_map[i])
	{
		j = 0;
		while (map->arr_map[i][j] != '\0')
		{
			if (char_valid_player(map, map->arr_map[i][j]))
			{
				map->x_player = j;
				map->y_player = i;
				return ;
			}
			j++;
		}
		i++;
	}
	
}

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