/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 03:58:55 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/03 15:00:57 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		n = n * -1;
		count++;
	}
	else if (n == 0)
		return (ft_strdup("0"));
	count = ft_length(n) + count;
	if (!(str = ft_strnew(count)))
		return (NULL);
	str[count] = '\0';
	while (n > 0)
	{
		str[--count] = n % 10 + '0';
		n = n / 10;
	}
	if (count == 1)
		str[0] = '-';
	return (str);
}
