/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_treat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:51:31 by cghael            #+#    #+#             */
/*   Updated: 2020/01/16 18:46:54 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_agr_dollar(t_ftptf *tmp_t, t_arg *ap_t)
{
	int			val;
	int			i;
	int			j;

	j = 1;
	i = ft_isbigger(tmp_t->dollar[1], tmp_t->dollar[2]);
	while (j <= i)
	{
		val = va_arg(ap_t->d_wp, int);
		if (j == tmp_t->dollar[1] && !tmp_t->dollar_1_wr)
		{
			tmp_t->dollar[1] = val;
			tmp_t->dollar_1_wr = 1;
		}
		if (j == tmp_t->dollar[2] && !tmp_t->dollar_2_wr)
		{
			tmp_t->dollar[2] = val;
			tmp_t->dollar_2_wr = 1;
		}
		j++;
	}
}

static void		ft_check_stars_n_dollars(char *tmp, t_ftptf *tmp_t, t_arg *ap_t)
{
	tmp_t->dollar[0] = ft_atoi(tmp);
	tmp = ft_strchr(tmp, '$');
	while (*tmp != tmp_t->spec)
	{
		while (*tmp != '*' && *tmp != tmp_t->spec)
		{
			if (*tmp == '.')
				tmp_t->dot = 1;
			tmp++;
		}
		if (*tmp == '*')
		{
			if (tmp_t->dot)
				tmp_t->dollar[2] = ft_atoi(++tmp);
			else
				tmp_t->dollar[1] = ft_atoi(++tmp);
		}
		else
			break ;
		tmp++;
	}
	ft_agr_dollar(tmp_t, ap_t);
}

char			*ft_dollar_treat(char *p, t_ftptf *tmp_t, t_arg *ap_t)
{
	char		*tmp;

	tmp = p;
	while (*p != tmp_t->spec)
	{
		if (*p == '$')
		{
			ft_check_stars_n_dollars(tmp, tmp_t, ap_t);
			return (++p);
		}
		p++;
	}
	return (tmp);
}
