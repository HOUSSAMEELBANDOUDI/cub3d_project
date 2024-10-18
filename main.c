/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:26:05 by hel-band          #+#    #+#             */
/*   Updated: 2024/10/18 11:45:10 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void ft_parsing(t_data *data)
{
    t_pars_map(data);
    ft_find_content(data);
    ft_add_textures(data);
    ft_add_colors(data);
    ft_take_cub(data);
    ft_find_player_pos(&(data)->carte);
    ft_pars_cub(data->carte.cub);
    ft_last_pars_cub(data->carte);
}

int main(int ac, char **av)
{
    t_data  data;
    
     if (ac != 2)
        print_error(av, "numberd argument not valid\n", 1);
    ft_pars_file(*av);
    ft_parsing(&data);
}
   