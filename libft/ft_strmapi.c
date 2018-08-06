/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:02:17 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/02 19:17:52 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*pt;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(pt = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(pt, s);
	while (s[i])
	{
		pt[i] = f(i, pt[i]);
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
