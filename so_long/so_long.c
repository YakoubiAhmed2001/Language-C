/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:08:06 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/12/03 14:49:09 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file)
{
	int i;
	int	count;
	char	*buff;
	int		fd;
	
	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	while (1) 
	{
		buff = get_next_line(fd);
		if (!buff)
			break;
		while (buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
			count++;
	}
	free(buff);
	return (count);	
}

// int	count_char(char *file)
// {
// 	int	fd;
// 	fd = open(file, O_RDONLY);
// 	char *line;
// 	line =
// }

char	**read_map(char *file)
{
	int fd;
	char	*line;
	line = NULL;
	char	*tmp;
	char	**map;
	fd = open(file, O_RDONLY);
	// map = (char *)(malloc())
		while (1)
	{
		tmp = get_next_line(fd);
		line = ft_strfree(line, tmp);
		if(!tmp)
			break;
	}
	map = ft_split(line, '\n');
	return (map);	
}

int	wall_pos(char *file, int x, int y)
{
	char	**map;
	map = read_map(file);
		if (map[x][y] == '1')
			return (1);
	return (0);
}

int	check_map(char *file, int x, int y)
{
	if (wall_pos(file, x -1, y) && wall_pos(file, x + 1, y) && wall_pos(file, x, y + 1) && wall_pos(file, x, y - 1))
		return (1);	
	return (0);
}

void	player_pos(char *file, int *x, int *y)
{
	int	fd;
	char	*line;
	
	int i;
	int j;
	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		++i;
		j = -1;
		while(line[++j])
		{
			if (line[j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
		}
		free(line);
	}
}

int	ft_close(int keycode, t_mlx *mlx)
{
	t_data file;
	file.file = "maps";
	// int i;
	// int j;
	t_data player;
	t_data grass;
	// int	fd;
	// char *line;
	player.img = mlx_xpm_file_to_image(mlx->mlx, "./textures/man.xpm", &player.img_width, &player.img_height);
	grass.img = mlx_xpm_file_to_image(mlx->mlx, "./textures/grasss.xpm", &grass.img_width, &grass.img_height);
	// player_pos(file.file, &i, &j);
	// printf("key == > %d\t i === > %d\t j === > %d\n",keycode, i, j);
	if (keycode == 126 && mlx->x >= 0 && !wall_pos(file.file, mlx->x - 1, mlx->y))
	{
		
		printf("x == > %d\t j == > %d\n", mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, grass.img, mlx->y * 50, mlx->x * 50);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player.img, mlx->y * 50, mlx->x * 50 - 50);
		mlx->x--;
	}
	if (keycode == 125 && mlx->x < count_line(file.file) - 1 && !wall_pos(file.file, mlx->x + 1, mlx->y))
	{
		printf("x == > %d\t j == > %d\n", mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, grass.img, mlx->y * 50, mlx->x * 50);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player.img, mlx->y * 50, mlx->x * 50 + 50);
		mlx->x++;
	}
	if (keycode == 124 && !wall_pos(file.file, mlx->x, mlx->y + 1))
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, grass.img, mlx->y * 50, mlx->x * 50);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player.img, mlx->y * 50 + 50, mlx->x * 50);
		mlx->y++;
	}
	if (keycode == 123 && mlx->y > 0 && !wall_pos(file.file, mlx->x, mlx->y - 1))
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, grass.img, mlx->y * 50, mlx->x * 50);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player.img, mlx->y * 50 - 50, mlx->x * 50);
		mlx->y--;
	}

	return (0);
}


void    so_long(int fd , char *file)
{
	t_mlx mlx;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return ;
	player_pos(file, &mlx.x, &mlx.y);
	if (check_map(file, mlx.x, mlx.y))
	{
		printf("map invalid");
		return ;
	}
	char *line = get_next_line(fd);
	close(fd);
	mlx.mlx_win = mlx_new_window(mlx.mlx, ft_strlen(line) * 50 - 50, count_line(file) * 50, "mlx game");
	if (mlx.mlx_win == NULL)
		return (free(mlx.mlx_win));
	//player_pos(file, &mlx.x, &mlx.y);
	loop_map(mlx.mlx, mlx.mlx_win, file);
	close(fd);
	mlx_hook(mlx.mlx_win, 2, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	//mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}

int main(int ac, char *av[])
{
	(void) ac;
	int	fd;
	fd = open(av[1], O_RDONLY);
	so_long(fd, av[1]);
	close(fd);
	return 0;
}
