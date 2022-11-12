/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:45:40 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/11 16:58:11 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_rest(char	*buffer, char	*s)
{
	char	*tmp;
	tmp = ft_strjoin(buffer, s);
	if (!tmp)
		return (NULL);
	free(buffer);
	return (tmp);
}

char    *fill_gnl(int fd, char *rest)
{
	//char    str[BUFFER_SIZE];
	int     ret;
	char    *buff;

	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
		return (0);
	ret = 1;
	while (ret > 0 && !strchr(buff, '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0 || (ret == 0 && rest == NULL))
			return (free(buff), NULL);
		buff[ret] = '\0';
		rest = ft_free_rest(rest, buff);
	}
	free(buff);
	return (rest);
}

char    *ft_line(char *buff)
{
	int i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	char *line;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return 0;
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i])
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

void    ft_save(char *rest)
{
	char	*buff;
	
	buff = rest;
	int i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == 0 || (buff[i] == '\n' && buff[i + 1] == 0))
	{
		rest[0] = 0;
		return ;
	}
	int j = 0;
	while (buff[++i])
	{
		rest[j++] = buff[i];
	}
	rest[j] = 0;
}

char    *get_next_line(int fd)
{
	char    *rest;
	static	char rest2[BUFFER_SIZE];
	char    *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rest = ft_calloc(strlen(rest2) + 1, 1);
	int i = -1;
	while (rest2[++i])
		rest[i] = rest2[i];
	if (!strchr(rest, '\n'))
		rest = fill_gnl(fd, rest);
	if (!rest[0])
		return (free(rest), NULL);
	//printf("buff === > %s\n", buff);
	line = ft_line(rest);
	
	ft_save(rest);
	i = -1;
	while (rest[++i])
		rest2[i] = rest[i];
	i++;
	rest[i] = '\0';
	free(rest);
	//ft_save(buff, rest);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *s;
// 	fd = open("41_with_nl", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("line 1 ==== > %s", s);
// 	s = get_next_line(fd);
// 	printf("line 2 ==== > %s", s);
// 	s = get_next_line(fd);
// 	printf("line 3 ==== > %s", s);
// 	// s = get_next_line(fd);  
// 	// printf("line 4 ==== > %s", s);
// 	// s = get_next_line(fd);
// 	// printf("line 5 ==== > %s", s);
// 	// s = get_next_line(fd);  
// 	// printf("line 6 ==== > %s", s);
// 	// s = get_next_line(fd);
// 	// printf("line 7 ==== > %s", s);
// 	// s = get_next_line(fd);
// 	// printf("line 8 ==== > %s", s);
// 	// s = get_next_line(fd);
// 	// printf("line 9 ==== > %s", s);
// 	// s = get_next_line(fd);
// 	// printf("line 10 ==== > %s", s);
// 	return 0;
// }