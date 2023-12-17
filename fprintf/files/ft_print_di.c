/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:52:22 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/17 22:46:01 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_treat_nbr(long int nbr, t_menu *menu, int operator)
{
	int	i;

	i = 1;
	if (operator == 1)
	{
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
		return (i);
	}
	else if (nbr > 9)
		ft_treat_nbr(nbr / 10, menu, 2);
	menu->count += ft_write_c("0123456789"[nbr % 10], menu->fd);
	return (0);
}

static void	ft_treat_flag(long int *n, t_menu *menu)
{
	if (!menu->zero && (*n < 0 || menu->plus || menu->space))
	{
		if (*n < 0)
		{
			*n *= -1;
			menu->count += ft_write_c('-', menu->fd);
			if (!menu->space && !menu->plus)
				(*menu).width--;
		}
		else if (menu->plus)
			menu->count += ft_write_c('+', menu->fd);
		else if (menu->space)
			menu->count += ft_write_c(' ', menu->fd);
	}
	ft_treat_nbr(*n, menu, 2);
}

static void	ft_flag(long int *n, t_menu *menu, char *c)
{
	if (menu->zero)
	{
		*c = '0';
		if (*n < 0)
		{
			menu->count += ft_write_c('-', menu->fd);
			*n *= -1;
			if (!menu->space && !menu->plus)
				menu->width--;
		}
		else if (menu->plus)
			menu->count += ft_write_c('+', menu->fd);
		else if (menu->space)
			menu->count += ft_write_c(' ', menu->fd);
	}
}

void	ft_print_di(long int n, t_menu *menu, char c)
{
	if (!n && menu->precision)
		ft_special_di(menu);
	else if (menu->precision)
		ft_precision_di(n, menu);
	else if (menu->width <= ft_treat_nbr(n, menu, 1))
	{
		menu->zero = 0;
		ft_treat_flag(&n, menu);
	}
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(&n, menu);
		while (menu->width-- - ft_treat_nbr(n, menu, 1) > 0)
			menu->count += ft_write_c(' ', menu->fd);
	}
	else
	{
		ft_flag(&n, menu, &c);
		while (menu->width-- - ft_treat_nbr(n, menu, 1) > 0)
			menu->count += ft_write_c(c, menu->fd);
		ft_treat_flag(&n, menu);
	}
}
