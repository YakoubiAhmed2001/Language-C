/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:49:26 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/04 12:32:54 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strfree(char *buff, char *str);
//char	*ft_save(char *buff, char *rest);
char	*ft_line(char *buff, char *str);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
#endif