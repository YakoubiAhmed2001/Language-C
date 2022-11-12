/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:41:31 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/12 15:38:12 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

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

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if (!p)
		return (NULL);
	ft_memset(p, '\0', (num * size));
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;
	size_t	lens1;
	size_t	lens2;

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
/*
char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != (char)c)
		;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
*/
char    *ft_strchr(char *str, int c)
{
    while (*str != (char)c)
    {
        if (!*str)
            return (0);
        str++;
    }
    return ((char *)str);
}
