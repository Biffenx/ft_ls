/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 07:32:09 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:33:01 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		Conversion %c for bits
*/

void		specifer_c(t_tab *dt)
{
	int		var;

	asterix(dt);
	var = va_arg(dt->ap, int);
	if (dt->fr[dt->i] == 'C')
		var -= 32;
	if (dt->w_i.mi == 0)
	{
		insert_pad(dt, 1);
		write(dt->fd, &var, 1);
	}
	else if (dt->w_i.mi == 1)
	{
		write(dt->fd, &var, 1);
		insert_pad(dt, 1);
	}
}
