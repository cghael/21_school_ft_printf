/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:30:55 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/21 23:30:55 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_buff_free() call ft_bzero to clear buf_t->buf
*/

void			ft_buff_free(t_res *buf_t)
{
	size_t		buf_len;

	buf_len = ft_strlen(buf_t->buf);
	ft_bzero(buf_t->buf, buf_len);
}
