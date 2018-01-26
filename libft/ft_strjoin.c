/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:34:24 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/24 14:34:25 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_scat(char const *s3, char const *s4, char *str1)
{
	int		i;
	int		j;

	i = 0;
	while (s3[i])
	{
		str1[i] = s3[i];
		i++;
	}
	j = 0;
	while (s4[j])
	{
		str1[i + j] = s4[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(len + 1);
		if (str != NULL)
		{
			str = ft_scat(s1, s2, str);
		}
		return (str);
	}
	else
		return (str);
}
