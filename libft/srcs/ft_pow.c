/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:59:50 by jwilen            #+#    #+#             */
/*   Updated: 2020/02/21 00:58:25 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int x, unsigned int y)
{
	int temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}
