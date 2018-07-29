/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:53:52 by pcapesta          #+#    #+#             */
/*   Updated: 2018/07/29 23:43:38 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_multifd		*createelement(int fd)
{
	t_multifd *tmp;

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
		*begin_list = createelement(fd);
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
	run_list->next = createelement(fd);
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

int		get_next_line(const int fd, char **line)
{
	static t_multifd	*begin_list = NULL;
	char				buf[BUFF_SIZE + 1];
	int					ret;
	char				*gnl;
	char				*interm;
	int					i;
	t_multifd			*link_list;

	gnl = NULL;
	interm = NULL;
	ret = 0;
	i = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
	if (!(line) || fd < 0 || !(link_list = get_fd(&begin_list, fd)))
		return (-1);
	if (link_list->rest)
	{
		if (!(ft_strchr(link_list->rest, '\n')))
		{
			ret = read(fd, buf, BUFF_SIZE);
			if (ret == 0 || ret == -1)
			{
				if (!ret && !(*line = ft_strdup(link_list->rest)))
					ret = -1;
				ft_memdel((void**)&(link_list->rest));
				return (ret == 0 ? 1 : -1);
			}
			buf[ret] = '\0';
			if (!(gnl = ft_strjoin(link_list->rest, buf)))
				return (-1);
		}
		else if (!(gnl = ft_strdup(link_list->rest)))
			return (-1);
		ft_memdel((void**)&(link_list->rest));
	}
	else if ((ret = read(fd, buf, BUFF_SIZE)) > -2)
	{
		if (ret != 0 && ret != -1)
		{
			buf[ret] = '\0';
			if (!(gnl = ft_strdup(buf)))
				return (-1);
		}
		else
		{
			if (ret == 0)
				repare_list(&begin_list, link_list);
			return (ret);
		}
	}
	while (!(ft_strchr(gnl, '\n')))
	{
		interm = gnl;
		ft_bzero(buf, BUFF_SIZE + 1);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0 || ret == -1)
		{
			if (ret == 0)
				*line = ft_strdup(interm);
			ft_memdel((void**)&interm);
			return (ret == 0 ? 1 : -1);
		}
		buf[ret] = '\0';
		gnl = ft_strjoin(interm, buf);
		ft_memdel((void**)&interm);
		if (!(gnl))
			return (-1);
	}
	while (gnl[i] && gnl[i] != '\n')
		i++;
	*line = strndup(gnl, i);
	if (gnl[i] && gnl[i + 1])
		link_list->rest = ft_strsub(gnl, i + 1, ft_strlen(gnl) - (i + 1));
	ft_memdel((void**)&gnl);
	return (1);
}

/*int		main()
{
	int fd;
	char *ou;
	int ret = 0;
	fd = open(getenv("QUEUE"), O_RDONLY);

	while ((ret = get_next_line(fd, &ou)) > 0)
	{
		printf("%d\n", ret);
		free(ou);
	}

	//while (1)
	//;
}
*/
