/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:59:30 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/16 12:01:22 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_printf() is a recoded stdlib printf() func.
** man 3 printf, bitch!
*/

int				ft_printf(const char *format, ...)
{
	t_arg		ap_t;
	t_res		buf_t;

	if (!format || ft_bzero_buf_n_set_pointers(&buf_t, format))
		ft_error_exit("ft_printf: format string NOT valid\n", &buf_t);
	va_start(ap_t.n_arg, format);
	while (buf_t.p_tmp != buf_t.end)
	{
		if ((buf_t.p_perc = ft_strchr(buf_t.p_tmp, '%')))
		{
			va_start(ap_t.d_wp, format);
			va_start(ap_t.d_arg, format);
			ft_percent_treat(&ap_t, &buf_t);
			va_end(ap_t.d_wp);
			va_end(ap_t.d_arg);
		}
		else
			ft_buff_no_percent(&buf_t);
		if (buf_t.p_tmp++ == buf_t.end)
			break ;
	}
	va_end(ap_t.n_arg);
	return (ft_final_print_n_free_rt_len(&buf_t));
}
