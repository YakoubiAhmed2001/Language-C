/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:11:11 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/11 13:21:51 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t    ft_strlen(const char *str)
{
	size_t    i;
	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}
// void    *ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	char    *ndest;
// 	char    *nsrc;
// 	size_t    i;

// 	ndest = (char *)dest;
// 	nsrc = (char *)src;
// 	i = -1;
// 	if (!ndest && !nsrc)
// 		return (0);
// 	while (++i < n)
// 		ndest[i] = nsrc[i];
// 	return (dest);
// }

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	size;
// 	char	*newstr;

// 	size = len + 1;
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		newstr = malloc(1);
// 		newstr[0] = 0;
// 		return (newstr);
// 	}
// 	i = 0;
// 	j = start;
// 	newstr = malloc(size);
// 	if (!newstr)
// 		return (NULL);
// 	while (j < len + start)
// 		newstr[i++] = s[j++];
// 	newstr[i] = '\0';
// 	return (newstr);
// }

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new;
	size_t			i;

	i = -1;
	new = (unsigned char *) s;
	while (++i < n)
		new[i] = c;
	return (s);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}


void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (num * size));
	return (p);
}


char    *ft_strjoin(char *s1, char *s2)
{
	size_t    i;
	size_t    j;
	char    *new;
	size_t    lens1;
	size_t    lens2;

	if (!s1 && !s2)
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

char    *ft_strchr(char *s, int c)
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

// char    *ft_strfree(char *buff, char *str)
// {
// 	char *tmp;

// 	tmp = ft_strjoin(buff, str);
// 	free(buff);
// 	return (tmp);
// }

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (src[++j])
		;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
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
