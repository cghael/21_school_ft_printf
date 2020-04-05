/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:00:17 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 13:00:18 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_b(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t)
{
	void	*val;
	int		len;
	char	*tmp;

	val = ft_dollar_arg(tmp_t->dollar[0], ap_t);
	if ((int)val == 0)
		tmp_t->arg_zero = 1;
	tmp = ft_num_to_str(val, *tmp_t, 0);
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
