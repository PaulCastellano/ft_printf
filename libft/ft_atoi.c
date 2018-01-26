/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:30:45 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/20 18:33:15 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ft_ops(long int n, char c)
{
	n *= 10;
	n += (int)c - '0';
	return (n);
}

static int			ft_neg(int c)
{
	int	q;

	if (c == '-')
		q = 1;
	else
		q = 0;
	return (q);
}

static int			ft_plus(char c, int j)
{
	if (c == '+' || c == '-')
		j++;
	return (j);
}

int					ft_atoi(const char *str)
{
	int			i;
	long int	nbr;
	int			neg;

	nbr = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	neg = ft_neg(str[i]);
	i = ft_plus(str[i], i);
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (nbr > 2147483647 && neg == 0)
			return (-1);
		else if (nbr > 2147483648 && neg == 1)
			return (0);
		nbr = ft_ops(nbr, str[i]);
		i++;
	}
	if (neg == 1)
		return (-nbr);
	else
		return (nbr);
}
