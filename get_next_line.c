#include "get_next_line.h"
#include <stdio.h>


char		*read_gnl(char **rest, int fd)
{

	char	*final;
	char	buf[BUFF_SIZE + 1];
	int		ret = 1;

	if (*rest && ft_strchr(*rest, '\n') == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret != -1)
		{
			buf[ret] = '\0';
			final = ft_strjoin(*rest, buf);
			ft_memdel((void*)rest);
		}
		else
			return (NULL);
	}
	else if (*rest && ft_strchr(*rest, '\n') != NULL)
	{
		final = ft_strdup(*rest);
		ft_memdel((void*)rest);
	}
	else
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret != -1)
		{
			buf[ret] = '\0';
			final = ft_strdup(buf);
		}
	}
	return (final);
}

char		*cut_line(char **final, int fd, char **rest)
{
	char *inter;
	inter = NULL;

	char *detector;
	detector = NULL;

	int ret = 1;
	char buf[BUFF_SIZE + 1];

	int i = 0;
	char *newline;

	while (!(detector = ft_strchr(*final, '\n')))
	{
		inter = ft_strdup(*final);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret != -1 && ret != 0)
		{
			buf[ret] = '\0';
			*final = ft_strjoin(inter, buf);
		}
	}
	while ((*final)[i] && (*final)[i] != '\n')
	{
		i++;
	}
	newline = strndup(*final, i);
	*rest = ft_strsub(*final, i + 1, ft_strlen(*final) - (i + 1));
	return (newline);
}

int		get_next_line(const int fd, char **line)
{
	static char *rest = NULL;

	char *stock;
	stock = NULL;

	stock = read_gnl(&rest, fd);
	if (stock)
	{
		*line = cut_line(&stock, fd, &rest);
		printf("%s\n", *line);
		return (1);
	}
	else
		return (0);
}

int main()
{

	//int fd;
	char *ou;
	int coucou;

	//fd = open("text.c", O_RDONLY);
	coucou = get_next_line(0, &ou);
	printf("%d\n", coucou);
	//get_next_line(fd, &ou);
	//get_next_line(fd, &ou);
	//get_next_line(fd, &ou);
	//get_next_line(fd, &ou);
}

