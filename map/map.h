/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:43:35 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 04:09:25 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

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


int		char_valid_player(t_map *map, char c);
int		char_valid(t_map *map, char c);
int		check_char(t_map *map, char *str);
int		skip_space_front(char *str);
int		skip_space_bake(char *str);
int		check_form(t_map *map, char *line);
void    fill_color_of_floor(t_map *map, char **log);
void    fill_color_of_ciling(t_map *map, char **log);
char	*skip_revers(char *line);
int		skip_space(char *line);
void    init_map(t_map *map);
void    map_error(t_map *map, int error);
void	get_cols(t_map *map);
void	search_player(t_map *map);
void	map_read(char *file, t_map *map);
void	continue_save(int fd, t_map *map, char *line, int i);
void	map_save(char *file, t_map *map);
int		is_space(int c);
int		move_space(char *str);
int		ft_atoi(const char *str);
int		is_digit(char	*str);
int		is_number(char **str);
int     check_form_6(t_map *map, char *line, int *error);
int     check_form_2_compl(t_map *map, char *line, int **i, int **error);
int     check_form_3_compl(t_map *map, char *line, int **i, int **error);
#endif