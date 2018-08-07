/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:20:56 by pcapesta          #+#    #+#             */
/*   Updated: 2018/07/29 23:44:18 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 9999

int		get_next_line(const int fd, char **line);

typedef struct			s_multifd
{
	char				*rest;
	int					fd;
	struct s_multifd	*next;
}						t_multifd;



#endif
