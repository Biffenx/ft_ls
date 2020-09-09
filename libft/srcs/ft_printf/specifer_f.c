/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:28:00 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:33:31 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		padding for #
*/

void		insert_pad_hash(t_tab *dt, int len)
{
	int t;

	t = 0;
	while (t++ < dt->pre_i.pre - len)
	{
		(dt->pre) ? write(dt->fd, "0", 1) : write(dt->fd, " ", 1);
		dt->len++;
	}
}

void		insert_float(t_tab *dt, char *str, int len)
{
	if (dt->w_i.sp && dt->neg == 0 && dt->w_i.pl == 0)
	{
		write(dt->fd, " ", 1);
		len++;
	}
	else if (dt->w_i.pl && dt->neg == 0 && dt->pre == 0)
		write(dt->fd, "+", 1);
	else if (dt->w_i.pl && dt->neg == 0 && dt->w_i.zero)
		write(dt->fd, "+", 1);
	if ((dt->w_i.h_tag && dt->pre_i.pre == 0) || (dt->w_i.pl && dt->neg == 0))
		len++;
	if (dt->neg == 1 && dt->w_i.zero)
		write(dt->fd, "-", 1);
	(dt->w_i.zero == 0) ? float_padd(dt, ' ', len) : float_padd(dt, '0', len);
	if (dt->neg == 1 && dt->w_i.zero == 0)
		write(dt->fd, "-", 1);
	if (dt->w_i.pl || dt->neg)
		dt->w_i.sp = 0;
	if (dt->w_i.pl && dt->neg == 0 && dt->pre && dt->w_i.zero == 0)
		write(dt->fd, "+", 1);
	while (*str)
		write(dt->fd, str++, 1);
	if (dt->w_i.h_tag && dt->pre_i.pre == 0)
		write(dt->fd, ".", 1);
}

/*
**		padding for float with minus
*/

void		insert_float_minus(t_tab *dt, char *str, int len)
{
	if (dt->w_i.sp && dt->neg == 0 && dt->w_i.pl == 0)
	{
		write(dt->fd, " ", 1);
		len++;
	}
	else if (dt->w_i.pl && dt->neg == 0)
	{
		write(dt->fd, "+", 1);
		len++;
	}
	if (dt->neg)
	{
		write(dt->fd, "-", 1);
		dt->w_i.sp = 0;
	}
	while (*str)
		write(dt->fd, str++, 1);
	if (dt->w_i.h_tag && dt->pre_i.pre == 0)
	{
		write(dt->fd, ".", 1);
		len++;
	}
	float_padd(dt, ' ', len);
}

/*
**		padding for float
*/

void		float_padd(t_tab *dt, char c, int len)
{
	int		i;
	int		j;

	i = 0;
	j = (dt->pre_i.pre > len) ? dt->pre_i.pre : len;
	if (dt->wi > len)
		while (i++ < (dt->wi - j))
			write(dt->fd, &c, 1);
}

/*
**		Conversion %f for bits
*/

void		specifer_f(t_tab *dt)
{
	long double		nbr;
	int				len;
	char			*str;

	asterix(dt);
	if (dt->pre == 0)
	{
		dt->pre_i.pre = 6;
		dt->pre = 1;
	}
	nbr = conv_double(dt);
	if (nbr < 0)
		dt->neg = 1;
	str = ft_ftoa(nbr, dt->pre_i.pre, dt->pre);
	len = (dt->neg == 0) ? ft_strlen(str) : (ft_strlen(str) + 1);
	if (dt->w_i.mi == 0)
		insert_float(dt, str, len);
	else
		insert_float_minus(dt, str, len);
	dt->len += (dt->wi > len + dt->w_i.sp) ? dt->wi : (len - 1 + dt->w_i.sp);
	if (len + 1 > dt->wi && dt->w_i.pl)
		dt->len++;
	free(str);
}
