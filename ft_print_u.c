/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:18:21 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/28 15:35:00 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_treat_nbr(int fd, unsigned int nbr, t_menu *menu, int *count, int op)
{
	int	i;

	i = 1;
	if (op == 1)
	{
		while (nbr / 10)
		{
			i++;
			nbr /= 10;
		}
		if (menu->precision && i < menu->lenght)
			return (menu->lenght);
		return (i);
	}
	else if (nbr > 9)
		ft_treat_nbr(fd, nbr / 10, menu, count, 2);
	*count += ft_write_c(fd, "0123456789"[nbr % 10]);
	return (0);
}

static void	ft_treat_flag(int fd, unsigned int *n, t_menu *menu, int *count)
{
	while (menu->lenght-- - ft_treat_nbr(fd, *n, menu, count, 1) > 0)
	{
		*count += ft_write_c(fd, '0');
		(*menu).width--;
	}
}

static void	ft_treat_all(int fd, unsigned int n, t_menu *menu, int *count)
{
	ft_treat_flag(fd, &n, menu, count);
	if (menu->lenght == -1 && n == 0)
		*count += ft_write_c(fd, ' ');
	else
		ft_treat_nbr(fd, n, menu, count, 2);
}

static void	ft_precision(int fd, unsigned int n, t_menu *menu, int *count)
{
	if (menu->width < ft_treat_nbr(fd, n, menu, count, 1))
	{
		ft_treat_flag(fd, &n, menu, count);
		ft_treat_nbr(fd, n, menu, count, 2);
	}
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_all(fd, n, menu, count);
		while (menu->width-- - ft_treat_nbr(fd, n, menu, count, 1) > 0)
			*count += ft_write_c(fd, ' ');
	}
	else
	{
		while (menu->width-- - ft_treat_nbr(fd, n, menu, count, 1) > 0)
			*count += ft_write_c(fd, ' ');
		ft_treat_all(fd, n, menu, count);
	}
}

void	ft_print_u(int fd, unsigned int n, t_menu *menu, int *count, char c)
{
	if (menu->precision && !n && !menu->lenght && !menu->width)
		return ;
	if (menu->precision)
		ft_precision(fd, n, menu, count);
	else if (menu->width < ft_treat_nbr(fd, n, menu, count, 1))
		ft_treat_nbr(fd, n, menu, count, 2);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_nbr(fd, n, menu, count, 2);
		while (menu->width-- - ft_treat_nbr(fd, n, menu, count, 1) > 0)
			*count += ft_write_c(fd, ' ');
	}
	else
	{
		if (menu->zero)
			c = '0';
		while (menu->width-- - ft_treat_nbr(fd, n, menu, count, 1) > 0)
			*count += ft_write_c(fd, c);
		ft_treat_nbr(fd, n, menu, count, 2);
	}
}
