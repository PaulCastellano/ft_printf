/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:07 by egaraz            #+#    #+#             */
/*   Updated: 2017/12/01 17:42:25 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char	*src1;
	int		len;
	int		i;
	int		k;

	if (str == NULL)
		return (NULL);
	k = 0;
	i = 0;
	len = ft_strlen(str) - 1;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ') && str[i])
		i++;
	while ((str[len] == '\n' || str[len] == '\t' || str[len] == ' ') && len > 0)
		len--;
	if (len < i)
		len = i;
	src1 = (char *)malloc(sizeof(char) * (len - i) + 2);
	if (src1 == NULL)
		return (NULL);
	while (i <= len)
		src1[k++] = str[i++];
	src1[k] = '\0';
	return (src1);
}
