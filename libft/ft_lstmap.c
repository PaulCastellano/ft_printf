/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:21:48 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/27 19:21:50 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ls;
	t_list *r;
	t_list *ls2;

	if (lst == NULL)
		return (NULL);
	ls2 = f(lst);
	ls = ft_lstnew(ls2->content, ls2->content_size);
	if (ls == NULL)
		return (NULL);
	r = ls;
	lst = lst->next;
	while (lst)
	{
		ls2 = f(lst);
		ls->next = ft_lstnew(ls2->content, ls2->content_size);
		if (ls->next == NULL)
			return (NULL);
		lst = lst->next;
		ls = ls->next;
	}
	return (r);
}
