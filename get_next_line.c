/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:53:52 by pcapesta          #+#    #+#             */
/*   Updated: 2018/07/22 00:00:50 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(const int fd, char **line)
{
	static char		*rest = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*gnl;
	char			*interm;
	int i;

	gnl = NULL;
	interm = NULL;
	ret = 0;
	i = 0;

	if (rest)
	{
		//printf("coucou!\n");
		if (!(ft_strchr(rest, '\n')))
		{
			ret = read(fd, buf, BUFF_SIZE);
			if (ret == 0)
			{
				*line = ft_strdup(rest);
				return (1);
			}
			else if (ret == -1)
				return (-1);
			else if (ret != -1)
			{
				buf[ret] = '\0';
				gnl = ft_strjoin(rest, buf);
			}
		}
		else if (ft_strchr(rest, '\n'))
			gnl = ft_strdup(rest);
		ft_memdel((void**)&rest);
	}
	else if (!(rest))
	{
		//printf("coucou\n");
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0)
			return (0);
		else if (ret == -1)
			return (-1);
		else if (ret != -1)
		{
			buf[ret] = '\0';
			gnl = ft_strdup(buf);
		}
	}
	while (!(ft_strchr(gnl, '\n')))
	{
		interm = ft_strdup(gnl);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0)
		{
			*line = ft_strdup(interm);
			return (1);
		}
		else if (ret == -1)
			return (-1);
		else if (ret != -1)
		{
			buf[ret] = '\0';
			gnl = ft_strjoin(interm, buf);
		}
	}
	while (gnl[i] && gnl[i] != '\n')
		i++;
	*line = strndup(gnl, i);
	rest = ft_strsub(gnl, i + 1, ft_strlen(gnl) - (i + 1));
	rest[0] = 0;
	return (1);
}
\0 = 0 = NULL
'0' = 48

int		main()
{
	int fd;
	char *ou;
	int		ret = 0;
	int i = 0;

	fd = open("text.c", O_RDONLY);
	while (i < 3)
	{
		ret = get_next_line(fd, &ou);
		i++;
	}
}

