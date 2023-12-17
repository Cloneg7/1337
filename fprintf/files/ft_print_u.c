/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:18:21 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/17 22:44:15 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_treat_nbr(unsigned int nbr, t_menu *menu, int op)
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
		ft_treat_nbr(nbr / 10, menu, 2);
	menu->count += ft_write_c("0123456789"[nbr % 10], menu->fd);
	return (0);
}

static void	ft_treat_flag(unsigned int *n, t_menu *menu)
{
	while (menu->lenght-- - ft_treat_nbr(*n, menu, 1) > 0)
	{
		menu->count += ft_write_c('0', menu->fd);
		(*menu).width--;
	}
}

static void	ft_treat_all(unsigned int n, t_menu *menu)
{
	ft_treat_flag(&n, menu);
	if (menu->lenght == -1 && n == 0)
		menu->count += ft_write_c(' ', menu->fd);
	else
		ft_treat_nbr(n, menu, 2);
}

static void	ft_precision(unsigned int n, t_menu *menu)
{
	if (menu->width < ft_treat_nbr(n, menu, 1))
	{
		ft_treat_flag(&n, menu);
		ft_treat_nbr(n, menu, 2);
	}
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_all(n, menu);
		while (menu->width-- - ft_treat_nbr(n, menu, 1) > 0)
			menu->count += ft_write_c(' ', menu->fd);
	}
	else
	{
		while (menu->width-- - ft_treat_nbr(n, menu, 1) > 0)
			menu->count += ft_write_c(' ', menu->fd);
		ft_treat_all(n, menu);
	}
}

void	ft_print_u(unsigned int n, t_menu *menu, char c)
{
	if (menu->precision && !n && !menu->lenght && !menu->width)
		return ;
	if (menu->precision)
		ft_precision(n, menu);
	else if (menu->width < ft_treat_nbr(n, menu, 1))
		ft_treat_nbr(n, menu, 2);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_nbr(n, menu, 2);
		while (menu->width-- - ft_treat_nbr(n, menu, 1) > 0)
			menu->count += ft_write_c(' ', menu->fd);
	}
	else
	{
		if (menu->zero)
			c = '0';
		while (menu->width-- - ft_treat_nbr(n, menu, 1) > 0)
			menu->count += ft_write_c(c, menu->fd);
		ft_treat_nbr(n, menu, 2);
	}
}
