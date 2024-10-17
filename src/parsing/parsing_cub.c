/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:56:16 by hel-band          #+#    #+#             */
/*   Updated: 2024/10/16 20:11:17 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int ft_arroud_player(char **cub, int row, int col)
{
    if (cub[row][col + 1] == ' ' || cub[row][col - 1] == ' '
		|| cub[row + 1][col] == ' ' || cub[row - 1][col] == ' ')
        print_error("", "Player surronded by spaces", 1);
    return (1);
}
void    ft_pars_cub(char **cub)
{
    int i;
    int j;
    int flag;

    flag = 0;
    i = 0;
    while (cub[i])
    {
        j = 0;
        while (cub[i][j])
        {
            if (!ft_find_char(cub[i][j], " 01NSEW"))
                print_error("", "Invalid charachter in map", 1);
            if (ft_find_char(cub[i][j], "NSEW")
                && ft_arroud_player(cub, i, j))
                flag++;
            j++;
        }
        i++;
    }
    if (flag == 0)
        print_error("", "you don't have palyer in map", 1);
    if (flag > 1)
        print_error("", "you should have only one player", 1);
}
