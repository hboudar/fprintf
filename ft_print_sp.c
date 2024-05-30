/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:36:10 by hboudar           #+#    #+#             */
/*   Updated: 2024/05/30 16:08:32 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	ft_print_sign(int fd, t_menu *menu, int *count)
{
	if (menu->plus)
		*count += ft_write_c(fd, '+');
	else if (menu->space)
		*count += ft_write_c(fd, ' ');
}

static void	ft_print_all(int fd, t_menu *menu, int *count)
{
	if (menu->minus)
	{
		if (menu->plus || menu->space)
			menu->width--;
		ft_print_sign(fd, menu, count);
		while (menu->lenght-- > 0)
		{
			*count += ft_write_c(fd, '0');
			menu->width--;
		}
		while (menu->width-- > 0)
			*count += ft_write_c(fd, ' ');
	}
	else
	{
		if (menu->plus || menu->space)
			menu->width--;
		while (menu->width-- - menu->lenght > 0)
			*count += ft_write_c(fd, ' ');
		ft_print_sign(fd, menu, count);
		while (menu->lenght--)
			*count += ft_write_c(fd, '0');
	}
}

void	ft_special_di(int fd, t_menu *menu, int *count)
{
	if (!menu->lenght && !menu->width)
	{
		ft_print_sign(fd, menu, count);
		return ;
	}
	else if (menu->width && !menu->lenght)
	{
		if (menu->minus)
			ft_print_sign(fd, menu, count);
		if (menu->plus || menu->space)
			menu->width--;
		while (menu->width--)
			*count += ft_write_c(fd, ' ');
		if (!menu->minus)
			ft_print_sign(fd, menu, count);
	}
	else if (menu->lenght && !menu->width)
	{
		ft_print_sign(fd, menu, count);
		while (menu->lenght--)
			*count += ft_write_c(fd, '0');
	}
	else
		ft_print_all(fd, menu, count);
}

static void	ft_special_x_p(int fd, t_menu *menu, int *count)
{
	if (menu->minus)
	{
		while (menu->lenght-- > 0)
		{
			*count += ft_write_c(fd, '0');
			menu->width--;
		}
		while (menu->width-- > 0)
			*count += ft_write_c(fd, ' ');
	}
	else
		while (menu->width-- - menu->lenght > 0)
			*count += ft_write_c(fd, ' ');
	while (menu->lenght-- > 0)
		*count += ft_write_c(fd, '0');
}

void	ft_special_x(int fd, t_menu *menu, int *count)
{
	if (!menu->width && !menu->lenght && menu->precision)
		return ;
	else if (!menu->lenght)
	{
		while (menu->width-- > 0)
			*count += ft_write_c(fd, ' ');
	}
	else
		ft_special_x_p(fd, menu, count);
}
