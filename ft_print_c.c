/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:16:28 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/28 15:18:15 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_c(int fd, int c)
{
	return (write(fd, &c, 1));
}

void	ft_print_c(int fd, char s, t_menu *menu, int *count, char c)
{
	if (menu->width < 1)
		*count += ft_write_c(fd, s);
	else if (menu->minus)
	{
		menu->zero = 0;
		*count += ft_write_c(fd, s);
		while (menu->width-- - 1 > 0)
			*count += ft_write_c(fd, c);
	}
	else
	{
		if (menu->zero)
			c = '0';
		while (menu->width-- - 1 > 0)
			*count += ft_write_c(fd, c);
		*count += ft_write_c(fd, s);
	}
}
