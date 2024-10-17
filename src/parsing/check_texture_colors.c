/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:13:29 by hel-band          #+#    #+#             */
/*   Updated: 2024/10/16 18:23:08 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static  void    ft_pars_texture(t_data *data, int *ptr)
{
    int flag;

    flag = 0;
    while (data->map[*ptr] && *ptr < 4)
    {
        if (ft_strncmp(data->map[*ptr], "NO ", 3) == 0
            || ft_strncmp(data->map[*ptr], "SO ", 3) == 0
            || ft_strncmp(data->map[*ptr], "WE ", 3) == 0
            || ft_strncmp(data->map[*ptr], "EA ", 3) == 0)
            flag++;
        (*ptr)++;
    }
    if (flag != 4 && *ptr != flag)
         print_error("", "Error in textures", 1);
    if (*ptr == 0)
        print_error("", "Empty map", 1);
}

static  void ft_pars_colors(t_data *data, int *ptr)
{
    int flag;
    int i;
    int start;
    
    i = *ptr + 2;
    start = *ptr;

    flag = 0;
    while (data->map[*ptr] && *ptr < i)
    {
        if (ft_strncmp(data->map[*ptr], "F ", 2) == 0
            || ft_strncmp(data->map[*ptr], "C ", 2) == 0)
            flag++;
        (*ptr)++;
    }
    if (flag != 2 && *ptr - start != flag)
        print_error("", "Error in colors", 1);
}

void    ft_find_content(t_data *data)
{
    int i;
    
    i = 0;
    ft_pars_texture(data, &i);
    while (data->map[i] && ft_strncmp(data->map[i], "\n", 1) == 0)
        i++;
    ft_pars_colors(data, &i);
    while (data->map[i] && ft_strncmp(data->map[i], "\n", 1) == 0)
        i++;
    if (data->map[i] == NULL)
        print_error("", "No map include", 1);
}