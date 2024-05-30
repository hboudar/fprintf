/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:14:55 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/28 15:34:50 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_menu
{
	va_list	list;
	int		i;
	int		count;
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		precision_1;
	int		lenght;
}			t_menu;

int		ft_fprintf(int fd, const char *str, ...);
int		ft_flags(char *s, t_menu *flags);
void	ft_print_c(int fd, char s, t_menu *menu, int *count, char c);
void	ft_print_di(int fd, long int n, t_menu *menu, int *count, char c);
void	ft_print_s(int fd, char *s, t_menu *menu, int *count, char c);
void	ft_print_u(int fd, unsigned int nbr, t_menu *menu, int *count, char c);
void	ft_print_x(int fd, unsigned int nbr, t_menu *menu, int *count, char c);
void	ft_print_xx(int fd, unsigned int n, t_menu *menu, int *count, char c);
void	ft_print_p(int fd, unsigned long long nbr, t_menu *menu, int *count, char c);
int		ft_write_c(int fd, int c);
void	ft_write_s(int fd, char *s, int *count, t_menu *menu);
void	ft_special_di(int fd, t_menu *menu, int *count);
void	ft_precision_di(int fd, long int n, t_menu *menu, int *count);
void	ft_special_x(int fd, t_menu *menu, int *count);

#endif
