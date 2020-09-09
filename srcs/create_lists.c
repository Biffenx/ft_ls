/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 06:19:28 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/09/07 08:12:26 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_data			*create_node(char *str)
{
	t_data		*node;

	if (!(node = (t_data *)malloc(sizeof(t_data))))
		error_ls(str, MALL_ERR);
	node->name = str;
	node->next = NULL;
	return (node);
}

void			create_input(t_base *base, t_data *lst, char *str, int d)
{
	t_data		*current;

	if (!lst)
	{
		current = create_node(str);
		if (d == 0)
			base->directory = current;
		else
			base->files = current;
	}
	else
	{
		if (d == 0)
			current = base->directory;
		else
			current = base->files;
		while (current->next != NULL)
			current = current->next;
		current->next = create_node(str);
	}
}

void			create_lists(t_base *base, char **argv)
{
	struct stat	buf;
	size_t		i;
	int			e;

	i = 0;
	e = 0;
	while (argv[i])
	{
		if (stat(argv[i], &buf) != 0)
		{
			error_ls(argv[i], ERRNO);
			e = 1;
		}
		else if (S_ISDIR(buf.st_mode))
			create_input(base, base->directory, argv[i], 0);
		else
			create_input(base, base->files, argv[i], 1);
		i += 1;
	}
	if (!base->directory && !base->files && e != 1)
		create_input(base, base->directory, ".", 0);
	if (base->directory)
		read_lists(base->directory);
	if (base->files)
		read_lists(base->files);
}
