/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_buf_n_set_pointers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:13:20 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/23 11:13:21 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_bzero_buf_n_set_pointers(t_res *buf_t, const char *format)
{
	ft_bzero(buf_t, sizeof(t_res));
	buf_t->p_tmp = (char *)format;
	buf_t->end = &buf_t->p_tmp[ft_strlen(buf_t->p_tmp)];
	return (0);
}
