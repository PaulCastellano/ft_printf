/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:36:41 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/23 19:36:42 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*s;

	s = (char *)malloc(size + 1);
	if (s != NULL)
	{
		i = 0;
		while (i <= size)
		{
			s[i] = '\0';
			i++;
		}
		return (s);
	}
	else
		return (NULL);
}
