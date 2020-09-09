/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:15:27 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:20 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void			specifer_d2(t_tab *dt, intmax_t nbr, int len, char *str)
{
	if (str && dt->w_i.sp && !dt->w_i.pl)
	{
		if (dt->w_i.zero)
			check_d_epsilion(dt, nbr, len, str);
		else if (dt->wi && dt->pre)
			check_d_zeta(dt, nbr, len, str);
		else if (dt->wi)
			check_d_eta(dt, nbr, len, str);
		else if (dt->pre)
			check_d_theta(dt, nbr, len, str);
		else
			check_d_iota(dt, nbr, len, str);
		return ;
	}
	specifer_d3(dt, nbr, len, str);
}

void			specifer_d3(t_tab *dt, intmax_t nbr, int len, char *str)
{
	if (str && dt->wi && dt->pre && (dt->w_i.zero || dt->zero))
	{
		if (dt->w_i.mi && dt->w_i.pl)
			check_d_kappa(dt, nbr, len, str);
		else if (dt->w_i.mi)
			check_d_lambda(dt, nbr, len, str);
		else if (dt->w_i.pl)
			check_d_mu(dt, nbr, len, str);
		else
			check_d_nu(dt, nbr, len, str);
		return ;
	}
	specifer_d4(dt, nbr, len, str);
}

void			specifer_d4(t_tab *dt, intmax_t nbr, int len, char *str)
{
	if (str && dt->wi && dt->pre)
	{
		if (dt->w_i.mi && dt->w_i.pl)
			check_d_xi(dt, nbr, len, str);
		else if (dt->w_i.mi)
			check_d_omicron(dt, nbr, len, str);
		else if (dt->w_i.pl)
			check_d_pi(dt, nbr, len, str);
		else
			check_d_rho(dt, nbr, len, str);
	}
	else if (str && dt->pre)
		check_d_sigma(dt, nbr, len, str);
	else if (str && dt->w_i.zero && dt->w_i.pl)
		check_d_tau(dt, nbr, len, str);
	else if (str && dt->w_i.pl && dt->wi)
		check_d_upsilon(dt, nbr, len, str);
	else if (str && dt->w_i.zero)
		check_d_phi(dt, nbr, len, str);
	else if (str)
		check_d_chi(dt, nbr, len, str);
}

/*
**		Conversion %d for bits
*/

void			specifer_d(t_tab *dt)
{
	intmax_t	nbr;
	int			len;
	char		*str;

	asterix(dt);
	nbr = check_flag_signed(dt);
	str = ft_itoa_imax(dt, nbr);
	len = ft_strlen(str);
	if (dt->w_i.zero && dt->w_i.mi)
		check_d_alfa(dt);
	if (dt->wi > (int)ft_strlen(str) + 3 &&
	dt->pre && dt->w_i.sp && !dt->w_i.mi)
		check_d_beta(dt);
	if (dt->pre && dt->pre_i.pre == 0 && nbr == 0)
	{
		check_d_delta(dt, len);
		free(str);
		return ;
	}
	specifer_d2(dt, nbr, len, str);
	dt->len += len - 1;
	dt->len += (nbr < 0 || dt->w_i.pl || dt->w_i.sp) ? 1 : 0;
	free(str);
}
