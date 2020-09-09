/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_d_gamma.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:05:59 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:32 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		if (str && dt->wi && dt->pre && (dt->w_i.zero || dt->zero))
**			if (dt->w_i.mi && dt->w_i.pl)
*/

void		check_d_kappa(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	if (dt->pre)
		insert_pad_zero(dt, len);
	else
		insert_pad_zero(dt, dt->pre_i.pre);
	write(dt->fd, str, len);
	if (dt->pre_i.pre >= (int)ft_strlen(str) && nbr >= 0)
		insert_pad(dt, dt->pre_i.pre + 1);
	if (dt->pre_i.pre < (int)ft_strlen(str) && nbr >= 0)
		insert_pad(dt, dt->pre_i.pre + 2);
	if (nbr < 0 && dt->pre_i.pre >= (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre < (int)ft_strlen(str))
		insert_pad(dt, len + 1);
}

/*
**		if (str && dt->wi && dt->pre && (dt->w_i.zero || dt->zero))
**			else if (dt->w_i.mi)
*/

void		check_d_lambda(t_tab *dt, intmax_t nbr, int len, char *str)
{
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	(dt->pre) ? insert_pad_zero(dt, len) : 0;
	write(dt->fd, str, len);
	if (dt->pre_i.pre >= (int)ft_strlen(str) && nbr >= 0)
		insert_pad(dt, dt->pre_i.pre);
	if (dt->pre_i.pre < (int)ft_strlen(str) && nbr >= 0)
		insert_pad(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre >= (int)ft_strlen(str))
		insert_pad(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre < (int)ft_strlen(str))
		insert_pad(dt, len + 1);
}

/*
**		if (str && dt->wi && dt->pre && (dt->w_i.zero || dt->zero))
**			else if (dt->w_i.pl)
*/

void		check_d_mu(t_tab *dt, intmax_t nbr, int len, char *str)
{
	if (dt->pre_i.pre >= (int)ft_strlen(str) && nbr >= 0)
		insert_pad2(dt, dt->pre_i.pre + 1);
	if (dt->pre_i.pre < (int)ft_strlen(str) && nbr >= 0)
		insert_pad2(dt, dt->pre_i.pre + 2);
	if (nbr < 0 && dt->pre_i.pre >= (int)ft_strlen(str))
		insert_pad2(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre < (int)ft_strlen(str))
		insert_pad2(dt, len + 1);
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	if (dt->pre)
		insert_pad_zero(dt, len);
	else
		insert_pad_zero(dt, dt->pre_i.pre);
	write(dt->fd, str, len);
}

/*
**		if (str && dt->wi && dt->pre && (dt->w_i.zero || dt->zero))
**			else
*/

void		check_d_nu(t_tab *dt, intmax_t nbr, int len, char *str)
{
	if (dt->pre_i.pre >= (int)ft_strlen(str) && nbr >= 0)
		insert_pad2(dt, dt->pre_i.pre);
	if (dt->pre_i.pre < (int)ft_strlen(str) && nbr >= 0)
		insert_pad2(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre >= (int)ft_strlen(str))
		insert_pad2(dt, dt->pre_i.pre + 1);
	if (nbr < 0 && dt->pre_i.pre < (int)ft_strlen(str))
		insert_pad2(dt, len + 1);
	(nbr < 0) ? write(dt->fd, "-", 1) : 0;
	(dt->w_i.pl && nbr >= 0) ? write(dt->fd, "+", 1) : 0;
	if (dt->pre)
		insert_pad_zero(dt, len);
	else
		insert_pad_zero(dt, dt->pre_i.pre);
	write(dt->fd, str, len);
}
