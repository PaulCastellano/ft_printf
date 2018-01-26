/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:01:40 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/23 22:01:41 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (s != NULL)
	{
		str = (char *)malloc(len + 1);
		if (str != NULL)
		{
			i = 0;
			while (i < len)
			{
				str[i] = s[start];
				i++;
				start++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (str);
}
