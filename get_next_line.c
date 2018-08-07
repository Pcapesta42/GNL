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
	char				*anti_leak;
	int					ret;


	tmp = NULL;
	anti_leak = NULL;
	ret = 1;
	if (!(line) || fd < 0 || !(link_list = get_fd(&begin_list, fd)))
		return (-1);
	if (link_list->rest)
	{
		tmp = ft_strdup(link_list->rest);
		ft_memdel((void**)&link_list->rest);
	}
	else if (!(tmp = ft_memalloc(sizeof(char) * 1)))
	{
		ft_memdel((void**)&tmp);
		return (-1);
	}
	while (!(ft_strchr(tmp, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		anti_leak = tmp;
		tmp = ft_strjoin(tmp, buf);
		ft_memdel((void**)&anti_leak);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (ret == -1 || (ret == 0 && tmp[0] == '\0'))
	{
		ft_memdel((void**)&tmp);
		if (ret == 0)
			repare_list(&begin_list, link_list);
		return (ret);
	}
	else if (ret == 0 && !(ft_strchr(tmp, '\n')))
		*line = ft_strdup(tmp);
	else
	{
		ret = 0;
		while (tmp[ret] && tmp[ret] != '\n')
			ret++;
		*line = strndup(tmp, ret);
		if (tmp[ret] && tmp[ret + 1])
			link_list->rest = ft_strsub(tmp, ret + 1, ft_strlen(tmp) - (ret + 1));
	}
	ft_memdel((void**)&tmp);
	return (1);
}


/*int		main()
{
	int fd;
	char *ou;
	int ret = 1;
	fd = open("text.c", O_RDONLY);

	get_next_line(fd, &ou);
	printf("%s\n", ou);
	get_next_line(fd, &ou);
	printf("%s\n", ou);
	get_next_line(fd, &ou);
	printf("%s\n", ou);


	while ((ret = get_next_line(fd, &ou)) > 0)
	{
		printf("%s\n", ou);
		free(ou);
	}

	//while (1)
//	;

}
*/
