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
        ft_line(buff, rest);
		free(buff);
    }
   // free(buff);
    return (rest);
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

void    ft_line(char *buff, char *rest)
{
	//char *line;
	char *tmp;

	if (!rest)
		rest = strdup("");
	tmp = rest;
	rest = ft_strjoin(tmp, buff);
	//free(tmp);
	//free(buff);
	// return (rest);
}

char	*ft_save(char *buff, char *rest)
{
	int i = -1;
	while (buff[++i] && buff[i] != '\n')
		;
	
	char	*line;
	char	*tmp;
	line = ft_substr(rest, 0, i + 1);
	tmp = rest;
	rest = ft_substr(tmp, i + 1, ft_strlen(rest));
	//free(tmp);
	return (line);
	
	// while (buff[++i])
	// {
	// 	rest[j++] = buff[i];
	// 	buff[i] = 0;
	// }
	// rest[j] = 0;
	// buff = ft_strjoin(rest, buff);
	// return (buff);
}

char    *get_next_line(int fd)
{
	char    *buff;
	static char rest[BUFFER_SIZE];
	//int	ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// while (1)
	// {
	// 	buff = malloc(BUFFER_SIZE + 1);
	// 	ret = fill_gnl(fd, buff);
	// 	if (ret < 0 || (ret == 0 && rest  != NULL))
    //          return (NULL);
	// 	ft_save(buff, rest);
	// 	if (rest == '\0')
	// 		return (NULL);
	// 	if ((ret == 0 && *rest) || !ft_strchr(buff, '\n'))
	// 		return (ft_line(buff, rest));
		
	// }
	buff = NULL;
	buff = fill_gnl(fd, buff, rest);

	return (ft_save(buff, rest));
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