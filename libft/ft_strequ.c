/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:25:12 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/23 21:25:13 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strcmp(s1, s2);
		if (i != 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}
