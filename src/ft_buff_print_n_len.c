/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_print_n_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:27:55 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/21 23:27:57 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_buff_print_n_len() printing result from *src, calculate printed length &
** write it to buf_t->len
*/

void			ft_buff_print_n_len(t_res *buf_t, char *src)
{
	size_t		buf_len;
	char		eol;

	eol = '\0';
	buf_len = ft_strlen(src);
	if (buf_t->eol_c && src != buf_t->buf)
	{
		if (buf_t->eol_c == 1 && buf_len > 0)
			src[buf_len - 1] = eol;
		else if (buf_t->eol_c == 2)
			src[0] = eol;
		else
			buf_len++;
		buf_t->eol_c = 0;
	}
	write(1, src, buf_len);
	buf_t->len += buf_len;
}
