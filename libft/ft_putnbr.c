/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:15:41 by egaraz            #+#    #+#             */
/*   Updated: 2017/08/07 12:53:39 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put(int nb)
{
	ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

void		ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar('-');
			if (nb >= 10)
				ft_put(nb);
			else
				ft_putchar('0' + nb);
		}
		else
		{
			if (nb >= 10)
				ft_put(nb);
			else
				ft_putchar('0' + nb);
		}
	}
}
