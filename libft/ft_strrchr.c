/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 23:41:06 by pcapesta          #+#    #+#             */
/*   Updated: 2017/11/24 23:52:40 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int stock;

	i = 0;
	stock = -1;
	while (s[i])
	{
		if (s[i] == c)
			stock = i;
		i++;
	}
	if (c == '\0')
		return ((char*)s + i);
	else if (stock == -1)
		return (NULL);
	return ((char*)s + stock);
}
