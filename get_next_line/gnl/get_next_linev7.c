

#include "get_next_line.h"

char	*ft_free_rest(char	*buffer, char	*s)
{
	char	*tmp;
	tmp = ft_strjoin(buffer, s);
	free(buffer);
	return (tmp);
}

char    *fill_gnl(int fd, char *rest)
{
    //char    str[BUFFER_SIZE + 1];
    int     ret;
	char	*buff;

	if (!rest)
		rest = calloc(BUFFER_SIZE, 1);
	if (rest)
    	buff = calloc(BUFFER_SIZE + 1, 1);
	else
		return 0;
    if (!buff)
        return (0);
    ret = 1;
    while (ret > 0 && !strchr(buff, '\n'))
    {
		ret = read(fd, buff, BUFFER_SIZE);
        if (ret < 0)
            return (free(buff), NULL);
        buff[ret] = '\0';
        rest = ft_free_rest(rest, buff);
    }
	free(buff);
    return (rest);
}

char    *ft_line(char *rest)
{
	if (!rest[0])
		return (NULL);
    int i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	char *line;
	line = calloc(i + 2, 1);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i])
		line[i++] = '\n';
	line[i] = '\0';
    return (line);
}

char	*ft_save(char *rest)
{
	int	i;
	i = 0;
	char	*temp;
	while (rest[i] && rest[i] != '\n')
	{
		i++;
	}
	if (strchr(rest, '\n'))
	{
		temp = calloc(i + 2, 1);
		//temp = rest;
		i++;
		int j = 0;
		while (rest[i])
		{
			temp[j++] = rest[i++]; 
		}
		temp[j] = 0;
		return (temp);
	}
	return (rest);
}

char    *get_next_line(int fd)
{
    char    *buff;
    char *rest;
	static	char rest2[BUFFER_SIZE];

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
	rest = calloc(strlen(rest2) + 1, 1);
	int i = -1;
	while (rest2[++i])
		rest[i] = rest2[i];
	//printf("rest == %s\n", rest);	
    rest = fill_gnl(fd, rest);
	//printf("rest == %s\n", rest);
	buff = ft_line(rest);
	//printf("line == %s\n", buff);
    rest = ft_save(rest);
	i = -1;
	while (rest[++i])
		rest2[i] = rest[i];
	free(rest);
	// printf("rest == %s\n", rest);
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