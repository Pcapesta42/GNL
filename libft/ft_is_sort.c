/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:43:55 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/03 14:44:30 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		croissant;
	int		decroissant;

	i = 0;
	croissant = 1;
	decroissant = 1;
	while (i + 1 < length && croissant == 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			croissant = 0;
		i++;
	}
	while (i + 1 < length && decroissant == 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			decroissant = 0;
		i++;
	}
	if (decroissant == 1 || croissant == 1)
		return (1);
	else
		return (0);
}
