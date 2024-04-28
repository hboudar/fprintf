/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:54:14 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/14 22:13:26 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_flag(char c)
{
	return (c == ' ' || c == '#' || c == '+'
		|| (c >= '0' && c <= '9') || c == '-' || c == '.');
}

static int	ft_check(char c, char c1, char c2)
{
	return ((c == '.' && (c1 == ' ' || c1 == '#' || c1 == '+' || c1 == '-')
			&& (ft_is_flag(c2))) || ((c == '-' || c == '+' || c == ' '
				|| c == '#') && (c1 >= '0' && c1 <= '9')));
}

static int	ft_initialize(t_menu *menu)
{
	(*menu).i = 0;
	(*menu).hash = 0;
	(*menu).space = 0;
	(*menu).plus = 0;
	(*menu).minus = 0;
	(*menu).zero = 0;
	(*menu).width = 0;
	(*menu).precision = 0;
	(*menu).precision_1 = 0;
	(*menu).lenght = 0;
	return (0);
}

int	ft_flags(char *s, t_menu *l)
{
	ft_initialize(l);
	while (s[l->i] && ft_is_flag(s[l->i]))
	{
		l->minus += (s[l->i] == '-');
		l->hash += (s[l->i] == '#');
		l->space += (s[l->i] == ' ');
		l->plus += (s[l->i] == '+');
		l->precision += (s[l->i] == '.');
		l->precision_1 += (s[l->i] == '.');
		l->zero += (s[l->i] == '0' && !l->width && !l->precision_1);
		if (ft_check(s[l->i], s[l->i + 1], s[l->i + 2]))
		{
			l->precision_1 = 0;
			l->width = 0;
		}
		else if (!l->precision_1 && s[l->i] >= '0' && s[l->i] <= '9')
			l->width = (l->width * 10 + s[l->i] - '0')
				* (s[l->i] >= '0' && s[l->i] <= '9');
		else if (l->precision)
			l->lenght = (l->lenght * 10 + s[l->i] - '0')
				* (s[l->i] >= '0' && s[l->i] <= '9');
		l->i++;
	}
	return (l->i);
}
