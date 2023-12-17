/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:16:28 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/17 22:45:58 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_c(int c, int fd)
{
	return (write(fd, &c, 1));
}

void	ft_print_c(char s, t_menu *menu, char c)
{
	if (menu->width < 1)
		menu->count += ft_write_c(s, menu->fd);
	else if (menu->minus)
	{
		menu->zero = 0;
		menu->count += ft_write_c(s, menu->fd);
		while (menu->width-- - 1 > 0)
			menu->count += ft_write_c(c, menu->fd);
	}
	else
	{
		if (menu->zero)
			c = '0';
		while (menu->width-- - 1 > 0)
			menu->count += ft_write_c(c, menu->fd);
		menu->count += ft_write_c(s, menu->fd);
	}
}
