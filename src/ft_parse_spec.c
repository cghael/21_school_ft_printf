/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:15:43 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/16 18:10:45 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** di		signed		decimal
** D		signed		decimal			l
** u		unsigned	decimal
** U		unsigned	decimal			l
** o		unsigned	octal
** O		unsigned	octal			l
** x		unsigned	hex (lowercase)
** X		unsigned	hex (uppercase)
** c		int
** C		wint_t						l
** s		char
** S		char*						l
** p		pointer
*/

static int		ft_base_check(t_ftptf *tmp_t)
{
	if (tmp_t->spec == 'x' || tmp_t->spec == 'X' || tmp_t->spec == 'p')
		return (16);
	if (tmp_t->spec == 'o')
		return (8);
	if (tmp_t->spec == 'b')
		return (2);
	else
		return (10);
}

char			*ft_parse_spec(char *p, t_ftptf *tmp_t)
{
	int			i;
	char		*all_spec;

	if (!(all_spec = ft_strdup(SPECS)))
		return (NULL);
	p++;
	while (*p)
	{
		i = 0;
		while (all_spec[i])
		{
			if (all_spec[i] == *p)
			{
				tmp_t->spec = *p;
				tmp_t->base = ft_base_check(tmp_t);
				free(all_spec);
				return (p);
			}
			i++;
		}
		p++;
	}
	free(all_spec);
	return (NULL);
}
