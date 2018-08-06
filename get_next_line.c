#include "get_next_line.h"
#include <stdio.h>

t_multifd		*create_element(int fd)
{
	t_multifd	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_multifd))))
		return (NULL);
	tmp->fd = fd;
	return (tmp);
}

t_multifd		*get_fd(t_multifd **begin_list, int fd)
{
	t_multifd		*run_list;

	if (!(*begin_list))
	{
		*begin_list = create_element(fd);
		return (*begin_list);
	}
	run_list = *begin_list;
	while (run_list)
	{
		if (run_list->fd == fd)
			return (run_list);
		else
			run_list = run_list->next;
	}
	run_list = *begin_list;
	while (run_list->next)
		run_list = run_list->next;
	run_list->next = create_element(fd);
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

int get_next_line(const int fd, char **line)
{
	static t_multifd	*begin_list = NULL;
	char				buf[BUFF_SIZE + 1];
	t_multifd			*link_list;
	char				*tmp;
	int					ret;
	int					i;

	tmp = NULL;
	ret = 1;
	i = 0;
	if (!(line) || fd < 0 || !(link_list = get_fd(&begin_list, fd)))
		return (-1);
	if (link_list->rest)
	{
		tmp = ft_strdup(link_list->rest);
		ft_memdel((void**)&link_list->rest);
	}
	else
	{
		if (!(tmp = malloc(sizeof(char) * 1)))
			return (-1);
		tmp[0] = '\0';
	}
	while (!(ft_strchr(tmp, '\n')) && ret > 0)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	if (ret == -1)
		return (ret);
	else if (ret == 0 && tmp == NULL)
	{
		repare_list(&begin_list, link_list);
		return (0);
	}
	else if (ret == 0 && !(ft_strchr(tmp, '\n')))
		*line = ft_strdup(tmp);
	else
	{
		while (tmp[i] && tmp[i] != '\n')
			i++;
		*line = strndup(tmp, i);
		if (tmp[i] && tmp[i + 1])
			link_list->rest = ft_strsub(tmp, i + 1, ft_strlen(tmp) - (i + 1));
	}
	ft_memdel((void**)&tmp);
	return (1);
}


int		main()
{
	int fd;
	char *ou;
	fd = open("text.c", O_RDONLY);

	get_next_line(fd, &ou);
	printf("%s\n", ou);
	get_next_line(fd, &ou);
	return (1);

/*	while ((ret = get_next_line(fd, &ou)) > 0)
	{
		printf("%s\n", ou);
		free(ou);
	}

	//while (1)
	//;
}
*/
}
