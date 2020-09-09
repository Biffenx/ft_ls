/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_o_beta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:18:20 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:28 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.h_tag)
*/

void		check_o_pi(t_tab *dt, unsigned int len, char *str)
{
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre);
	else
		insert_pad(dt, len + 1);
	if (ft_strlen(str) > 3)
		insert_pad_zero(dt, len + 1);
	else
		insert_pad_zero(dt, len);
	if (dt->w_i.h_tag && len > 3)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
}

/*
**	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.h_tag)
*/

void		check_o_eta(t_tab *dt, unsigned int len, char *str)
{
	if (dt->w_i.mi)
	{
		if (ft_strlen(str) < 3)
			insert_pad_zero(dt, len);
		else
			insert_pad_zero(dt, len + 1);
		if (dt->w_i.h_tag && len > 3)
		{
			write(dt->fd, "0", 1);
			dt->len += 1;
			write(dt->fd, str, len);
		}
		else
			write(dt->fd, str, len);
		if (dt->pre_i.pre > (int)ft_strlen(str))
			insert_pad(dt, dt->pre_i.pre);
		else
			insert_pad(dt, len + 1);
	}
	else
		check_o_pi(dt, len, str);
}

/*
**	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.mi)
*/

void		check_o_theta(t_tab *dt, unsigned int len, char *str)
{
	(dt->pre_i.pre) ? insert_pad_zero(dt, len) : 0;
	if (dt->w_i.h_tag)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre);
	else
		insert_pad(dt, len);
}

/*
**	else if (str && dt->wi && dt->pre_i.pre)
*/

void		check_o_oita(t_tab *dt, unsigned int len, char *str)
{
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre);
	else
		insert_pad(dt, len);
	(dt->pre_i.pre) ? insert_pad_zero(dt, len) : 0;
	if (dt->w_i.h_tag && len > 3)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
}

/*
**	else if (str && dt->wi && dt->w_i.h_tag)
*/

void		check_o_xi(t_tab *dt, unsigned int len, char *str)
{
	(!dt->w_i.mi) ? insert_pad(dt, len + 1) : 0;
	if (dt->w_i.h_tag >= 1)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
	(dt->w_i.mi) ? insert_pad(dt, len + 1) : 0;
}
