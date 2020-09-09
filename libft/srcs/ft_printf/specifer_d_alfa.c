/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_d_alfa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:18:24 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:33:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		if (dt->w_i.zero && dt->w_i.mi)
*/

void		check_d_alfa(t_tab *dt)
{
	dt->w_i.zero = 0;
	dt->zero = 1;
}

/*
**		if (dt->wi > ft_strlen(str) + 3 &&
**		dt->pre && dt->w_i.sp && !dt->w_i.mi)
*/

void		check_d_beta(t_tab *dt)
{
	dt->w_i.sp = 0;
	dt->sp = 1;
}

/*
**		Gamma and Delta are the same
*/

void		check_d_gamma(t_tab *dt, int len)
{
	(!dt->w_i.mi && !dt->w_i.pl) ? insert_pad(dt, len - 1) : 0;
	(!dt->w_i.mi && dt->w_i.pl) ? insert_pad(dt, len) : 0;
	if (dt->w_i.pl)
	{
		write(dt->fd, "+", 1);
		dt->len += 1;
	}
	else
		dt->len -= 1;
	(dt->w_i.mi && !dt->w_i.pl) ? insert_pad(dt, len - 1) : 0;
	(dt->w_i.mi && dt->w_i.pl) ? insert_pad(dt, len) : 0;
}

/*
**		if (dt->pre && dt->pre_i.pre == 0 && nbr == 0)
*/

void		check_d_delta(t_tab *dt, int len)
{
	(!dt->w_i.mi && !dt->w_i.pl) ? insert_pad(dt, len - 1) : 0;
	(!dt->w_i.mi && dt->w_i.pl) ? insert_pad(dt, len) : 0;
	if (dt->w_i.pl)
	{
		write(dt->fd, "+", 1);
		dt->len += 1;
	}
	else
		dt->len -= 1;
	(dt->w_i.mi && !dt->w_i.pl) ? insert_pad(dt, len - 1) : 0;
	(dt->w_i.mi && dt->w_i.pl) ? insert_pad(dt, len) : 0;
}
