/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 00:22:53 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/02 18:14:20 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	int			k;
	size_t		j;

	i = 0;
	j = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = i;
		k = 0;
		while (big[j] == little[k] && j < len)
		{
			j++;
			k++;
			if (little[k] == '\0')
				return (char*)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
