/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_print_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:48:21 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/07 19:48:22 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_buff_print_free() call function for printing && calc printed chars
** && free buff (ft_bzero();)
*/

void		ft_buff_print_free(t_res *buf_t)
{
	char	*tmp;

	if (!buf_t->p_perc && buf_t->percent_treated == 0)
	{
		ft_buff_print_n_len(buf_t, buf_t->buf);
		ft_buff_print_n_len(buf_t, buf_t->p_tmp);
		ft_buff_free(buf_t);
	}
	else if (buf_t->percent_treated == 1)
	{
		ft_buff_print_n_len(buf_t, buf_t->buf);
		if (!(tmp = ft_strpcpy(buf_t->p_tmp, buf_t->p_perc)))
			ft_error_exit("malloc error", buf_t);
		ft_buff_print_n_len(buf_t, tmp);
		ft_buff_free(buf_t);
		free(tmp);
	}
	else
	{
		ft_buff_print_n_len(buf_t, buf_t->buf);
		ft_buff_print_n_len(buf_t, buf_t->res);
		ft_buff_free(buf_t);
	}
}
