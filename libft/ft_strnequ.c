/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:48:10 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/23 21:48:14 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strncmp(s1, s2, n);
		if (i != 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}
