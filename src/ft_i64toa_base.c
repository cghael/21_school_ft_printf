/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i64toa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:15:42 by cghael            #+#    #+#             */
/*   Updated: 2020/02/09 14:15:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_memsize(long long int n, int base)
{
	size_t		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static char		*ft_fillnum(char *str, long long int n, \
									size_t size, int base)
{
	unsigned long long int		nb;
	char						*s;

	if (!(s = ft_strdup("0123456789abcdef")))
		return (NULL);
	nb = n;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[--size] = s[nb % base];
		nb = nb / base;
	}
	free(s);
	return (str);
}

/*
** l_size - flag '1' to upper letters in hex base
*/

char			*ft_i64toa_base(long long int n, int base, int l_size)
{
	char		*str;
	size_t		size;
	int			i;

	size = ft_memsize(n, base);
	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	str = ft_fillnum(str, n, size, base);
	i = 0;
	if (l_size == 1)
		while (str[i])
		{
			if (ft_isalpha(str[i]))
				str[i] = (char)ft_toupper(str[i]);
			i++;
		}
	return (str);
}
