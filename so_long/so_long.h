/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:56:47 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/28 16:30:15 by ayakoubi         ###   ########.fr       */
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

typedef struct	s_data {
	void	*img;
	char	*src;
	int		img_width;
	int		img_height;	
}				t_data;

char	*get_next_line(int fd);
void	ft_map(void *mlx, void *mlx_win, int fd, char *line);
void	ft_putnbr(int nbr);
void	ft_putstr_fd(char *fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

#endif
