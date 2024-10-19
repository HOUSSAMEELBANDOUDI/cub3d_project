/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:15:36 by hel-band          #+#    #+#             */
/*   Updated: 2024/10/18 20:51:12 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <math.h>
# include <unistd.h>

# define EQUAL 0
//****COLORS
# define RESET	"\e[0m"
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

# define FLOOR "F"
# define CEILLING "C"

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

typedef struct s_gdata
{
    void			*data;
    struct s_gdata	*next;
}	t_gdata;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	int			row;
	int			col;
	int			nbr_line;
	char		**file;
	int			height;
	int			width;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	t_color		floor_color;
	t_color		ceilling_color;
	char		starting_derection;
	int			index_end_of_map;
	char		**cub;
	char		*filename;
	t_vector	player;
}	t_map;


typedef struct s_data
{
	void		*mlx;
	void		*win_ptr;
    int         ac;
    char        **av;
	int			win_height;
	int			win_width;
	t_map	    carte;
	char		**map;
}	t_data;

// *** parsing ***:
int main(int ac, char **av);
int		print_error(char *arg, char *str, int fd);
int		ft_pars_file(char *arg);
void	ft_pars_map(t_data *data);
void	ft_find_content(t_data *data);
void	ft_spl_free(char **spl);
void    ft_add_textures(t_data *data);
void    ft_add_colors(t_data *data);
int		ft_len_map(t_data  *data);
int		ft_find_newline(char *str);
int		ft_find_char(char x, char *str);
void    ft_find_player_pos(t_map *map);
int ft_pars_wall(char **cub, int row);
int ft_surrond_wall(char **cub, int row, int col);
int	ft_check_wall(char **cub, int row, int col);
void    ft_last_pars_cub(t_map map);
void	ft_check_cub(t_map map, int row, int col);
void	ft_take_cub(t_data *data);
void    ft_pars_cub(char **cub ,t_data *data);
void	ft_init_game(t_data *data);
void	ft_init_carte(t_map *map);
void	init_color(t_color *color);
int	ft_find_cub_(char *src, char *to_find);

#endif