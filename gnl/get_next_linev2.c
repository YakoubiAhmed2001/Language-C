/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:00:38 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/11/07 18:52:52 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
char    *fill_gnl(int fd, char *buff, char *rest)
{
    char    str[BUFFER_SIZE + 1];
    int     ret;
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (0);
    ret = 1;
    while (ret && !strchr(str, '\n'))
    {
		
        ret = read(fd, str, BUFFER_SIZE);
        if (ret < 0 || (ret == 0 && rest  == NULL))
            return (NULL);	
        str[ret] = 0;
        //buff = malloc(BUFFER_SIZE + 1);
        buff = ft_strfree(buff, str);
    }
   // free(buff);
    return (buff);
}

// int    fill_gnl(int fd, char *buff)
// {
// 	int	ret;
	
// 	ret = read(fd, buff, BUFFER_SIZE);
// 	if (ret < 0)
// 		return (ret);
// 	buff[ret] = 0;
// 	return (ret);
// }

char    *ft_line(char *buff, char *rest)
{
	buff = ft_strjoin(rest, buff);
	return (buff);
}

void	ft_save(char *buff, char *rest)
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
	// buff = ft_strjoin(rest, buff);
	// return (buff);
}

char    *get_next_line(int fd)
{
	char    *buff;
	static char rest[BUFFER_SIZE];
	//int	ret = 1;

	//buff = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	// while (ret > 0)
	// {
	// 	buff = malloc(BUFFER_SIZE + 1);
	// 	if (!buff)
	// 		return (NULL);
	// 	ret = fill_gnl(fd, buff);
	// 	//printf("buff ===> %s", buff);
	// 	if (ret < 0 || ret == 0)
    //          return (NULL);
	// 	// if (rest == '\0')
	// 	// 	return (NULL);
	// 	// if (ret > 0 && !ft_strchr(buff, '\n'))
	// 	// 	return (ft_line(buff, rest));
		
	// }

	// buff = ft_line(buff, rest);
	// ft_save(buff, rest);	
	
	buff = NULL;
	buff = fill_gnl(fd, buff, rest);
	buff = ft_line(buff, rest);
	ft_save(buff, rest);
	
	 if (*buff == '\0')
		return (rest[fd] = 0, NULL);
	return (buff);
}

int main()
{
	int fd;
	char *s;
	fd = open("init.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("line 1 ==== > %s", s);
	s = get_next_line(fd);
	printf("line 2 ==== > %s", s);
	s = get_next_line(fd);
	printf("line 3 ==== > %s", s);
	s = get_next_line(fd);
	printf("line 4 ==== > %s", s);
	s = get_next_line(fd);
	printf("line 5 ==== > %s", s);
	s = get_next_line(fd);
	printf("line 6 ==== > %s", s);
	s = get_next_line(fd);
	printf("line 7 ==== > %s", s);
	return 0;
}
