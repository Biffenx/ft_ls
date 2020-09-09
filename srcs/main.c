/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 06:19:02 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/09/09 07:47:01 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		init_flags(t_base *base)
{
	t_options	*flags;

	base->options = (t_options *)malloc(sizeof(t_options));
	!base->options ? error_ls("", MALL_ERR) : 0;
	flags = base->options;
	flags->cap_c = false;
	flags->cap_r = false;
	flags->cap_s = false;
	flags->cap_t = false;
	flags->a = false;
	flags->i = false;
	flags->l = false;
	flags->n = false;
	flags->o = false;
	flags->r = false;
	flags->t = false;
	flags->one = false;
}

static void		search_flags_alfa(char *str, size_t i, t_options *flags)
{
	str[i] == 'C' ? flags->cap_c = true : 0;
	str[i] == 'R' ? flags->cap_r = true : 0;
	str[i] == 'S' ? flags->cap_s = true : 0;
	str[i] == 'T' ? flags->cap_t = true : 0;
	str[i] == 'a' ? flags->a = true : 0;
	str[i] == 'i' ? flags->i = true : 0;
	str[i] == 'l' ? flags->l = true : 0;
	str[i] == 'r' ? flags->r = true : 0;
	str[i] == 't' ? flags->t = true : 0;
	if (str[i] == 'n' || str[i] == 'o')
	{
		str[i] == 'n' ? flags->n = true : 0;
		str[i] == 'o' ? flags->o = true : 0;
		flags->l = true;
	}
	str[i] == '1' ? flags->one = true : 0;
}

static void		search_flags(t_base *base, char ***argv)
{
	t_options	*flags;
	char		*str;
	size_t		i;

	flags = base->options;
	*argv += 1;
	str = **argv;
	while (str && str[0] == '-')
	{
		i = 1;
		while (str[i])
		{
			if (!ft_strchr(OPTIONS, str[i]))
				error_ls(&str[i], USAGE);
			search_flags_alfa(str, i, flags);
			i += 1;
		}
		*argv += 1;
		str = **argv;
	}
}

static void		sort_argv(char **argv)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
	while (*(argv + i))
	{
		j = i + 1;
		while (*(argv + j))
			if (ft_strcmp(*(argv + i), *(argv + j)) > 0)
			{
				tmp = *(argv + i);
				*(argv + i) = *(argv + j);
				*(argv + j) = tmp;
				continue ;
			}
			else
				j++;
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_base		*base;

	(void)argc;
	base = init_base();
	init_flags(base);
	search_flags(base, &argv);
	sort_argv(argv);
	create_lists(base, argv);
	print(base);
	return (0);
}
