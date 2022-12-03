/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:56:47 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/12/03 13:21:02 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"



typedef struct	s_mlx {
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
}				t_mlx;

typedef struct	s_data {
	char 	*file;
	void	*img;
	char	*src;
	int		img_width;
	int		img_height;	
}				t_data;

char	*get_next_line(int fd);
void	loop_map(void *mlx, void *mlx_win, char *file);
void	ft_map(void *mlx, void *mlx_win, char *line, int i, int j);
void	ft_putnbr(int nbr);
void	ft_putstr_fd(char *fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

#endif
