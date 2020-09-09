/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 06:44:25 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:43:19 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define UINT_MAX

/*
** 		Used libraries
*/

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include <ctype.h>

/*
**		Colours
*/

# define RED				"\033[0;31m"
# define BOLD_RED			"\033[1;31m"
# define GREEN				"\033[0;32m"
# define BOLD_GREEN			"\033[1;32m"
# define YELLOW				"\033[0;33m"
# define BOLD_YELLOW		"\033[01;33m"
# define BLUE				"\033[0;34m"
# define BOLD_BLUE			"\033[1;34m"
# define MAGNETA			"\033[0;35m"
# define BOLD_MAGNETA		"\033[1;35m"
# define CYAN				"\033[0;36m"
# define BOLD_CYAN			"\033[1;36m"
# define WHITE				"\033[0:37m"
# define WHITE_BOLD			"\033[1:37m"
# define RESET				"\033[0m"

# define BG_RED				"\033[0;31m"
# define BG_BOLD_RED		"\033[1;31m"
# define BG_GREEN			"\033[0;32m"
# define BG_BOLD_GREEN		"\033[1;32m"
# define BG_YELLOW			"\033[0;33m"
# define BG_BOLD_YELLOW		"\033[01;33m"
# define BG_BLUE			"\033[0;34m"
# define BG_BOLD_BLUE		"\033[1;34m"
# define BG_MAGNETA			"\033[0;35m"
# define BG_BOLD_MAGNETA	"\033[1;35m"
# define BG_CYAN			"\033[0;36m"
# define BG_BOLD_CYAN		"\033[1;36m"
# define BG_WHITE			"\033[0:37m"
# define BG_WHITE_BOLD		"\033[1:37m"

# define BOLD				"\033[1m"
# define UL					"\033[4m"
# define REV				"\033[7m"

/*
**		Struct for flags
*/

typedef	struct	s_width
{
	int			h_tag;
	int			zero;
	int			mi;
	int			pl;
	int			sp;
}				t_width;

/*
**		Struct for precision
*/

typedef	struct	s_pre
{
	int			pre;
}				t_pre;

/*
**		Conversion struct
*/

typedef	struct	s_flags
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			ld;

}				t_flags;

/*
**		Main struct
*/

typedef	struct	s_tab
{
	const char	*fr;
	va_list		ap;
	int			wi;
	int			len;
	int			fd;
	int			neg;
	int			zero;
	int			sp;
	int			str_wi;
	int			pre;
	t_width		w_i;
	t_pre		pre_i;
	t_flags		flag_info;
	int			ret;
	int			i;
	int			caps;
	int			hash;
	int			w_asterix;
	int			p_asterix;
	uintmax_t	nbr;
}				t_tab;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
void			initialz(t_tab *dt);
int				parse_format(t_tab *dt);
void			check_specifer(t_tab *dt);
void			check_flags(t_tab *dt);
void			check_precision(t_tab *dt);
void			check_width(t_tab *dt);
size_t			calc_width(t_tab *dt);
void			specifer_s(t_tab *dt);
void			specifer_p(t_tab *dt);
void			c_p_alfa (t_tab *dt, char *ptr, char *ptr_p, unsigned int len);
void			put_ptr_min(t_tab *dt, char *str, int len);
void			put_ptr(t_tab *dt, char *str, int len);
void			put_padd(t_tab *dt, char c, int len);
void			specifer_d(t_tab *dt);
void			specifer_d2(t_tab *dt, intmax_t nbr, int len, char *str);
void			specifer_d3(t_tab *dt, intmax_t nbr, int len, char *str);
void			specifer_d4(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_alfa(t_tab *dt);
void			check_d_beta(t_tab *dt);
void			check_d_delta(t_tab *dt, int len);
void			check_d_epsilion(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_zeta(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_eta(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_theta(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_iota(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_kappa(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_lambda(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_mu(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_nu(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_xi(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_omicron(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_pi(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_rho(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_sigma(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_tau(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_upsilon(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_phi(t_tab *dt, intmax_t nbr, int len, char *str);
void			check_d_chi(t_tab *dt, intmax_t nbr, int len, char *str);
void			specifer_o(t_tab *dt);
void			speci_o2(t_tab *dt, uintmax_t nbr, unsigned int len, char *str);
void			check_o_alfa(t_tab *dt, unsigned int len);
void			check_o_beta(t_tab *dt, unsigned int len);
void			check_o_delta(t_tab *dt, unsigned int len);
void			check_o_epsilon(t_tab *dt, unsigned int len);
void			check_o_zeta(t_tab *dt, unsigned int len, char *str);
void			check_o_eta(t_tab *dt, unsigned int len, char *str);
void			check_o_theta(t_tab *dt, unsigned int len, char *str);
void			check_o_oita(t_tab *dt, unsigned int len, char *str);
void			check_o_xi(t_tab *dt, unsigned int len, char *str);
void			check_o_omicron(t_tab *dt, unsigned int len, char *str);
void			check_o_kappa(t_tab *dt, unsigned int len, char *str);
void			check_o_lambda(t_tab *dt, unsigned int len, char *str);
void			check_o_pi(t_tab *dt, unsigned int len, char *str);
void			o_length (t_tab *dt, unsigned int len);
void			specifer_u(t_tab *dt);
void			specifer_x(t_tab *dt);
void			speci_x2(t_tab *dt, unsigned int len, char *str, char *ltr);
void			check_x_alfa(t_tab *dt, char *ltr, char *str, unsigned int len);
void			check_x_beta(t_tab *dt);
void			x_length(t_tab *dt, unsigned int len);
void			c_x_gamma(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_delta(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_epsilon(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_zeta(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_eta(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_theta(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_oita(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_xi(t_tab *dt, char *ltr, char *str, unsigned int len);
void			c_x_pi(t_tab *dt, char *ltr, char *str, unsigned int len);
void			specifer_c(t_tab *dt);
void			specifer_f(t_tab *dt);
void			specifer_b(t_tab *dt);
void			specifer_percent(t_tab *dt);
char			*ft_itoa_imax(t_tab *dt, intmax_t n);
void			insert_pad(t_tab *dt, int len);
void			insert_pad2(t_tab *dt, int len);
void			insert_pad_zero(t_tab *dt, int len);
void			insert_pad_zero2(t_tab *dt, int len);
void			insert_pad_neg(t_tab *dt, int len);
void			insert_pad_hash(t_tab *dt, int len);
void			insert_float(t_tab *dt, char *str, int len);
void			insert_float_minus(t_tab *dt, char *str, int len);
void			float_padd(t_tab *dt, char c, int len);
char			*zero_fill(char *str, int pre, int len);
char			*fill_zeros(char *str, int p_value, int len);
void			asterix(t_tab *dt);
void			aster(t_tab *dt);
char			calc(char *nbr, size_t k, t_tab *dt);
intmax_t		check_flag_signed(t_tab *dt);
uintmax_t		check_flag_unsigned(t_tab *dt);
long double		conv_double(t_tab *dt);
void			u_h_uno(t_tab *dt, unsigned int len, char *str);
void			u_h_duo(t_tab *dt, unsigned int len, char *str);
void			u_h_tre(t_tab *dt, unsigned int len, char *str);
void			u_h_qtr(t_tab *dt, unsigned int len, char *str);
void			u_h_zinco(t_tab *dt, unsigned int len, char *str);
void			str_h_uno(t_tab *dt, int len, char *str);
char			check_x(t_tab *dt, char *ltr, char *str, unsigned int len);
void			check_length_more_h(t_tab *dt);
void			check_length_more_l(t_tab *dt);

#endif
