/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:18:01 by cghael            #+#    #+#             */
/*   Updated: 2020/01/16 11:44:40 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_choose_cs(t_type func_n_spec[17])
{
	func_n_spec[0].ch = 'c';
	func_n_spec[0].somefunc = &ft_c;
	func_n_spec[1].ch = 'C';
	func_n_spec[1].somefunc = &ft_c;
	func_n_spec[2].ch = '%';
	func_n_spec[2].somefunc = &ft_c;
	func_n_spec[3].ch = 's';
	func_n_spec[3].somefunc = &ft_s;
}

static void		ft_choose_di(t_type func_n_spec[17])
{
	func_n_spec[4].ch = 'd';
	func_n_spec[4].somefunc = &ft_di;
	func_n_spec[5].ch = 'D';
	func_n_spec[5].somefunc = &ft_di;
	func_n_spec[6].ch = 'i';
	func_n_spec[6].somefunc = &ft_di;
}

static void		ft_choose_fg(t_type func_n_spec[17])
{
	func_n_spec[7].ch = 'f';
	func_n_spec[7].somefunc = &ft_f;
	func_n_spec[8].ch = 'F';
	func_n_spec[8].somefunc = &ft_f;
	func_n_spec[9].ch = 'g';
	func_n_spec[9].somefunc = &ft_f;
	func_n_spec[10].ch = 'G';
	func_n_spec[10].somefunc = &ft_f;
}

static void		ft_choose_ouxbp(t_type func_n_spec[17])
{
	func_n_spec[11].ch = 'o';
	func_n_spec[11].somefunc = &ft_o;
	func_n_spec[12].ch = 'u';
	func_n_spec[12].somefunc = &ft_u;
	func_n_spec[13].ch = 'x';
	func_n_spec[13].somefunc = &ft_x;
	func_n_spec[14].ch = 'X';
	func_n_spec[14].somefunc = &ft_x;
	func_n_spec[15].ch = 'b';
	func_n_spec[15].somefunc = &ft_b;
	func_n_spec[16].ch = 'p';
	func_n_spec[16].somefunc = &ft_p;
}

void			ft_choose_func(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t)
{
	int			i;
	t_type		func_n_spec[N_SPECS];

	i = 0;
	ft_choose_cs(func_n_spec);
	ft_choose_di(func_n_spec);
	ft_choose_fg(func_n_spec);
	ft_choose_ouxbp(func_n_spec);
	while (i < N_SPECS)
	{
		if ((*tmp_t).spec == func_n_spec[i].ch)
		{
			func_n_spec[i].somefunc(ap_t, buf_t, tmp_t);
			return ;
		}
		i++;
	}
}
