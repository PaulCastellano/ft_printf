/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:55:12 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/27 17:55:22 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ls;
	t_list *nxlist;

	ls = *alst;
	while (ls)
	{
		nxlist = ls->next;
		del(ls->content, ls->content_size);
		free(ls);
		ls = nxlist;
	}
	*alst = NULL;
}
