/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:11:11 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/04 14:50:22 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t    ft_strlen(const char *str)
{
    size_t    i;

    i = -1;
    while (str[++i])
        ;
    return (i);
}
void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    char    *ndest;
    char    *nsrc;
    size_t    i;

    ndest = (char *)dest;
    nsrc = (char *)src;
    i = -1;
    if (!ndest && !nsrc)
        return (0);
    while (++i < n)
        ndest[i] = nsrc[i];
    return (dest);
}



char    *ft_strjoin(char *s1, char *s2)
{
    size_t    i;
    size_t    j;
    char    *new;
    size_t    lens1;
    size_t    lens2;

    if (!s1 || !s2)
        return (NULL);
    i = 0;
    j = 0;
    lens1 = ft_strlen(s1);
    lens2 = ft_strlen(s2);
    new = malloc(lens1 + lens2 + 1);
    if (!new)
        return (NULL);
    while (i < lens1)
        new[i++] = s1[j++];
    j = 0;
    while (j < lens2)
        new[i++] = s2[j++];
    new[i] = '\0';
    return (new);
}

char    *ft_strchr(const char *s, int c)
{
    int    i;

    i = -1;
    if (!s)
        return (0);
    while (s[i] && s[i] != (char)c)
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    return (NULL);
}

// char    *ft_save(char *buff)
// {
//     int    i;
//     int    j;
//     static char    rest[BUFFER_SIZE];

//     i = 0;
//     while (buff[i] && buff[i] != '\n')
//         i++;
//     j = 0;
//     while (buff[++i])
//     {
//         rest[j] = buff[i];
//         j++;
//     }
//     rest[j] = 0;
//     return (rest);
// }

char    *ft_strfree(char *buff, char *str)
{
    char *tmp;

    tmp = ft_strjoin(buff, str);
    free(str);
    return (tmp);
}

// char    *ft_line(char *buff, char *str)
// {
//     int    size_b;
//     int    size_s;
//     int i;
//     char    *line;

//     size_b = ft_strlen(buff);
//     size_s = ft_strlen(str);
//     line = malloc(size_b - size_s + 1);
//     i = -1;
//     while (buff[++i] && buff[i] != '\n')
//         line[i] = buff[i];
//     line[i] = '\0';
//     line = ft_strjoin(str, line);
//     return (line);
// }
