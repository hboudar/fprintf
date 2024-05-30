/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:20:45 by hboudar           #+#    #+#             */
/*   Updated: 2024/05/30 16:08:29 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_treat_nbr(int fd, unsigned long long nbr, int *count, int op)
{
	int	len;

	len = 2;
	if (op == 1)
	{
		if (nbr < 0)
		{
			len++;
			nbr *= -1;
		}
		else if (nbr == 0)
			return (3);
		while (nbr != 0)
		{
			len++;
			nbr /= 16;
		}
	}
	else
	{
		if (nbr > 15)
			ft_treat_nbr(fd, nbr / 16, count, 2);
		*count += ft_write_c(fd, "0123456789abcdef"[nbr % 16]);
	}
	return (len);
}

static void	ft_treat_flag(int fd, unsigned long long nbr, t_menu *menu, int *count)
{
	(*menu).lenght = 2;
	ft_write_s(fd, "0x", count, menu);
	if (menu->precision && !nbr)
		return ;
	ft_treat_nbr(fd, nbr, count, 2);
}

void	ft_print_p(int fd, unsigned long long nbr, t_menu *menu, int *count, char c)
{
	if (menu->width < ft_treat_nbr(fd, nbr, count, 1))
		ft_treat_flag(fd, nbr, menu, count);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(fd, nbr, menu, count);
		if (menu->precision && !nbr)
			menu->width++;
		while (menu->width-- - ft_treat_nbr(fd, nbr, count, 1) > 0)
			*count += ft_write_c(fd, c);
	}
	else
	{
		if (menu->precision && !nbr)
			menu->width++;
		while (menu->width-- - ft_treat_nbr(fd, nbr, count, 1) > 0)
			*count += ft_write_c(fd, c);
		ft_treat_flag(fd, nbr, menu, count);
	}
}
