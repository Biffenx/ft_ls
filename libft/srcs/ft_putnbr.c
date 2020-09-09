/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:12:13 by jwilen            #+#    #+#             */
/*   Updated: 2019/10/21 14:16:13 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
		return ;
	}
	ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
}
