/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:26:10 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/03 15:13:47 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		j;
	int		i;
	char	stock;

	j = 0;
	i = 0;
	stock = 0;
	while (str[j] != '\0')
		j++;
	j--;
	while (i < j)
	{
		stock = str[i];
		str[i] = str[j];
		str[j] = stock;
		i++;
		j--;
	}
	return (str);
}
