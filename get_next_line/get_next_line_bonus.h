/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:23:00 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/12 15:38:29 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

# endif

char	*get_next_line(int fd);
char	*ft_line(char *rest);
void	ft_save(char *rest);
char	*ft_strfree(char *buff, char *str);
size_t	ft_strlen(char *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

#endif
