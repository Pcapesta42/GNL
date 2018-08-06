/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:23:26 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/02 14:25:12 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutspace(char const *s)
{
	int		i;
	char	*tab;
	int		j;

	tab = ft_strnew(ft_strlen(s));
	i = 0;
	j = 0;
	while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strcpy(tab, s));
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			{
				tab[j] = s[i];
				j++;
			}
			i++;
		}
	}
	return (tab);
}
