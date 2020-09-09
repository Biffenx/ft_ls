/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_o_alfa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 08:36:40 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:29 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**	if (dt->hash && dt->wi && dt->pre && dt->pre_i.pre == 0 && nbr == 0)
*/

void		check_o_alfa(t_tab *dt, unsigned int len)
{
	(!dt->w_i.mi) ? insert_pad(dt, len) : 0;
	if (dt->hash)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
	}
	else
		dt->len -= 1;
	(dt->w_i.mi) ? insert_pad(dt, len) : 0;
}

/*
**	else if (dt->wi && dt->pre && dt->pre_i.pre == 0 && nbr == 0)
*/

void		check_o_beta(t_tab *dt, unsigned int len)
{
	(!dt->w_i.mi) ? insert_pad(dt, len - 1) : 0;
	if (dt->hash)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
	}
	else
		dt->len -= 1;
	(dt->w_i.mi) ? insert_pad(dt, len - 1) : 0;
}

/*
**	else if (dt->hash && dt->pre && dt->pre_i.pre == 0 && nbr == 0)
*/

void		check_o_delta(t_tab *dt, unsigned int len)
{
	(!dt->w_i.mi) ? insert_pad(dt, len - 1) : 0;
	if (dt->hash)
		write(dt->fd, "0", 1);
	else
		dt->len -= 1;
	(dt->w_i.mi) ? insert_pad(dt, len - 1) : 0;
}

/*
**	else if (dt->pre && dt->pre_i.pre == 0 && nbr == 0)
*/

void		check_o_epsilon(t_tab *dt, unsigned int len)
{
	(!dt->w_i.mi) ? insert_pad(dt, len - 1) : 0;
	if (dt->hash)
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
	}
	else
		dt->len -= 1;
	(dt->w_i.mi) ? insert_pad(dt, len - 1) : 0;
}

/*
**	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.zero)
*/

void		check_o_zeta(t_tab *dt, unsigned int len, char *str)
{
	if (dt->pre_i.pre > (int)ft_strlen(str))
		insert_pad2(dt, dt->pre_i.pre);
	else
		(dt->w_i.h_tag) ? insert_pad2(dt, len + 1) : insert_pad2(dt, len);
	if (dt->pre_i.pre < (int)ft_strlen(str))
		insert_pad_zero(dt, len + 1);
	else
		insert_pad_zero(dt, len);
	if (dt->w_i.h_tag && (dt->pre_i.pre < (int)ft_strlen(str)))
	{
		write(dt->fd, "0", 1);
		dt->len += 1;
		write(dt->fd, str, len);
	}
	else if (dt)
		write(dt->fd, str, len);
}
