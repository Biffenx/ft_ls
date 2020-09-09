/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_u_alfa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 05:25:02 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:48:52 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void		u_h_uno(t_tab *dt, unsigned int len, char *str)
{
	(dt->w_i.pl) ? insert_pad(dt, len) : 0;
	(!dt->w_i.mi) ? insert_pad(dt, len) : 0;
	(dt->pre_i.pre) ? insert_pad_zero(dt, len) : 0;
	write(dt->fd, str, len);
	(dt->w_i.mi) ? insert_pad(dt, len) : 0;
}

void		u_h_duo(t_tab *dt, unsigned int len, char *str)
{
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre);
	else
		insert_pad(dt, len);
	(dt->pre_i.pre) ? insert_pad_zero(dt, len) : 0;
	write(dt->fd, str, len);
}

void		u_h_tre(t_tab *dt, unsigned int len, char *str)
{
	len = 0;
	dt->len -= 1;
	(dt->wi) ? insert_pad(dt, ft_strlen(str + 1)) : 0;
	write(dt->fd, str, len);
	(dt->w_i.mi) ? insert_pad(dt, dt->wi) : 0;
}

void		u_h_qtr(t_tab *dt, unsigned int len, char *str)
{
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad2(dt, dt->pre_i.pre);
	else
		insert_pad2(dt, len);
	(dt->pre_i.pre) ? insert_pad_zero(dt, len) : 0;
	write(dt->fd, str, len);
}

void		u_h_zinco(t_tab *dt, unsigned int len, char *str)
{
	(dt->pre_i.pre) ? insert_pad_zero(dt, len) : 0;
	write(dt->fd, str, len);
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre);
	else
		insert_pad(dt, len);
}
