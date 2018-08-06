/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:30:50 by pcapesta          #+#    #+#             */
/*   Updated: 2017/11/26 01:40:52 by pcapesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*nextlst;
	t_list		*tmp;

	tmp = *alst;
	while (tmp)
	{
		nextlst = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = nextlst;
	}
	*alst = NULL;
}
