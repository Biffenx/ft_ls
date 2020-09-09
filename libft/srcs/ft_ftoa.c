/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:51:35 by jwilen            #+#    #+#             */
/*   Updated: 2020/02/25 07:51:13 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_umax_2(uintmax_t n)
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

static long double	rounding(int pre, long double f)
{
	long double	rounding;
	int			d;

	rounding = 0.5;
	if (f < 0)
		rounding *= -1;
	d = 0;
	while (d++ < pre)
		rounding /= 10.0;
	return (rounding);
}

char				*ft_ftoa(long double f, int pre, int dot)
{
	unsigned long long	dec;
	char				*ipart;
	char				*fpart;
	char				*joint;
	int					i;

	f = f + rounding(pre, f);
	f *= (f < 0) ? -1 : 1;
	dec = f;
	ipart = ft_itoa_umax_2(dec);
	f = pre ? (f - dec) : 0;
	fpart = ft_strnew(pre + 2);
	fpart[0] = (dot == 1 && pre > 0) ? '.' : '\0';
	i = 1;
	while (pre-- > 0)
	{
		f *= 10;
		dec = f;
		f -= dec;
		fpart[i++] = dec + '0';
	}
	joint = ft_strjoin(ipart, fpart);
	free(fpart);
	free(ipart);
	return (joint);
}
