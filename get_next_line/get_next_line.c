/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:45:40 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/26 22:18:07 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *fill_gnl(int fd, char *buff)
{
	char	*str;
	int	ret;
	str = NULL;
//	ret = read(fd, buff, BUFFER_SIZE);
//	printf("buff	====>%s \n", buff);
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	str[BUFFER_SIZE] = 0;
	ret = read(fd, str, BUFFER_SIZE);
	if (ret == -1)
	{
		free(str);
		return (NULL);
	}
	while (ret > 0 && !strchr(str, '\n'))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (0);
		ret = read(fd, buff, BUFFER_SIZE);
	//	printf("str	====> %s\n",str);
		str = ft_strjoin(str, buff);
	//	printf("%s\n", str);
	}
//	printf ("new buff	====> %s", buff);
	return (str);
}	

char *get_next_line(int fd)
{
	char	*buff;
	static char *baki;
	buff = NULL;
	buff = fill_gnl(fd, buff);
	baki = ft_sive(buff);
	return (buff);
}

int main()
{
	int fd;
	char *s;
	fd = open("init.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("s ==== >%s\n", s);
	return 0;
}
