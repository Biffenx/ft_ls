/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:16:43 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/08 10:43:58 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	ll_length(t_base *base, t_data *lst)
{
	size_t			len;
	t_data			*current;

	len = 1;
	current = lst;
	while (current)
	{
		len = ft_strchr(current->name, '/') ?
		ft_max(ft_strlen(ft_strrchr(current->name, '/')), len) :
		ft_max(ft_strlen(current->name), len);
		current = current->next;
	}
	len = base->options->i == true ? len + 7 : len;
	return (len);
}

static void	lst_clmn_n(t_base *base, int tmp_clmn, t_index maxlen, t_data *lst)
{
	int				n;

	n = 0;
	if (base->options->i)
		ft_strchr(lst->name, '/') ? ft_printf("%d %s ",
		lst->st_ino, ft_strrchr(lst->name, '/') + 1) :
		ft_printf("%d %s ", lst->st_ino, lst->name);
	else
		ft_strchr(lst->name, '/') ? ft_printf("%s ",
		ft_strrchr(lst->name, '/') + 1) : ft_printf("%s ", lst->name);
	if (tmp_clmn)
	{
		if (base->options->i)
			n = maxlen.x - (ft_strlen(lst->name) + 3);
		else
			n = ft_strchr(lst->name, '/') ? maxlen.x -
			(ft_strlen(ft_strrchr(lst->name, '/'))) :
			maxlen.x - (ft_strlen(lst->name));
		while (n > 0)
		{
			ft_printf(" ");
			n--;
		}
	}
}

static int	lst_clmn(t_base *base, t_data *lst, t_index row_col, t_index maxlen)
{
	int				tmp_clmn;
	int				tmp_row;
	t_data			*lst_tmp;
	int				counter;

	counter = row_col.y;
	while (lst && counter--)
	{
		tmp_clmn = row_col.x;
		lst_tmp = lst->next;
		while (lst && tmp_clmn--)
		{
			lst_clmn_n(base, tmp_clmn, maxlen, lst);
			tmp_row = row_col.y;
			while (lst && tmp_row--)
				lst = lst->next;
		}
		ft_putchar('\n');
		lst = lst_tmp;
	}
	return (1);
}

int			display_basic(t_base *base, t_data *lst)
{
	t_index			maxlen;
	struct ttysize	ts;
	t_index			i;
	t_data			*tmp_lst;

	tmp_lst = lst;
	maxlen.x = ll_length(base, tmp_lst);
	maxlen.y = 0;
	ioctl(0, TIOCGWINSZ, &ts);
	i.x = ((base->options->one)) ? 1 : ts.ts_cols / (maxlen.x + 1);
	i.x = i.x < 1 ? 1 : i.x;
	i.y = 0;
	while (tmp_lst)
	{
		++i.y;
		tmp_lst = tmp_lst->next;
	}
	i.y = (i.y % i.x ? 1 : 0) + (i.y / i.x);
	lst_clmn(base, lst, i, maxlen);
	return (1);
}
