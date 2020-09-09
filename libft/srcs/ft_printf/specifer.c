/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:15:53 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:42:48 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		Checks letter
*/

void		check_specifer(t_tab *dt)
{
	if (ft_strchr("%cspdiouxXSOCDUfb", (dt->fr[dt->i])))
	{
		if ((dt->fr[dt->i] == 'c') || (dt->fr[dt->i] == 'C'))
			specifer_c(dt);
		else if ((dt->fr[dt->i] == 's') || (dt->fr[dt->i] == 'S'))
			specifer_s(dt);
		else if (dt->fr[dt->i] == 'p')
			specifer_p(dt);
		else if ((dt->fr[dt->i] == 'd') || (dt->fr[dt->i] == 'i')
				|| (dt->fr[dt->i] == 'D'))
			specifer_d(dt);
		else if ((dt->fr[dt->i] == 'o') || (dt->fr[dt->i] == 'O'))
			specifer_o(dt);
		else if ((dt->fr[dt->i] == 'u') || (dt->fr[dt->i] == 'U'))
			specifer_u(dt);
		else if ((dt->fr[dt->i] == 'x') || (dt->fr[dt->i] == 'X'))
			specifer_x(dt);
		else if (dt->fr[dt->i] == 'f')
			specifer_f(dt);
		else if (dt->fr[dt->i] == '%')
			specifer_percent(dt);
		else if (dt->fr[dt->i] == 'b')
			specifer_b(dt);
	}
	initialz(dt);
}

/*
**		Checks flags
*/

void		check_length(t_tab *dt)
{
	if (dt->fr[dt->i] == 'h')
		check_length_more_h(dt);
	if (dt->fr[dt->i] == 'l')
		check_length_more_l(dt);
	if (dt->fr[dt->i] == 'L')
	{
		dt->flag_info.ld = 1;
		dt->i++;
	}
	if (dt->fr[dt->i] == 'z')
	{
		dt->flag_info.z = 1;
		dt->i++;
	}
	if (dt->fr[dt->i] == 'j')
	{
		dt->flag_info.j = 1;
		dt->i++;
	}
	check_specifer(dt);
}

/*
**		Checks precision
*/

void		check_pre(t_tab *dt)
{
	char	*nbr;
	size_t	k;
	size_t	str_wi;

	k = 0;
	str_wi = calc_width(dt);
	if (!(nbr = (char*)malloc(sizeof(char) * str_wi + 1)))
		exit(-1);
	ft_bzero(nbr, str_wi + 1);
	if (dt->fr[dt->i] == '.')
	{
		dt->pre = 1;
		if (dt->fr[dt->i + 1] == '*')
			aster(dt);
		else
		{
			while (ft_isdigit(dt->fr[dt->i + 1]))
				*nbr = calc(nbr, k, dt);
			dt->pre_i.pre = ft_atoi(nbr);
			dt->i++;
		}
	}
	free(nbr);
	check_length(dt);
}

/*
**		Checks width
*/

void		check_width(t_tab *dt)
{
	char	*num;
	size_t	t;
	size_t	width;

	t = 0;
	width = calc_width(dt);
	if (!(num = (char*)malloc(sizeof(char) * width + 1)))
		exit(-1);
	ft_bzero(num, width + 1);
	if (dt->fr[dt->i] == '*')
	{
		dt->w_asterix = 1;
		dt->i++;
	}
	while (ft_isdigit(dt->fr[dt->i]))
	{
		num[t] = dt->fr[dt->i];
		t++;
		dt->i++;
	}
	dt->wi = ft_atoi(num);
	free(num);
	check_pre(dt);
}

/*
**		Checks flags
*/

void		check_flags(t_tab *dt)
{
	while (ft_strchr("-+0 #", dt->fr[dt->i]))
	{
		if (dt->fr[dt->i] == '#')
			dt->w_i.h_tag = 1;
		else if (dt->fr[dt->i] == '0')
			dt->w_i.zero = 1;
		else if (dt->fr[dt->i] == '-')
			dt->w_i.mi = 1;
		else if (dt->fr[dt->i] == '+')
			dt->w_i.pl = 1;
		else if (dt->fr[dt->i] == ' ')
			dt->w_i.sp = 1;
		dt->i++;
	}
	check_width(dt);
}
