/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:06:19 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 10:41:27 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_is_ll(char *p, t_ftptf *tmp_t)
{
	if (tmp_t->l_)
	{
		p++;
		return (p);
	}
	if (*p == 'l')
	{
		tmp_t->l = 1;
		p++;
	}
	if (*p == 'l')
	{
		tmp_t->l = 0;
		tmp_t->ll = 1;
		p++;
	}
	return (p);
}

static char		*ft_is_l_(char *p, t_ftptf *tmp_t)
{
	if (*p == 'L')
	{
		tmp_t->l = 0;
		tmp_t->ll = 0;
		tmp_t->l_ = 1;
		p++;
	}
	return (p);
}

static char		*ft_is_hh(char *p, t_ftptf *tmp_t)
{
	if (*p == 'h')
	{
		tmp_t->h = 1;
		p++;
	}
	if (*p == 'h')
	{
		tmp_t->h = 0;
		tmp_t->hh = 1;
		p++;
	}
	return (p);
}

static char		*ft_is_flags(char *p, t_ftptf *tmp_t)
{
	while (*p && *p != '\0')
	{
		if ((ft_strchr(FLAGS, *p)) == NULL)
			break ;
		if (*p == '0')
			tmp_t->zero = 1;
		if (*p == '#')
			tmp_t->octo = 1;
		if (*p == '-')
			tmp_t->minus = 1;
		if (*p == '+')
			tmp_t->plus = 1;
		if (*p == ' ')
			tmp_t->spacer = 1;
		p++;
	}
	return (p);
}

/*
** DESCRIPTION
** ft_parse_flags() parse FLAGS from template:
** "%[digit$][FLAGS][width\*\*digit$][.accuracy\*\*digit$][SIZE]type"
** Function take *p; must be pointed on the '%'
** RETURN VALUES
** char *p to last FLAG symbol or NULL if have any errors
** SIDE EFFECTS
** function write all parsed FLAGS into structuretmp_tr
*/

char			*ft_parse_flags(char *p, t_ftptf *tmp_t, t_arg *ap_t)
{
	p++;
	p = ft_dollar_treat(p, tmp_t, ap_t);
	p = ft_is_flags(p, tmp_t);
	p = ft_width_n_precision(p, tmp_t, ap_t);
	if (tmp_t->width < 0)
	{
		tmp_t->minus = 1;
		tmp_t->width = ft_abs(tmp_t->width);
	}
	if (tmp_t->precision < 0)
		tmp_t->dot = 0;
	if (*p == 'l')
		return (p = ft_is_ll(p, tmp_t));
	if (*p == 'h')
		return (p = ft_is_hh(p, tmp_t));
	if (*p == 'L')
		return (p = ft_is_l_(p, tmp_t));
	return (p);
}
