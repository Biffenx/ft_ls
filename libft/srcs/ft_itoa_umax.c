/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_umax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:03:54 by jwilen            #+#    #+#             */
/*   Updated: 2020/02/21 00:59:10 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_umax(uintmax_t n)
{
	char		*str;
	uintmax_t	str_len;
	uintmax_t	n2;

	n2 = n;
	str_len = ft_getintlen(n);
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n2 % 10 + '0';
	while (n2 /= 10)
		str[--str_len] = n2 % 10 + '0';
	return (str);
}
