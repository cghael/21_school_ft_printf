/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_finded_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:51:36 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/22 15:51:40 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_buff_finded_percent(t_res *buf_t)
{
	int		buf_len;

	buf_t->percent_treated = 1;
	buf_len = (int)ft_strlen(buf_t->buf);
	if ((buf_t->p_perc - buf_t->p_tmp) < (PF_BUFF - buf_len))
		ft_strcpy_dptp(&buf_t->buf[buf_len], buf_t->p_tmp, buf_t->p_perc);
	else
		ft_buff_print_free(buf_t);
	buf_t->p_tmp = buf_t->p_tmp + ft_strlen(buf_t->p_tmp);
	buf_t->percent_treated = 0;
}
