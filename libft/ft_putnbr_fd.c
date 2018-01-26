/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:12:47 by egaraz            #+#    #+#             */
/*   Updated: 2017/11/24 21:12:48 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put(int nb, int fd)
{
	ft_putnbr_fd(nb / 10, fd);
	ft_putnbr_fd(nb % 10, fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar_fd('-', fd);
			if (nb >= 10)
				put(nb, fd);
			else
				ft_putchar_fd('0' + nb, fd);
		}
		else
		{
			if (nb >= 10)
				put(nb, fd);
			else
				ft_putchar_fd('0' + nb, fd);
		}
	}
}
