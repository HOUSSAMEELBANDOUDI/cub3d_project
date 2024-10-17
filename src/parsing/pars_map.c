/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:17:53 by hel-band          #+#    #+#             */
/*   Updated: 2024/10/16 18:14:02 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static int ft_get_number_line(char *av)
{
    char    *line;
    int     fd;
    int     number_lines;

    number_lines = 0;
    fd = open(av, O_RDONLY);
    if (fd == -1)
        print_error(av, "fd get_line_map:", 1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        number_lines++;
        free(line);
        line = get_next_line(fd);
    }
    close (fd);
    return (number_lines);
}

static void    ft_remplir_map(t_data *data)
{
    int fd;
    int i;
    
    fd = open(data->av[1], O_RDONLY);
    if (fd == -1)
        print_error(data->av[1], "fd ft_remplir_map:", 1);
    data->map = ft_calloc(data->carte.nbr_line, sizeof(char *));
    i = 0;
    while(i < data->carte.nbr_line)
    {
        data->map[i] = get_next_line(fd);
        i++;
    }
    data->map[i] = NULL;
    close (fd);
}

int ft_pars_map(t_data *data)
{
    int fd;

    fd = open(data->av[1], O_RDONLY);
    if (fd == -1)
        print_error(data->av[1], "fd pars_map:", 1);
    data->carte.nbr_line = ft_get_number_line(data->av[1]);
    if (data->carte.nbr_line == 0)
        print_error(data->av[1], "nbr_line_in_map_invalid:", 1);
    close (fd);
    ft_remplir_map(data);
}