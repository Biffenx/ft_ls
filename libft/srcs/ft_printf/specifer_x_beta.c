/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_x_beta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:54 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:31 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void		c_x_zeta(t_tab *dt, char *ltr, char *str, unsigned int len)
{
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad(dt, (dt->pre_i.pre + len));
	else
		insert_pad(dt, len + 2);
	write(dt->fd, ltr, 2);
	dt->len += 2;
	insert_pad_neg(dt, len);
	write(dt->fd, str, len);
}

void		c_x_eta(t_tab *dt, char *ltr, char *str, unsigned int len)
{
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre);
	else
		insert_pad(dt, len);
	(dt->pre_i.pre) ? insert_pad_zero(dt, len) : 0;
	if (dt->w_i.h_tag)
	{
		write(dt->fd, ltr, 2);
		dt->len += 2;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
}

void		c_x_theta(t_tab *dt, char *ltr, char *str, unsigned int len)
{
	if (dt->pre && dt->w_i.h_tag)
	{
		write(dt->fd, ltr, 2);
		dt->len += 2;
		insert_pad_neg(dt, dt->pre_i.pre);
	}
	(dt->pre) ? insert_pad_neg(dt, ft_strlen(str)) : 0;
	write(dt->fd, str, len);
	dt->len += (dt->w_i.h_tag) ? dt->pre_i.pre - 1 : 0;
}

void		c_x_oita(t_tab *dt, char *ltr, char *str, unsigned int len)
{
	if (dt->w_i.h_tag)
	{
		write(dt->fd, ltr, 2);
		dt->len += 2;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
	if (dt->w_i.mi)
	{
		if (dt->w_i.h_tag)
			insert_pad(dt, ft_strlen(str) + 2);
		else
			insert_pad(dt, ft_strlen(str));
	}
}
