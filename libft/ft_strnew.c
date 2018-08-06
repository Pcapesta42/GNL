/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 02:22:28 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/02 18:40:43 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*pt;
	size_t			i;

	i = 0;
	if (!(pt = malloc(size + 1)))
		return (NULL);
	while (i <= size)
	{
		pt[i] = '\0';
		i++;
	}
	pt[size] = '\0';
	return (pt);
}
