/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:43:49 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/16 18:10:45 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_parsing()
** RETURN
** buf_t.p_perc -> founded spec
** SIDE EFFECT
** tmp_t fill all parsed flags
*/

int			ft_parsing(t_arg *ap_t, t_ftptf *tmp_t, t_res *buf_t)
{
	char	*tmp;

	if (ft_find_in_def(SPECS, buf_t->p_perc) < 0)
		return (-1);
	tmp = ft_parse_spec(buf_t->p_perc, tmp_t);
	buf_t->p_perc = ft_parse_flags(buf_t->p_perc, tmp_t, ap_t);
	buf_t->p_perc = tmp;
	return (0);
}
