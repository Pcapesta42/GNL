#include "get_next_line.h"
#include <stdio.h>

t_multifd		*save(int fd, char **lin, char *tmp, t_multifd **list)
{
	int i;
	t_multifd	*maillon;

	i = 0;
	maillon = NULL;
	if (fd >= 0)
	{
		if (!(maillon = ft_memalloc(sizeof(t_multifd))))
			return (NULL);
		maillon->fd = fd;
	}
	else
	{
		while (tmp[i] && tmp[i] != '\n')
			i++;
		*lin = strndup(tmp, i);
		if (tmp[i] && tmp[i + 1])
			(*list)->rest = ft_strsub(tmp, i + 1, ft_strlen(tmp) - (i + 1));
	}
	return (maillon);
}

t_multifd		*get_fd(t_multifd **begin_list, int fd)
{
	t_multifd		*run_list;

	if (!(*begin_list))
	{
		*begin_list = save(fd, 0, 0, 0);
		return (*begin_list);
	}
	run_list = *begin_list;
	while (run_list)
	{
		if (run_list->fd == fd)
			return (run_list);
		run_list = run_list->next;
	}
	run_list = *begin_list;
	while (run_list->next)
		run_list = run_list->next;
	run_list->next = save(fd, 0, 0, 0);
	return (run_list->next);
}

void		repare_list(t_multifd **begin_list, t_multifd *link_list)
{
	t_multifd	*run_list;

	run_list = *begin_list;
	if (!(run_list))
		return ;
	if (run_list == link_list)
	{
		free(link_list);
		*begin_list = NULL;
		return ;
	}
	while (run_list->next && run_list->next != link_list)
		run_list = run_list->next;
	run_list->next = link_list->next;
	free(link_list);
}

int		read_gnl(t_multifd *link_list, char **tmp, int fd)
{
	int		ret;
	char	*anti_leak;
	char	buf[BUFF_SIZE + 1];

	ret = 1;
	anti_leak = NULL;
	if (link_list->rest)
		if (!(*tmp = ft_strdup(link_list->rest)))
			return (-1);
	ft_memdel((void**)&link_list->rest);
	else if (!(*tmp = ft_memalloc(sizeof(char) * 1)))
		return (-1);
	while (!(ft_strchr(*tmp, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		anti_leak = *tmp;
		if (!(*tmp = ft_strjoin(*tmp, buf)))
			return (-1);
		ft_memdel((void**)&anti_leak);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (ret);
}


int get_next_line(const int fd, char **line)
{
	static t_multifd	*begin_list = NULL;
	t_multifd			*link_list;
	char				*tmp;
	int					r;

	tmp = NULL;
	if (!(line) || fd < 0 || !(link_list = get_fd(&begin_list, fd)))
		return (-1);
	r = read_gnl(link_list, &tmp, fd);
	if (r == -1 || (r == 0 && tmp[0] == '\0'))
	{
		ft_memdel((void**)&tmp);
		if (r == 0)
			repare_list(&begin_list, link_list);
		return (r);
	}
	else if (r == 0 && !(ft_strchr(tmp, '\n')))
		*line = ft_strdup(tmp);
	else
		save(-1, line, tmp, &link_list);
	ft_memdel((void**)&tmp);
	return (1);
}


/*
int		main()
{
	int fd;
	char *ou;
	int ret = 1;
	fd = open("text.c", O_RDONLY);




	while ((ret = get_next_line(fd, &ou)) > 0)
	{
		printf("%s\n", ou);
		free(ou);
	}

	//while (1)
//	;

}
*/
