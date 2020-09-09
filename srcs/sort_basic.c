/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:48:49 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/06 21:25:46 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_data	*sorted_merge_basic(t_data *a, t_data *b, t_base *base)
{
	t_data		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->name, b->name) < 0)
		result = a;
	else
		result = b;
	if (result == a)
		result->next = sorted_merge_basic(a->next, b, base);
	else
		result->next = sorted_merge_basic(a, b->next, base);
	return (result);
}

t_data			*merge_sort_basic(t_data **files, t_base *base)
{
	t_data		*head;
	t_data		*a;
	t_data		*b;

	head = *files;
	if ((head == NULL) || (head->next == NULL))
		return (*files);
	front_back_split(head, &a, &b);
	merge_sort_basic(&a, base);
	merge_sort_basic(&b, base);
	*files = sorted_merge_basic(a, b, base);
	return (*files);
}
