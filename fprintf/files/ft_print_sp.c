/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:36:10 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/17 22:43:59 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_sign(t_menu *menu)
{
	if (menu->plus)
		menu->count += ft_write_c('+', menu->fd);
	else if (menu->space)
		menu->count += ft_write_c(' ', menu->fd);
}

static void	ft_print_all(t_menu *menu)
{
	if (menu->minus)
	{
		if (menu->plus || menu->space)
			menu->width--;
		ft_print_sign(menu);
		while (menu->lenght-- > 0)
		{
			menu->count += ft_write_c('0', menu->fd);
			menu->width--;
		}
		while (menu->width-- > 0)
			menu->count += ft_write_c(' ', menu->fd);
	}
	else
	{
		if (menu->plus || menu->space)
			menu->width--;
		while (menu->width-- - menu->lenght > 0)
			menu->count += ft_write_c(' ', menu->fd);
		ft_print_sign(menu);
		while (menu->lenght--)
			menu->count += ft_write_c('0', menu->fd);
	}
}

void	ft_special_di(t_menu *menu)
{
	if (!menu->lenght && !menu->width)
	{
		ft_print_sign(menu);
		return ;
	}
	else if (menu->width && !menu->lenght)
	{
		if (menu->minus)
			ft_print_sign(menu);
		if (menu->plus || menu->space)
			menu->width--;
		while (menu->width--)
			menu->count += ft_write_c(' ', menu->fd);
		if (!menu->minus)
			ft_print_sign(menu);
	}
	else if (menu->lenght && !menu->width)
	{
		ft_print_sign(menu);
		while (menu->lenght--)
			menu->count += ft_write_c('0', menu->fd);
	}
	else
		ft_print_all(menu);
}

static void	ft_special_x_p(t_menu *menu)
{
	if (menu->minus)
	{
		while (menu->lenght-- > 0)
		{
			menu->count += ft_write_c('0', menu->fd);
			menu->width--;
		}
		while (menu->width-- > 0)
			menu->count += ft_write_c(' ', menu->fd);
	}
	else
		while (menu->width-- - menu->lenght > 0)
			menu->count += ft_write_c(' ', menu->fd);
	while (menu->lenght-- > 0)
		menu->count += ft_write_c('0', menu->fd);
}

void	ft_special_x(t_menu *menu)
{
	if (!menu->width && !menu->lenght && menu->precision)
		return ;
	else if (!menu->lenght)
	{
		while (menu->width-- > 0)
			menu->count += ft_write_c(' ', menu->fd);
	}
	else
		ft_special_x_p(menu);
}
