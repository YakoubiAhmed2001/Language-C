/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:45:40 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/04 17:24:25 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char    *fill_gnl(int fd, char *buff, char *rest)
{
    char    *str;
    int     ret;

    str = malloc(BUFFER_SIZE + 1);
    if (!str)
        return (0);
    ret = 1;
    while (ret && !strchr(str, '\n'))
    {
        if (ret < 0 || (ret == 0 && rest  != NULL))
            return (free(buff), NULL);
        buff = malloc(BUFFER_SIZE + 1);
        ret = read(fd, buff, BUFFER_SIZE);
        buff[ret] = '\0';
        str = ft_strjoin(str, buff);
        
    }
    
   // free(buff);
    return (str);
}

char    *ft_line(char *buff, char *rest)
{
    buff = ft_strjoin(rest, buff);
    return (buff);
}

void    ft_save(char *buff, char *rest)
{
    int i = -1;
    while (buff[++i] && buff[i] != '\n')
        ;
    int j = 0;
    while (buff[++i])
    {
        rest[j++] = buff[i];
        buff[i] = 0;
    }
    rest[j] = 0;
}

char    *get_next_line(int fd)
{
    char    *buff;
    static char rest[BUFFER_SIZE];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	buff = NULL;
    buff = fill_gnl(fd, buff, rest);
    buff = ft_line(buff, rest);
    ft_save(buff, rest);
     if (*buff == '\0')
        return (rest[fd] = 0, NULL);
    return (buff);
}

// int main()
// {
//     int fd;
//     char *s;
//     fd = open("init.txt", O_RDONLY);
//     s = get_next_line(fd);
//     printf("line 1 ==== > %s", s);
//     s = get_next_line(fd);
//     printf("line 2 ==== > %s", s);
//     s = get_next_line(fd);
//     printf("line 3 ==== > %s", s);
//     s = get_next_line(fd);
//     printf("line 4 ==== > %s", s);
//     s = get_next_line(fd);
//     printf("line 5 ==== > %s", s);
//     s = get_next_line(fd);
//     printf("line 6 ==== > %s", s);
//     s = get_next_line(fd);
//     printf("line 7 ==== > %s", s);
//     return 0;
// }
