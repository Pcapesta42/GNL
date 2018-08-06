/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 07:47:43 by pcapesta          #+#    #+#             */
/*   Updated: 2017/11/26 08:48:46 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*negative = 1;
		*n = -*n;
		return (1);
	}
	return (0);
}

static int		ft_size(int n, int base)
{
	int		size;
	int		tmp;

	size = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / base;
		size++;
	}
	return (size);
}


char	*ft_itoabase(int n, int base)
{
	int		negative;
	int		size;
	char	*tab;
	int		i;
	int		tmp;

	i = 0;
	size = 0;
	negative = 0;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	if (ft_negative(&n, &negative) == 1)
		tmp = n;
	size = ft_size(tmp, base) + negative;
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return(NULL);
	else if (n == 0)
	{
		tab[0] = '0';
		i++;
	}
	while (i + negative < size)
	{
		tab[i] = n % base + '0';
		n = n / base;
		i++;
	}
	if (negative == 1)
	{
		tab[i] = '-';
		i++;
	}
	tab = ft_strrev(tab);
	tab[i] = '\0';
	return (tab);
}

int		main(int ac, char **av)
{
	if (ac < 0)
		return (0);
	printf("%s", ft_itoabase(ft_atoi(av[1]), ft_atoi(av[2])));
}
