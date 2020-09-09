/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:28:54 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:33:34 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void		speci_o2(t_tab *dt, uintmax_t nbr, unsigned int len, char *str)
{
	if (dt->hash && dt->wi && dt->pre && dt->pre_i.pre == 0 && nbr == 0)
		check_o_alfa(dt, len);
	else if (dt->wi && dt->pre && dt->pre_i.pre == 0 && nbr == 0)
		check_o_beta(dt, len);
	else if (dt->hash && dt->pre && dt->pre_i.pre == 0 && nbr == 0)
		check_o_delta(dt, len);
	else if (dt->pre && dt->pre_i.pre == 0 && nbr == 0)
		check_o_epsilon(dt, len);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.zero)
		check_o_zeta(dt, len, str);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.h_tag)
		check_o_eta(dt, len, str);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.mi)
		check_o_theta(dt, len, str);
	else if (str && dt->wi && dt->pre_i.pre)
		check_o_oita(dt, len, str);
	else if (str && dt->wi && dt->w_i.h_tag)
		check_o_xi(dt, len, str);
	else if (str && dt->pre && dt->w_i.h_tag)
		check_o_omicron(dt, len, str);
	else if (str && dt->pre)
		check_o_kappa(dt, len, str);
	else if (str)
		check_o_lambda(dt, len, str);
}

/*
**		function to return the right LEN
*/

void		o_length(t_tab *dt, unsigned int len)
{
	dt->len += len - 1;
	if (dt->wi == 0 && dt->pre_i.pre)
	{
		if (dt->pre_i.pre > (int)len)
			dt->len += (dt->pre_i.pre - (len + 1));
		else
			dt->len += (dt->pre_i.pre - (len - 2));
		if (dt->w_i.h_tag)
			dt->len -= 1;
	}
}

/*
**		Conversion %o for octals
*/

void		specifer_o(t_tab *dt)
{
	uintmax_t		nbr;
	unsigned int	len;
	char			*str;

	asterix(dt);
	nbr = check_flag_unsigned(dt);
	str = ft_itoa_b(nbr, 8);
	len = ft_strlen(str);
	if (dt->fr[dt->i] == 'O')
	{
		ft_toupper_str(str, len);
		dt->caps = 1;
	}
	if (dt->w_i.h_tag && nbr == 0)
	{
		dt->w_i.h_tag = 0;
		dt->hash = 1;
	}
	if (dt->w_i.zero && dt->w_i.mi)
		dt->w_i.zero = 0;
	speci_o2(dt, nbr, len, str);
	o_length(dt, len);
	free(str);
}
