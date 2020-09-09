/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_d_beta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:40:56 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:43 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		if (str && dt->w_i.sp && !dt->w_i.pl)
**			if (dt->w_i.zero)
*/

void		check_d_epsilion(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr >= 0) ? write(dt->fd, " ", 1) : 0;
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	(dt->wi > (int)ft_strlen(str)) ? insert_pad(dt, len + 1) : 0;
	(dt->wi < (int)ft_strlen(str)) ? insert_pad_zero(dt, len) : 0;
	write(dt->fd, str, len);
}

/*
**		if (str && dt->w_i.sp && !dt->w_i.pl)
**			else if (dt->wi && dt->pre)
*/

void		check_d_zeta(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr >= 0) ? write(dt->fd, " ", 1) : 0;
	if (dt->pre_i.pre >= (int)ft_strlen(str) && nbr >= 0 && !dt->w_i.mi)
		insert_pad(dt, dt->pre_i.pre);
	if (dt->pre_i.pre < (int)ft_strlen(str) && nbr >= 0 && !dt->w_i.mi)
		insert_pad(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre >= (int)ft_strlen(str) && !dt->w_i.mi)
		insert_pad(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre < (int)ft_strlen(str) && !dt->w_i.mi)
		insert_pad(dt, len + 1);
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	if (dt->pre)
		insert_pad_zero(dt, len);
	else
		insert_pad_zero(dt, dt->pre_i.pre);
	write(dt->fd, str, len);
	if ((dt->pre_i.pre > (int)ft_strlen(str)) && dt->w_i.mi && nbr < 0)
		insert_pad(dt, dt->pre_i.pre + 1);
	if ((dt->pre_i.pre < (int)ft_strlen(str)) && dt->w_i.mi && nbr < 0)
		insert_pad(dt, len + 1);
	if ((dt->pre_i.pre > (int)ft_strlen(str)) && dt->w_i.mi && nbr >= 0)
		insert_pad(dt, dt->pre_i.pre + 1);
	if ((dt->pre_i.pre < (int)ft_strlen(str)) && dt->w_i.mi && nbr >= 0)
		insert_pad(dt, len + 1);
}

/*
**		if (str && dt->w_i.sp && !dt->w_i.pl)
**			else if (dt->wi)
*/

void		check_d_eta(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(dt->wi && !dt->w_i.mi && nbr < 0) ? insert_pad(dt, len + 1) : 0;
	(nbr >= 0) ? write(dt->fd, " ", 1) : 0;
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	(dt->wi && !dt->w_i.mi && nbr >= 0) ? insert_pad(dt, len + 1) : 0;
	write(dt->fd, str, len);
	(dt->wi && dt->w_i.mi && nbr < 0) ? insert_pad(dt, len + 1) : 0;
	(dt->wi && dt->w_i.mi && nbr >= 0) ? insert_pad(dt, len + 1) : 0;
}

/*
**		if (str && dt->w_i.sp && !dt->w_i.pl)
**			else if (dt->pre)
*/

void		check_d_theta(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr >= 0) ? write(dt->fd, " ", 1) : 0;
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	if (dt->pre)
		insert_pad_zero(dt, len);
	else
		insert_pad_zero(dt, dt->pre_i.pre);
	write(dt->fd, str, len);
}

/*
**		if (str && dt->w_i.sp && !dt->w_i.pl)
**			else
*/

void		check_d_iota(t_tab *dt, intmax_t nbr, int len, char *str)
{
	if (dt->w_i.sp && nbr >= 0 && (!dt->w_i.pl) &&
	(dt->wi <= (int)ft_strlen(str)))
		write(dt->fd, " ", 1);
	if (dt->w_i.sp && nbr >= 0 && (!dt->w_i.pl) &&
	(dt->wi > (int)ft_strlen(str)))
		if (dt->w_i.mi)
			write(dt->fd, " ", 1);
	(dt->wi && !dt->w_i.mi && nbr < 0) ? insert_pad(dt, len + 1) : 0;
	(dt->wi && !dt->w_i.mi && nbr >= 0) ? insert_pad(dt, len) : 0;
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	write(dt->fd, str, len);
	(dt->wi && dt->w_i.mi && nbr < 0) ? insert_pad(dt, len + 1) : 0;
	(dt->wi && dt->w_i.mi && nbr >= 0) ? insert_pad(dt, len + 1) : 0;
}
