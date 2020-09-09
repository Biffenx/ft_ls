/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:58:24 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/07 10:16:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char		*create_path(const char *dir, const char *name)
{
	size_t		len1;
	size_t		len2;
	size_t		size;
	char		*p;

	len1 = ft_strlen(dir);
	len2 = ft_strlen(name);
	size = len1 + len2 + 2;
	p = (char *)malloc(sizeof(char) * size);
	if (p != NULL)
	{
		ft_memcpy(p, dir, len1);
		if (len1 > 0 && dir[len1 - 1] != '/')
			p[len1++] = '/';
		ft_memcpy(p + len1, name, len2 + 1);
	}
	return (p);
}

static void	base_option_a(t_data *dir)
{
	if (ft_strrchr(dir->name, '/') != 0)
	{
		if (ft_strequ(dir->name, ".") || ft_strequ(dir->name, ".."))
		{
			dir = dir->next;
			return ;
		}
	}
	else if (ft_strequ(ft_strrchr(dir->name, '/') + 1, ".") ||
	ft_strequ(ft_strrchr(dir->name, '/') + 1, ".."))
	{
		dir = dir->next;
		return ;
	}
}

void		recursive(t_base *base, t_data *dir)
{
	t_data	*current;

	current = dir;
	while (dir)
	{
		if (base->options->a)
			base_option_a(dir);
		if (S_ISDIR(dir->st_mode) && dir != NULL &&
		(!(ft_strequ(ft_strrchr(dir->name, '/') + 1, ".") ||
		(ft_strequ(ft_strrchr(dir->name, '/') + 1, "..")))))
		{
			ft_printf("\n");
			ft_printf("%s:\n", dir->name);
			read_dir_rec(base, dir->name);
		}
		dir = dir->next;
	}
}

void		print(t_base *base)
{
	t_data	*current;

	base->files = sort(base, base->files);
	if (base->files)
		base->options->l ? print_long(base, base->files) :
		display_basic(base, base->files);
	if (base->files && base->directory)
		ft_printf("\n");
	if (base->directory)
	{
		base->directory = sort(base, base->directory);
		current = base->directory;
		while (current)
		{
			read_dir(base, current);
			current->next == NULL ? 0 : ft_printf("\n");
			current = current->next;
		}
	}
}
