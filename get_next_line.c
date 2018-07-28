/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:53:52 by pcapesta          #+#    #+#             */
/*   Updated: 2018/07/28 20:20:18 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
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
		//printf("Il y a un reste\n");
		if (!(ft_strchr(rest, '\n')))
		{
			ret = read(fd, buf, BUFF_SIZE);
			if (ret == 0)
			{
				*line = ft_strdup(rest);
				ft_memdel((void**)&rest);
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
			free(interm);
			free(gnl);
			return (1);
		}
		else if (ret == -1)
		{
			free(interm);
			free(gnl);
			return (-1);
		}
		else if (ret != -1)
		{
			buf[ret] = '\0';
			gnl = ft_strjoin(interm, buf);
		}
	}
	free(interm);
	while (gnl[i] && gnl[i] != '\n')
		i++;
	*line = strndup(gnl, i);
	if (gnl[i] != '\0' && gnl[i + 1] != '\0')
		rest = ft_strsub(gnl, i + 1, ft_strlen(gnl) - (i + 1));
	else
		ft_memdel((void**)&rest);
	free(gnl);
	return (1);
}

/*int		main()
{
	int fd;
	char *ou;
	int		ret = 0;
	int i = 0;

	fd = open("test1", O_RDONLY);
	ret = get_next_line(fd, &ou);
	while (ret > -1)
	{
		ret = get_next_line(fd, &ou);
	}
}
*/
