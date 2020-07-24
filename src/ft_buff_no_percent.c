/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_no_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:51:50 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/14 16:51:52 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_buff_no_percent() takes buf_t, copy to buf_t->buf data from buf_t->p_tmp
** and print it IF DATA bigger than buffer.
** SIDE EFFECT
** calculating printed chars in ft_buff_print_free() -> ft_buff_print_n_len()
*/

void			ft_buff_no_percent(t_res *buf_t)
{
	int			buf_len;
	size_t		len;

	buf_len = ft_strlen(buf_t->buf);
	len = ft_strlen(buf_t->p_tmp);
	if ((int)len < (int)(PF_BUFF - buf_len))
		ft_strcpy_dptp(&buf_t->buf[buf_len], buf_t->p_tmp, &buf_t->p_tmp[len]);
	else
		ft_buff_print_free(buf_t);
	buf_t->p_tmp = buf_t->p_tmp + ft_strlen(buf_t->p_tmp);
}
