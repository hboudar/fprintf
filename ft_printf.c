/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:12:42 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/28 15:17:35 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(int fd, char format, t_menu *menu, int *count)
{
	if (format == '%')
		ft_print_c(fd, '%', menu, count, ' ');
	else if (format == 'c')
		ft_print_c(fd, va_arg(menu->list, int), menu, count, ' ');
	else if (format == 's')
		ft_print_s(fd, va_arg(menu->list, char *), menu, count, ' ');
	else if (format == 'd' || format == 'i')
		ft_print_di(fd, (int)va_arg(menu->list, int), menu, count, ' ');
	else if (format == 'x')
		ft_print_x(fd, va_arg(menu->list, unsigned int), menu, count, ' ');
	else if (format == 'X')
		ft_print_xx(fd, va_arg(menu->list, unsigned int), menu, count, ' ');
	else if (format == 'p')
		ft_print_p(fd, va_arg(menu->list, unsigned long long), menu, count, ' ');
	else if (format == 'u')
		ft_print_u(fd, va_arg(menu->list, unsigned int), menu, count, ' ');
}

int	ft_printf(int fd, const char *str, ...)
{
	t_menu	menu;

	if (write(fd, "", 0) == -1)
		return (-1);
	va_start(menu.list, str);
	menu.count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			str += ft_flags((char *)str, &menu);
			ft_format(fd, *str, &menu, &menu.count);
		}
		else if (*str != '%')
			menu.count += write(fd, str, 1);
		str++;
	}
	va_end(menu.list);
	return (menu.count);
}
