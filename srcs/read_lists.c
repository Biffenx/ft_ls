/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 11:55:05 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/08 10:33:37 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		init(t_data *current)
{
	current->st_ino = 0;
	current->st_mode = 0;
	current->st_nlink = 0;
	current->st_uid = 0;
	current->st_uid_nbr = 0;
	current->st_gid = 0;
	current->st_gid_nbr = 0;
	current->st_size = 0;
	current->st_blksize = 0;
	current->m_time = 0;
	current->st_blocks = 0;
	current->m_time = 0;
	current->dev_t = 0;
	ft_bzero(current->st_uid_pwname, MAX_LNAME);
	ft_bzero(current->st_gid_grname, MAX_LNAME);
}

static void		input_alfa(struct stat buf, t_data *current)
{
	struct group	*grp;
	struct passwd	*pwd;

	pwd = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);
	if (pwd != NULL)
	{
		ft_memmove(current->st_uid_pwname, pwd->pw_name,
		ft_strlen(pwd->pw_name));
		current->st_uid_nbr = pwd->pw_uid;
		current->pwd = *pwd;
	}
	if (grp != NULL)
	{
		ft_memmove(current->st_gid_grname, grp->gr_name,
		ft_strlen(grp->gr_name));
		current->st_gid_nbr = (getgrgid(buf.st_gid)->gr_gid);
		current->grp = *getgrgid(buf.st_gid);
	}
}

static void		input(t_data *current)
{
	struct stat		buf;

	if (lstat(current->name, &buf) != 0)
	{
		error_ls(current->name, ERRNO);
		return ;
	}
	input_alfa(buf, current);
	current->st_ino = buf.st_ino;
	current->st_mode = buf.st_mode;
	current->st_nlink = buf.st_nlink;
	current->st_uid = &buf.st_uid;
	current->st_gid = &buf.st_gid;
	current->st_size = buf.st_size;
	current->st_blksize = buf.st_blksize;
	current->st_blocks = buf.st_blocks;
	current->m_time = buf.st_mtime;
	current->dev_t = buf.st_rdev;
}

void			read_lists(t_data *lst)
{
	t_data			*current;

	current = lst;
	while (current)
	{
		init(current);
		input(current);
		current = current->next;
	}
}
