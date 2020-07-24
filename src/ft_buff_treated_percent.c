/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_treated_percent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:55:56 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/22 15:55:57 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_buff_treated_percent(t_res *buf_t)
{
	int			buf_len;
	size_t		len;

	buf_t->percent_treated = 2;
	buf_len = ft_strlen(buf_t->buf);
	len = ft_strlen(buf_t->res);
	if ((int)len < (int)(PF_BUFF - buf_len) && !buf_t->eol_c)
	{
		ft_strcpy_dptp(&buf_t->buf[buf_len], buf_t->res, &buf_t->res[len]);
		free(buf_t->res);
		buf_t->res = NULL;
	}
	else
		ft_buff_print_free(buf_t);
	buf_t->percent_treated = 0;
}
