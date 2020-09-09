/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_d_epsilon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:48:43 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:33:21 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		else if (str && dt->pre)
*/

void		check_d_sigma(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	if (dt->pre)
		insert_pad_zero(dt, len);
	else
		insert_pad_zero(dt, dt->pre_i.pre);
	write(dt->fd, str, len);
}

/*
**		else if (str && dt->w_i.zero && dt->w_i.pl)
*/

void		check_d_tau(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	(dt->wi) ? insert_pad(dt, len + 1) : insert_pad(dt, len);
	write(dt->fd, str, len);
	(dt->wi && dt->w_i.mi) ? insert_pad(dt, len) : 0;
}

/*
**		else if (str && dt->w_i.pl && dt->wi)
*/

void		check_d_upsilon(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(dt->wi) ? insert_pad(dt, len + 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	write(dt->fd, str, len);
	(dt->wi && dt->w_i.mi) ? insert_pad(dt, len) : 0;
}

/*
**		else if (str && dt->w_i.zero)
*/

void		check_d_phi(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->wi && nbr < 0) ? insert_pad_zero2(dt, len) : insert_pad(dt, len);
	write(dt->fd, str, len);
	(dt->wi && dt->w_i.mi) ? insert_pad(dt, len) : 0;
}

/*
**		else if (str)
*/

void		check_d_chi(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(dt->wi && !dt->w_i.mi && nbr < 0) ? insert_pad(dt, len + 1) : 0;
	(dt->wi && !dt->w_i.mi && nbr >= 0) ? insert_pad(dt, len) : 0;
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	write(dt->fd, str, len);
	(dt->wi && dt->w_i.mi && nbr < 0) ? insert_pad(dt, len + 1) : 0;
	(dt->wi && dt->w_i.mi && nbr >= 0) ? insert_pad(dt, len) : 0;
}
