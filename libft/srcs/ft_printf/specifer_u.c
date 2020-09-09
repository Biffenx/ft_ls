/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:25:20 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:34:03 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		Conversion %u for unsigned int
*/

void		specifer_u(t_tab *dt)
{
	uintmax_t		nbr;
	unsigned int	len;
	char			*str;

	asterix(dt);
	nbr = check_flag_unsigned(dt);
	str = ft_itoa_umax(nbr);
	len = ft_strlen(str);
	if (str && dt->wi && dt->pre_i.pre && dt->w_i.mi)
		u_h_zinco(dt, len, str);
	else if (str && dt->wi && dt->pre_i.pre && dt->w_i.zero)
		u_h_qtr(dt, len, str);
	else if ((str && dt->wi && dt->pre_i.pre))
		u_h_duo(dt, len, str);
	else if (str && dt->pre && !dt->pre_i.pre)
		u_h_tre(dt, len, str);
	else if (str)
		u_h_uno(dt, len, str);
	dt->len += (len - 1);
	free(str);
}
