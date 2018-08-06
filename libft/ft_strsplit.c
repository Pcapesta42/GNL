/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:04:58 by pcapesta          #+#    #+#             */
/*   Updated: 2017/12/03 15:30:15 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_number(char *str, char c)
{
	int			nb_word;
	int			in_word;

	if (!*str)
		return (0);
	nb_word = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && *str != '\0')
		{
			if (in_word == 0)
			{
				in_word = 1;
				nb_word++;
			}
		}
		else if (in_word == 1)
			in_word = 0;
		str++;
	}
	return (nb_word);
}

static char		*ft_fill_tab(char *dest, char *str, char c)
{
	int			i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		ft_size_str(char *str, char c)
{
	int			nb;
	int			i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			nb++;
		}
		if (str[i] == c || str[i] == '\0')
			return (nb);
		i++;
	}
	return (nb);
}

static int		ft_var(int *w, char c, char ***tab, char *str)
{
	if (!str)
		return (0);
	*w = 0;
	if (!(*tab = (char**)malloc(sizeof(char*) *
					(ft_word_number((char*)str, c) + 1))))
		return (0);
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int			w;
	char		**tab;
	int			i;

	i = 0;
	if (!ft_var(&w, c, &tab, (char*)s))
		return (NULL);
	while (w < ft_word_number((char*)s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tab[w] = (char*)malloc(sizeof(char) * ft_size_str((char*)s + i, c));
			tab[w] = ft_fill_tab(tab[w], (char*)s + i, c);
			w++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		i++;
	}
	tab[w] = 0;
	return (tab);
}
