/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:11:28 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/02 18:28:15 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*s1;
	const char		*s2;
	unsigned char	count;

	i = 0;
	s1 = dest;
	s2 = src;
	count = c;
	while (i < n)
	{
		s1[i] = s2[i];
		if ((unsigned char)s2[i] == (unsigned char)count)
			return (&s1[i + 1]);
		i++;
	}
	return (NULL);
}
