/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:07:11 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 11:19:29 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- Colors Definition --------------------------------
** Use this codes for format all symbols after that expression in output.
** Its work because this work in write() and printf() in shell.
** FORMAT: "\e[0;0;00m"
** '\033' == '\e' - escape
** \e[	- start expression
** 0;0;	- 0 regular; 1 bold; 3 italic font; 4 undelined; 9 crossed out;
** allowed to use several at the same time
** 00	- color by {r; g; b} ... this fuck my brain :(
** m	- end expression
** SIDE EFFECT:
** add some count to output length in ft_printf return();
** For more info see:
** man tput
** Stack Overflow - https://vk.cc/aiVRsC
** https://en.wikipedia.org/wiki/ANSI_escape_code#24-bit
** Templates to use colors:
*/
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"
# define MAG "\e[1;35m"
# define CYN "\e[1;36m"
# define END "\e[m"


/*
** --------------------------- Macros \ Static ---------------------------------
*/

# define FLAGS			"0#-+ "
# define N_SPECS		17
# define SPECS			"%cCspdDiouxXfFegGbrk"
# define PF_BUFF		655
# define FLOAT_BUFF		6000

/*
** -------------------------- External Headers ---------------------------------
*/

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <assert.h>
# include <limits.h>
# include <float.h>
# include <stdint.h>

/*
** ------------------------- Structures Definition -----------------------------
*/

/*
** | 1 bit for sign | 15 bit for exponent | 64 bit for mantis |
*/

typedef struct			s_ufloat
{
	uint64_t			mant : 64;
	unsigned int		expo : 15;
	unsigned int		sign : 1;
}						t_ufloat;

typedef union			u_float
{
	long double			value;
	t_ufloat			number;
}						t_float;

typedef struct			s_fstring
{
	int					int_numb[FLOAT_BUFF + 1];
	int					div_numb[FLOAT_BUFF + 1];
	int					int_len;
	char				*digit_str;
	char				*mant_str;
	int					exp;
}						t_fstring;

/*
** Struct with va_list variables for '$' option
*/

typedef struct			s_arg
{
	va_list				n_arg;
	va_list				d_wp;
	va_list				d_arg;
}						t_arg;

/*
** Struct with buffer, result str, etc
*/

typedef struct			s_res
{
	char				*res;
	int					eol_c;
	char				*p_tmp;
	char				*p_perc;
	char				*end;
	char				buf[PF_BUFF];
	int					len;
	int					percent_treated;
}						t_res;

/*
** Struct with specifier and flags for each percent treatment
*/

typedef struct			s_ftptf
{
	int					percent;
	int					octo;
	int					zero;
	int					minus;
	int					minus_val;
	int					nan;
	int					plus;
	int					spacer;
	int					l;
	int					ll;
	int					l_;
	int					h;
	int					hh;
	char				spec;
	int					base;
	int					width;
	int					dot;
	int					precision;
	int					arg_zero;
	int					dollar[3];
	int					dollar_1_wr;
	int					dollar_2_wr;
	char				sign;
}						t_ftptf;

/*
** Struct for choose the function according to specifier
*/

typedef void			(*t_spec_func)(t_arg*, t_res*, t_ftptf*);

typedef struct			s_type
{
	char				ch;
	t_spec_func			somefunc;
}						t_type;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int						ft_abs(int i);
int						ft_printf(const char *format, ...);
int						ft_parsing(t_arg *ap_t, t_ftptf *tmp_t, t_res *buf_t);
char					*ft_parse_flags(char *p, t_ftptf *ptf_str, t_arg *ap_t);
char					*ft_parse_spec(char *p, t_ftptf *ptf_str);
int						ft_find_in_def(char *define_line, char *p);
char					*ft_strpcpy(char *start, char *end);
void					ft_percent_treat(t_arg *ap_t, t_res *buf_t);
void 					ft_choose_func(t_arg *ap_t, t_res *buf_t, \
							t_ftptf *tmp_t);
void					ft_error_exit(char *str, void *mem);
char					*ft_dollar_treat(char *p, t_ftptf *tmp_t, t_arg *ap_t);
int						ft_isbigger(int a, int b);
char					*ft_strcpy_dptp(char *dst, char *src, char *end);
char					*ft_i64toa_base(long long int n, int base, int l_size);
char					*ft_u64toa_base(unsigned long long int n, int base, \
							int l_size);
char					*ft_width_treat(int len, char *val, t_ftptf tmp_t);
void					*ft_dollar_arg(int n, t_arg *ap_t);
char					*ft_num_to_str(void *val, t_ftptf tmp_t, int l_size);
char					*ft_precision_treat(char *tmp, t_ftptf tmp_t);
int						ft_bzero_buf_n_set_pointers(t_res *buf_t, \
							const char *format);
int						ft_final_print_n_free_rt_len(t_res *buf_t);
void					ft_add_specials(char *res, t_ftptf tmp_t);
char					*ft_exception_treat(t_float res, t_ftptf *tmp_t);
char					*ft_count_float(t_float res, t_ftptf tmp_t);
t_fstring				*ft_get_integer(t_fstring *numb);
t_fstring				*ft_get_divisional(t_fstring *numb);
char					*ft_round_float(t_fstring *numb, t_ftptf tmp_t);
char					*ft_integer_to_str(t_fstring *numb);
t_fstring				*ft_add_dig_to_int(t_fstring *numb);
char					*ft_width_n_precision(char *p, t_ftptf *tmp_t, \
							t_arg *ap_t);

/*
** ---------------- Buffer management functions
*/

void					ft_buff_print_n_len(t_res *buf_t, char *src);
void					ft_buff_free(t_res *buf_t);
void					ft_buff_print_free(t_res *buf_t);
void					ft_buff_finded_percent(t_res *buf_t);
void					ft_buff_treated_percent(t_res *buf_t);
void					ft_buff_no_percent(t_res *buf_t);
void					ft_c(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_s(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_p(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_di(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_o(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_u(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_x(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_f(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_b(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);

#endif
