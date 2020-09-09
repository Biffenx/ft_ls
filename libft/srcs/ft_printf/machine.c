/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:00:55 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:21 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		A basic itoa_max for int numbers,
**		note that the minus sign is removed from max minus
*/

char		*ft_itoa_imax(t_tab *dt, intmax_t n)
{
	char			*ret;
	int				len;
	long long		nb;

	if (n == -9223372036854775807 - 1)
		return (ft_strdup("9223372036854775808"));
	if (n < 0)
		dt->neg = 1;
	nb = ft_abs(n);
	len = ft_getintlen(nb);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		exit(-1);
	ret[len] = '\0';
	while (len-- > 0)
	{
		ret[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}

/*
**		Returning the correct indicator for signed flags
*/

intmax_t	check_flag_signed(t_tab *dt)
{
	if (dt->flag_info.hh)
		return ((char)va_arg(dt->ap, intmax_t));
	else if (dt->flag_info.h)
		return ((short)va_arg(dt->ap, intmax_t));
	else if (dt->flag_info.ll)
		return ((long long)va_arg(dt->ap, intmax_t));
	else if (dt->flag_info.l)
		return ((long)va_arg(dt->ap, intmax_t));
	else if (dt->flag_info.z)
		return ((size_t)va_arg(dt->ap, size_t));
	else if (dt->flag_info.j)
		return ((intmax_t)va_arg(dt->ap, uintmax_t));
	return ((int)va_arg(dt->ap, intmax_t));
}

/*
**		Returning the correct indicator for unsigned flags
*/

uintmax_t	check_flag_unsigned(t_tab *dt)
{
	if (dt->flag_info.hh)
		return ((unsigned char)va_arg(dt->ap, uintmax_t));
	else if (dt->flag_info.h)
		return ((unsigned short)va_arg(dt->ap, uintmax_t));
	else if (dt->flag_info.ll)
		return ((unsigned long long)va_arg(dt->ap, uintmax_t));
	else if (dt->flag_info.l)
		return ((unsigned long)va_arg(dt->ap, uintmax_t));
	else if (dt->flag_info.z)
		return ((size_t)va_arg(dt->ap, size_t));
	else if (dt->flag_info.j)
		return ((intmax_t)va_arg(dt->ap, uintmax_t));
	return ((unsigned int)va_arg(dt->ap, uintmax_t));
}

/*
**		Managing conversion f for l and L
*/

long double	conv_double(t_tab *dt)
{
	if (dt->flag_info.ld == 1)
		return (va_arg(dt->ap, long double));
	else
		return (va_arg(dt->ap, double));
}

/*
**		Main parse function
*/

int			parse_format(t_tab *dt)
{
	dt->i = 0;
	while (dt->fr[dt->i] != '\0')
	{
		if (dt->fr[dt->i] == '%')
		{
			dt->i++;
			if (dt->fr[dt->i] == '\0')
				return (0);
			check_flags(dt);
		}
		else
			write(dt->fd, &dt->fr[dt->i], 1);
		dt->len += 1;
		if (dt->fr[dt->i] != '\0')
			dt->i++;
	}
	return (0);
}
