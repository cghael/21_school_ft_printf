/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:35:40 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/07 19:35:41 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_tmp_del_10(t_fstring *numb, int i)
{
	int					tmp;

	tmp = numb->int_numb[i];
	while (tmp)
	{
		tmp = tmp / 10;
		numb->int_len++;
	}
	return (tmp);
}

static t_fstring		*ft_count_numblen(t_fstring *numb)
{
	int					i;

	i = 0;
	numb->int_len = 0;
	while (numb->int_numb[i] == 0 && i <= FLOAT_BUFF)
		i++;
	if (i > FLOAT_BUFF)
	{
		numb->int_len = 1;
		return (numb);
	}
	ft_tmp_del_10(numb, i);
	i++;
	while (i <= FLOAT_BUFF)
	{
		numb->int_len += 9;
		i++;
	}
	if (numb->int_len == 0)
		numb->int_len = 1;
	return (numb);
}

static void				ft_int_len_pos(t_fstring *numb, char *str)
{
	int					j;

	j = 9;
	while (j && numb->int_len >= 0)
	{
		str[numb->int_len] = '0';
		numb->int_len--;
		j--;
	}
}

static void				ft_int_len_pos_2(int tmp, t_fstring *numb, char *str)
{
	while (tmp && numb->int_len >= 0)
	{
		str[numb->int_len] = tmp % 10 + '0';
		tmp /= 10;
		numb->int_len--;
	}
}

char					*ft_integer_to_str(t_fstring *numb)
{
	int					i;
	char				*str;
	int					tmp;

	i = 0;
	numb = ft_count_numblen(numb);
	if (!(str = (char*)malloc(numb->int_len + 1)))
		ft_error_exit("Error malloc in ft_integer_to_str", NULL);
	str[numb->int_len] = '\0';
	numb->int_len--;
	while (numb->int_len >= 0)
	{
		if (!numb->int_numb[FLOAT_BUFF - i])
		{
			ft_int_len_pos(numb, str);
			i++;
		}
		else
		{
			tmp = numb->int_numb[FLOAT_BUFF - i];
			ft_int_len_pos_2(tmp, numb, str);
			i++;
		}
	}
	return (str);
}
