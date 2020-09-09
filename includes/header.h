/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 06:15:29 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/09/09 07:44:23 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdbool.h.html
*/
#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/dir.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <time.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/includes/libft.h"
# define MALLOC_ERROR 1
# define OPTION_ERROR 2
# define USAGE 3
# define ERRNO 4
# define MALL_ERR 5

# define OPTIONS "CRSTailnort1"
# define MAX_LNAME 257

typedef struct			s_options
{
	bool				cap_c;
	bool				cap_r;
	bool				cap_s;
	bool				cap_t;
	bool				a;
	bool				i;
	bool				l;
	bool				n;
	bool				o;
	bool				r;
	bool				t;
	bool				one;
}						t_options;

typedef struct			s_index
{
	int					x;
	int					y;
}						t_index;

typedef struct			s_data
{
	char				*name;
	size_t				st_ino;
	int					st_mode;
	int					st_nlink;
	unsigned int		*st_uid;
	char				st_uid_pwname[MAX_LNAME];
	unsigned int		st_uid_nbr;
	struct passwd		pwd;
	unsigned int		*st_gid;
	char				st_gid_grname[MAX_LNAME];
	unsigned int		st_gid_nbr;
	struct group		grp;
	size_t				st_size;
	size_t				st_blksize;
	long				m_time;
	int					st_blocks;
	size_t				dev_t;
	struct s_data		*next;
}						t_data;

typedef struct			s_base
{
	t_data				*files;
	t_data				*directory;
	t_options			*options;
}						t_base;

void					error_exit(int error, t_base *base);
void					create_lists(t_base *base, char **argv);
void					create_input(t_base *base, t_data *lst,
						char *str, int d);
t_data					*create_node(char *str);
char					*create_path(const char *dir, const char *name);
void					read_lists(t_data *lst);
int						error_ls(char *str, int error);
t_base					*init_base(void);
void					delete_list(t_data *lst);
// void					delete_list_dr(t_base *lst);
int						free_list_content(t_data *lst);
// void					delete_list2(t_base *base);
// void					delete_list_fi(t_base *lst);
/*
** Sort functions
*/
t_data					*sort(t_base *base, t_data *lst);
t_data					*merge_sort_size(t_data **files, t_base *base);
t_data					*merge_sort_basic(t_data **files, t_base *base);
void					front_back_split(t_data *src,
						t_data **f_ref, t_data **b_ref);
/*
** Read dir functions
*/
void					read_dir(t_base *base, t_data *lst);
void					read_dir_rec(t_base *base, char *name);
void					recursive(t_base *base, t_data *dir);
/*
** -l functions
*/
int						width_clmn(t_data *current2, int w[7]);
void					print_long(t_base *base, t_data *lst);
char					file_acl(char path[PATH_MAX]);
char					get_file_mode(int mode);
/*
** Print functions
*/
void					print(t_base *base);
int						display_basic(t_base *base, t_data *lst);

#endif
