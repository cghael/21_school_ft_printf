/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_treat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:51:08 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/16 11:44:35 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_percent_treat() use tmp_t structure to calculate result %spec with flags
** width, precision and other ft_pruntf features.
** Take 2 structure buf_t for writing result and tmp_t to temporary FLAGS & etc
** LOGICAL STEPS:
** null tmp_t
** parsing flags
** call right ft_specs*() function, who calculate result & save it to buf_t->res
*/

void			ft_percent_treat(t_arg *ap_t, t_res *buf_t)
{
	t_ftptf		tmp_t;

	ft_buff_finded_percent(buf_t);
	ft_bzero(&tmp_t, sizeof(t_ftptf));
	if (ft_parsing(ap_t, &tmp_t, buf_t) < 0)
		return ;
	ft_choose_func(ap_t, buf_t, &tmp_t);
	buf_t->p_tmp = buf_t->p_perc;
	ft_buff_treated_percent(buf_t);
	free(buf_t->res);
}
