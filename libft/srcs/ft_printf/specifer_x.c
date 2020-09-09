/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:50:35 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:34:12 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

char		check_x(t_tab *dt, char *ltr, char *str, unsigned int len)
{
	if (dt->fr[dt->i] == 'X')
	{
		ft_toupper_str(str, len);
		dt->caps = 1;
	}
	if (dt->caps == 0)
		ltr = "0x";
	else
		ltr = "0X";
	return (*ltr);
}

void		x_length(t_tab *dt, unsigned int len)
{
	if (dt->pre_i.pre > dt->wi && dt->pre_i.pre < (int)len + 3)
		dt->len += (dt->pre_i.pre);
	else
		dt->len += len - 1;
	if (dt->pre_i.pre > (int)len && dt->wi < (int)len + 2 && (int)len < 5)
		dt->len -= 2;
	if (!dt->wi && len > 2 && dt->pre && (dt->pre_i.pre + 2) > (int)len)
		dt->len -= 1;
	if (dt->wi < dt->pre_i.pre && (int)len > 7
			&& (dt->pre_i.pre < (int)len + 1))
		dt->len -= 1;
}

void		speci_x2(t_tab *dt, unsigned int len, char *str, char *ltr)
{
	if (str && dt->wi && dt->pre_i.pre && dt->w_i.zero && dt->w_i.h_tag)
		check_x_alfa(dt, ltr, str, len);
	else if (dt->pre && dt->pre_i.pre == 0 && dt->nbr == 0)
		check_x_beta(dt);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.zero)
		c_x_gamma(dt, ltr, str, len);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.mi && dt->w_i.h_tag)
		c_x_delta(dt, ltr, str, len);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.mi)
		c_x_epsilon(dt, ltr, str, len);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.h_tag)
		c_x_zeta(dt, ltr, str, len);
	else if (str && dt->wi && dt->pre_i.pre)
		c_x_eta(dt, ltr, str, len);
	else if (str && dt->pre)
		c_x_theta(dt, ltr, str, len);
	else if (str && dt->w_i.mi)
		c_x_oita(dt, ltr, str, len);
	else if (str && dt->w_i.zero && dt->w_i.h_tag)
		c_x_xi(dt, ltr, str, len);
	else if (str)
		c_x_pi(dt, ltr, str, len);
	x_length(dt, len);
	free(str);
}

/*
**		Conversion %x for hex
*/

void		specifer_x(t_tab *dt)
{
	uintmax_t		nbr;
	unsigned int	len;
	char			*str;
	char			*ltr;

	asterix(dt);
	nbr = check_flag_unsigned(dt);
	dt->nbr = nbr;
	str = ft_itoa_b(nbr, 16);
	len = ft_strlen(str);
	if (dt->fr[dt->i] == 'X')
	{
		ft_toupper_str(str, len);
		dt->caps = 1;
	}
	if (dt->caps == 0)
		ltr = "0x";
	else
		ltr = "0X";
	if (dt->w_i.zero && dt->w_i.mi)
		dt->w_i.zero = 0;
	if (dt->w_i.h_tag && nbr == 0)
		dt->w_i.h_tag = 0;
	speci_x2(dt, len, str, ltr);
}
