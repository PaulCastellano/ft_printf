/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:30:47 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/17 17:30:49 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *d;
	unsigned const char *s;

	d = (unsigned const char *)s1;
	s = (unsigned const char *)s2;
	while (n--)
		if (*d != *s)
			return (*d - *s);
		else
		{
			d++;
			s++;
		}
	return (0);
}
