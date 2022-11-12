#include "get_next_line.h"

static int    charpos(char *s, char c)
{
    int    i;

    i = 0;
    while (*s)
    {
        if (*s == c)
            return (i);
        s++;
        i++;
    }
    return (i);
}

static char    *line_handler(char *hold)
{
    char    *tmp;
    char    *line;
    int        pos;

    pos = charpos(hold, '\n');
    line = ft_substr(hold, 0, pos + 1);
    tmp = hold;
    hold = ft_substr(tmp, pos + 1, ft_strlen(tmp));
    //free(tmp);
    return (line);
}

static int    read_line(char *buff, int fd)
{
    int        rd;

    rd = read(fd, buff, BUFFER_SIZE);
    if(rd < 0)
        return (rd);
    buff[rd] = '\0';
    return (rd);

}

static void    fill_holder(char *hold, char *buff)
{
    char    *tmp;

    if (!hold)
        hold = strdup("");
    tmp = hold;
    hold = ft_strjoin(tmp, buff);
    // free(tmp);
    // free(buff);
}

char    *get_next_line(int fd)
{
    static char    *hold[BUFFER_SIZE];
    char        *buff;
    int            rd;
    if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buff)
            return (NULL);
        rd = read_line(buff, fd);
        if (rd < 0 || rd == 0 )
            return (free(buff), NULL);
        fill_holder(hold, buff);
        if (hold[fd] == '\0')
            return (/*free(hold),*/ *hold[fd] = 0, NULL);
        if ((rd == 0 && hold[fd]) || (ft_strchr(hold, '\n') != NULL))
            return (line_handler(hold));
    }
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
