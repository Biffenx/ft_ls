/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_o_delta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:31:31 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:33:48 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		else if (str && dt->pre && dt->w_i.h_tag)
*/

void		check_o_omicron(t_tab *dt, unsigned int len, char *str)
{
	(dt->pre && dt->w_i.h_tag) ? insert_pad_neg(dt, dt->pre_i.pre) : 0;
	(dt->pre) ? insert_pad_neg(dt, ft_strlen(str)) : 0;
	if (dt->w_i.h_tag && len > 3)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
		write(dt->fd, str, len);
	}
	else if (dt->w_i.h_tag && dt->pre_i.pre == 0)
	{
		write(dt->fd, "0", 1);
		dt->len -= 1;
		write(dt->fd, str, len);
	}
	else if (str)
		write(dt->fd, str, len);
}

/*
**		else if (str && dt->pre)
*/

void		check_o_kappa(t_tab *dt, unsigned int len, char *str)
{
	(dt->pre && dt->w_i.h_tag) ? insert_pad_neg(dt, dt->pre_i.pre) : 0;
	(dt->pre) ? insert_pad_neg(dt, ft_strlen(str)) : 0;
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
**		else if (str)
*/

void		check_o_lambda(t_tab *dt, unsigned int len, char *str)
{
	(!dt->w_i.mi) ? insert_pad(dt, len) : 0;
	if (dt->w_i.h_tag >= 1)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
	(dt->w_i.mi) ? insert_pad(dt, len) : 0;
}
