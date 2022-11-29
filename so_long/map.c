/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:54:55 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/29 11:49:07 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map(void *mlx, void *mlx_win, int fd, char *line)
{
	t_data img;
	int i;
	int j;
	i = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		j = -1;
		while (line[++j])
		{
			if (line[j] == '1')
			{
				img.img = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
			}
			else if (line[j] == '0')
			{
				img.img = mlx_xpm_file_to_image(mlx, "./textures/grasss.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
			}
			else if (line[j] == 'C')
			{
				img.img = mlx_xpm_file_to_image(mlx, "./textures/grasss.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
				img.img = mlx_xpm_file_to_image(mlx, "./textures/newCoin.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
			}
			else if (line[j] == 'E')
			{	
				img.img = mlx_xpm_file_to_image(mlx, "./textures/grasss.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
				img.img = mlx_xpm_file_to_image(mlx, "./textures/box.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
			}
			else if (line[j] == 'P')
			{
				img.img = mlx_xpm_file_to_image(mlx, "./textures/grasss.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
				img.img = mlx_xpm_file_to_image(mlx, "./textures/man.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
			}
			else
			{
				img.img = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img.img_width, &img.img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
			}
		}
		free(line);
		
	}
}
