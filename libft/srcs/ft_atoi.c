/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:31:10 by jwilen            #+#    #+#             */
/*   Updated: 2019/10/24 13:18:27 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\v' || str[i] == '\n' ||
				str[i] == '\r' || str[i] == '\f' || str[i] == '\t'))
		str++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
