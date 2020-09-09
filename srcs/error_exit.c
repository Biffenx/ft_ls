/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 06:19:16 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/09/06 20:44:57 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_base			*init_base(void)
{
	t_base		*base;

	base = (t_base*)malloc(sizeof(t_base));
	!base ? error_ls("", MALL_ERR) : 0;
	base->directory = NULL;
	base->files = NULL;
	return (base);
}

int				free_list_content(t_data *lst)
{
	while (lst)
	{
		free((lst)->name);
		free(lst);
		lst = (lst)->next;
	}
	return (1);
}

int				error_ls(char *str, int error)
{
	if (error == USAGE)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(*str);
		ft_putchar('\n');
		ft_putendl("usage: ft_ls [-CRSTailnort1] [file ...]");
	}
	else if (error == ERRNO || error == MALL_ERR)
		ft_putstr("ft_ls: ");
	if (error == ERRNO)
	{
		ft_putstr(str);
		ft_putstr(": ");
		ft_putendl(strerror(errno));
	}
	else if (error == ERRNO)
		ft_putendl(strerror(errno));
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);
}

void			delete_list(t_data *lst)
{
	t_data		*p;
	t_data		*store;

	p = lst;
	while (p != NULL)
	{
		store = p->next;
		p->name ? free(p->name) : 0;
		free(p);
		p = store;
	}
	lst = NULL;
}
