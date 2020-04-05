/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:36:51 by cghael            #+#    #+#             */
/*   Updated: 2020/01/21 17:36:53 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_dollar_arg(int n, t_arg *ap_t)
{
	int		i;
	void	*val;

	i = 1;
	val = 0;
	if (n > 0)
		while (i <= n)
		{
			val = va_arg(ap_t->d_arg, void*);
			i++;
		}
	else
		val = va_arg(ap_t->n_arg, void*);
	return (val);
}
