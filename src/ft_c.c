/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:54:05 by cghael            #+#    #+#             */
/*   Updated: 2020/01/16 13:55:33 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_c(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t)
{
	char	val;
	int		len;
	char	*tmp;

	if (!(tmp = ft_strnew(1)))
		ft_error_exit("Malloc error in ft_c()", buf_t);
	if (tmp_t->spec == '%')
		val = '%';
	else
		val = (char)(int)ft_dollar_arg(tmp_t->dollar[0], ap_t);
	if (val == '\0')
		buf_t->eol_c = 1;
	*tmp = val;
	len = ft_strlen(tmp);
	if (tmp_t->width > len)
	{
		len = tmp_t->width;
		tmp = ft_width_treat(len, tmp, *tmp_t);
		if (tmp_t->minus && buf_t->eol_c == 1)
			buf_t->eol_c = 2;
	}
	buf_t->res = tmp;
	if (buf_t->res == NULL)
		ft_error_exit("Malloc error in ft_c()", buf_t);
}
