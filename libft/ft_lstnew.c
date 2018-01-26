/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:38:16 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/26 11:40:12 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ls;

	ls = (t_list *)malloc(sizeof(t_list));
	if (ls == NULL)
		return (NULL);
	if (content == NULL)
	{
		ls->content = NULL;
		ls->content_size = 0;
	}
	else
	{
		ls->content = malloc(content_size);
		if (ls->content == NULL)
			return (NULL);
		ft_memcpy(ls->content, content, content_size);
		ls->content_size = content_size;
	}
	ls->next = NULL;
	return (ls);
}
