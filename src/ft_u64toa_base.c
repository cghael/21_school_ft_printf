/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:53:39 by cghael            #+#    #+#             */
/*   Updated: 2020/01/22 14:53:41 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_memsize(unsigned long long int n, int base)
{
	size_t		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static char		*ft_fillnum(char *str, unsigned long long int n, \
					size_t size, int base)
{
	char	*s;

	if (!(s = ft_strdup("0123456789abcdef")))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--size] = s[n % base];
		n = n / base;
	}
	free(s);
	return (str);
}

char			*ft_u64toa_base(unsigned long long int n, int base, int l_size)
{
	char		*str;
	size_t		size;
	int			i;

	size = ft_memsize(n, base);
	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	if (!(str = ft_fillnum(str, n, size, base)))
		return (NULL);
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
