/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_print_n_free_rt_len.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:34:20 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/23 11:34:22 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_final_print_n_free_rt_len(t_res *buf_t)
{
	ft_buff_print_n_len(buf_t, buf_t->buf);
	return (buf_t->len);
}
