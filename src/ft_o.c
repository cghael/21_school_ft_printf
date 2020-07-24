/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:59:43 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 12:59:43 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_zero(char *tmp, t_ftptf tmp_t)
{
	char		*res;
	size_t		len;

	res = tmp;
	if (tmp_t.octo)
	{
		len = ft_strlen(tmp) + 1;
		res = ft_strnew(len);
		res = ft_memset(res, '0', len);
		ft_strcpy(res + 1, tmp);
		free(tmp);
	}
	return (res);
}

void			ft_o(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t)
{
	void		*val;
	int			len;
	char		*tmp;

	val = ft_dollar_arg(tmp_t->dollar[0], ap_t);
	if ((int)val == 0)
		tmp_t->arg_zero = 1;
	tmp = ft_num_to_str(val, *tmp_t, 0);
	tmp = ft_add_zero(tmp, *tmp_t);
	tmp = ft_precision_treat(tmp, *tmp_t);
	len = ft_strlen(tmp);
	if (tmp_t->width > len)
	{
		len = tmp_t->width;
		tmp = ft_width_treat(len, tmp, *tmp_t);
	}
	buf_t->res = tmp;
	if (buf_t->res == NULL)
		ft_error_exit("Malloc error in ft_x()", buf_t);
}
