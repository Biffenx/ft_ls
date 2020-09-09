/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 07:50:11 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/09 07:46:47 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static	void	read_dir_alfa(t_base *base,
t_data *dir, t_data *current)
{
	read_lists(dir);
	dir = merge_sort_basic(&dir, base);
	dir = sort(base, dir);
	if (current->next || base->files)
		ft_printf("%s:\n", current->name);
	else if (current->next == NULL && ft_strcmp(current->name, "."))
		ft_printf("%s:\n", current->name);
	base->options->l ? print_long(base, dir) : display_basic(base, dir);
	base->options->cap_r == true ? recursive(base, dir) : 0;
	delete_list(dir);
}

static t_data	*create_dir_input(t_data *lst, char *str)
{
	t_data		*current;

	if (!lst)
	{
		current = create_node(str);
		lst = current;
	}
	else
	{
		current = lst;
		while (current->next != NULL)
			current = current->next;
		current->next = create_node(str);
	}
	return (lst);
}

static t_data	*read_dir_a(t_base *base, t_data *dir,
struct dirent *entry, char *dir_main)
{
	char		*path;

	path = create_path(dir_main, entry->d_name);
	if (!base->options->a && !ft_strncmp(ft_strrchr(path, '/') + 1, ".", 1))
		free(path);
	if (base->options->a == true)
		dir = create_dir_input(dir, path);
	else if (entry->d_name[0] != '.')
		dir = create_dir_input(dir, path);
	return (dir);
}

void			read_dir_rec(t_base *base, char *name)
{
	t_data			*rid;
	DIR				*dr;
	struct dirent	*entry;

	rid = NULL;
	dr = opendir(name);
	if (dr == NULL)
		error_ls(name, 0);
	while (dr == NULL)
	{
		error_ls(name, ERRNO);
		return ;
	}
	while ((entry = readdir(dr)) != NULL)
		rid = read_dir_a(base, rid, entry, name);
	closedir(dr);
	read_lists(rid);
	rid = merge_sort_basic(&rid, base);
	rid = sort(base, rid);
	base->options->l ? print_long(base, rid) : display_basic(base, rid);
	recursive(base, rid);
	delete_list(rid);
}

void			read_dir(t_base *base, t_data *lst)
{
	t_data			*current;
	t_data			*dir;
	DIR				*dr;
	struct dirent	*entry;

	dir = NULL;
	current = lst;
	dr = opendir(current->name);
	if (dr == NULL)
		error_ls(current->name, 0);
	while (dr == NULL)
	{
		error_ls(current->name, ERRNO);
		return ;
	}
	while ((entry = readdir(dr)) != NULL)
		dir = read_dir_a(base, dir, entry, current->name);
	closedir(dr);
	read_dir_alfa(base, dir, current);
}
