/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:46:23 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/28 15:27:02 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_count_nbr(int fd, long int nbr, int *count, int op)
{
	int	i;

	if (op == 1)
	{
		i = 1;
		if (nbr < 0)
			nbr *= -1;
		while (nbr / 10)
		{
			i++;
			nbr /= 10;
		}
		return (i);
	}
	else if (nbr > 9)
		ft_count_nbr(fd, nbr / 10, count, 2);
	*count += ft_write_c(fd, "0123456789"[nbr % 10]);
	return (0);
}

static int	ft_treat_nbr(long int nbr, t_menu *menu)
{
	int	i;

	i = 1;
	if ((menu->plus || menu->space) && nbr >= 0)
		i++;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr / 10)
	{
		i++;
		nbr /= 10;
	}
	if (menu->lenght > i)
		return (menu->lenght);
	return (i);
}

static void	ft_treat_flag(int fd, long int *n, t_menu *menu, int *count)
{
	if ((*n < 0 || menu->plus || menu->space))
	{
		if (*n < 0)
		{
			*n *= -1;
			*count += ft_write_c(fd, '-');
		}
		else if (menu->plus)
			*count += ft_write_c(fd, '+');
		else if (menu->space)
			*count += ft_write_c(fd, ' ');
		menu->width--;
	}
	while (menu->lenght-- - ft_count_nbr(fd, *n, count, 1) > 0)
	{
		*count += ft_write_c(fd, '0');
		menu->width--;
	}
	ft_count_nbr(fd, *n, count, 2);
	menu->width -= ft_count_nbr(fd, *n, count, 1);
}

void	ft_precision_di(int fd, long int n, t_menu *menu, int *count)
{
	if (menu->width < ft_treat_nbr(n, menu))
		ft_treat_flag(fd, &n, menu, count);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(fd, &n, menu, count);
		while (menu->width-- > 0)
			*count += ft_write_c(fd, ' ');
	}
	else
	{
		if ((n < 0 || menu->plus || menu->space)
			&& menu->lenght > ft_count_nbr(fd, n, count, 1))
			menu->width--;
		while (menu->width-- - ft_treat_nbr(n, menu) > 0)
			*count += ft_write_c(fd, ' ');
		ft_treat_flag(fd, &n, menu, count);
	}
}
