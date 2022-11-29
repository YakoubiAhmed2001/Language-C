/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:08:06 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/29 11:48:30 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd, char *file)
{
	int i;
	int	count;
	char	*buff;
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
	close(fd);
	return (count);	
}

void    so_long(int fd , char *file)
{
	void	*mlx;
	void	*mlx_win;
	mlx = mlx_init();
	char *line = get_next_line(fd);
	close(fd);
	mlx_win = mlx_new_window(mlx, ft_strlen(line) * 50 - 50, count_line(fd, file) * 50, "mlx game");
	fd = open(file, O_RDONLY);
	ft_map(mlx, mlx_win, fd, line);
	mlx_loop(mlx);
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
