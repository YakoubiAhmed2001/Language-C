/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:54:55 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/12/01 12:37:24 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check(void *mlx, void *mlx_win, char *src, int i, int j)
{
	t_data img;
	img.img = mlx_xpm_file_to_image(mlx, src, &img.img_width, &img.img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
}

void	ft_map(void *mlx, void *mlx_win, char *line , int i, int j)
{
	if (line[j] == '1')
		ft_check(mlx, mlx_win, "./textures/wall.xpm", i, j);
	else if (line[j] == '0')
		ft_check(mlx, mlx_win, "./textures/grasss.xpm", i, j);
	else if (line[j] == 'C')
	{
		ft_check(mlx, mlx_win, "./textures/grasss.xpm", i, j);
		ft_check(mlx, mlx_win, "./textures/newCoin.xpm", i, j);
	}
	else if (line[j] == 'E')
	{	
		ft_check(mlx, mlx_win, "./textures/grasss.xpm", i, j);
		ft_check(mlx, mlx_win, "./textures/box.xpm", i, j);
	}
	else if (line[j] == 'P')
	{
		ft_check(mlx, mlx_win, "./textures/grasss.xpm", i, j);
		ft_check(mlx, mlx_win, "./textures/man.xpm", i, j);
	}
	else
		ft_check(mlx, mlx_win, "./textures/wall.xpm", i, j);
}

void	loop_map(void *mlx, void *mlx_win, char *file)
{
	int	fd;
	char	*line;
	int	i;
	int	j;
	
	i = -1;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		i++;
		j = -1;
		while(line[++j])
			ft_map(mlx, mlx_win, line, i, j);
		free(line);
	}
}