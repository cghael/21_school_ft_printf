/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:59:21 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 12:59:22 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_precision_char(const char *val, t_ftptf tmp_t)
{
	char		*tmp;

	if (!(tmp = ft_strnew(tmp_t.precision)))
		ft_error_exit("Malloc error in ft_s()", NULL);
	tmp = ft_strncpy(tmp, val, tmp_t.precision);
	return (tmp);
}

void			ft_s(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t)
{
	char		*tmp;
	char		*val;
	int			len;

	val = (char*)ft_dollar_arg(tmp_t->dollar[0], ap_t);
	if (!val)
		val = "(null)";
	len = ft_strlen(val);
	if (tmp_t->dot > 0 && tmp_t->precision < len)
	{
		tmp = ft_precision_char(val, *tmp_t);
		len = ft_strlen(tmp);
	}
	else if (!(tmp = ft_strdup(val)))
		ft_error_exit("Malloc error in ft_s()", buf_t);
	if (tmp_t->width > len)
	{
		len = tmp_t->width;
		tmp = ft_width_treat(len, tmp, *tmp_t);
	}
	buf_t->res = tmp;
	if (buf_t->res == NULL)
		ft_error_exit("Malloc error in ft_s()", buf_t);
}
