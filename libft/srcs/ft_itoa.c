/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:02:17 by jwilen            #+#    #+#             */
/*   Updated: 2020/02/13 13:36:43 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		return_size(int n)
{
	int		size;

	size = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = (n < 0) ? return_size(n) + 1 : return_size(n);
	if (!(str = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	i = size - 1;
	while (n >= 10)
	{
		str[i] = (char)(n % 10 + 48);
		n /= 10;
		i--;
	}
	str[i] = (char)(n % 10 + 48);
	str[size] = '\0';
	return (str);
}
