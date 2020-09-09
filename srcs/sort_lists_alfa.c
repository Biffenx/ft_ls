/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lists_alfa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:27:42 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/03 09:56:36 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_data	*sorted_merge_size(t_data *a, t_data *b, t_base *base)
{
	t_data		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->st_size > b->st_size)
		result = a;
	else if (a->st_size == b->st_size)
	{
		if (ft_strcmp(a->name, b->name) < 0)
			result = a;
		else
			result = b;
	}
	else
		result = b;
	if (result == a)
		result->next = sorted_merge_size(a->next, b, base);
	else
		result->next = sorted_merge_size(a, b->next, base);
	return (result);
}

t_data			*merge_sort_size(t_data **files, t_base *base)
{
	t_data		*head;
	t_data		*a;
	t_data		*b;

	head = *files;
	if ((head == NULL) || (head->next == NULL))
		return (*files);
	front_back_split(head, &a, &b);
	merge_sort_size(&a, base);
	merge_sort_size(&b, base);
	*files = sorted_merge_size(a, b, base);
	return (*files);
}
