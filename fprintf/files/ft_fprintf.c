/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:12:42 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/17 22:48:05 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(char format, t_menu *menu)
{
	if (format == '%')
		ft_print_c('%', menu, ' ');
	else if (format == 'c')
		ft_print_c(va_arg(menu->list, int), menu, ' ');
	else if (format == 's')
		ft_print_s(va_arg(menu->list, char *), menu, ' ');
	else if (format == 'd' || format == 'i')
		ft_print_di((int)va_arg(menu->list, int), menu, ' ');
	else if (format == 'x')
		ft_print_x(va_arg(menu->list, unsigned int), menu, ' ');
	else if (format == 'X')
		ft_print_xx(va_arg(menu->list, unsigned int), menu, ' ');
	else if (format == 'p')
		ft_print_p(va_arg(menu->list, unsigned long long), menu, ' ');
	else if (format == 'u')
		ft_print_u(va_arg(menu->list, unsigned int), menu, ' ');
}

int	ft_fprintf(int fd, const char *str, ...)
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
			str += ft_flags((char *)str, &menu, fd);
			ft_format(*str, &menu);
		}
		else if (*str != '%')
			menu.count += write(fd, str, 1);
		str++;
	}
	va_end(menu.list);
	return (menu.count);
}
