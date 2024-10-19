/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:42:45 by hel-band          #+#    #+#             */
/*   Updated: 2024/10/18 13:56:12 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_color(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
}
void	ft_init_carte(t_map *map)
{
	map->cub= NULL;
	map->row = -1;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->filename = NULL;
	map->starting_derection = '\0';
	init_color(&map->floor_color);
	init_color(&map->ceilling_color);
	map->player.x = 0;
	map->player.y = 0;
}
void	ft_init_game(t_data *data)
{
	ft_init_carte(&data->carte);
	//data->mlx = mlx_init();
}