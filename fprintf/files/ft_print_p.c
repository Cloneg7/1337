/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:20:45 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/17 22:46:04 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_treat_nbr(unsigned long long nbr, t_menu *menu, int op)
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
			ft_treat_nbr(nbr / 16, menu, 2);
		menu->count += ft_write_c("0123456789abcdef"[nbr % 16], menu->fd);
	}
	return (len);
}

static void	ft_treat_flag(unsigned long long nbr, t_menu *menu)
{
	(*menu).lenght = 2;
	ft_write_s("0x", menu);
	if (menu->precision && !nbr)
		return ;
	ft_treat_nbr(nbr, menu, 2);
}

void	ft_print_p(unsigned long long nbr, t_menu *menu, char c)
{
	if (menu->width < ft_treat_nbr(nbr, menu, 1))
		ft_treat_flag(nbr, menu);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(nbr, menu);
		if (menu->precision && !nbr)
			menu->width++;
		while (menu->width-- - ft_treat_nbr(nbr, menu, 1) > 0)
			menu->count += ft_write_c(c, menu->fd);
	}
	else
	{
		if (menu->precision && !nbr)
			menu->width++;
		while (menu->width-- - ft_treat_nbr(nbr, menu, 1) > 0)
			menu->count += ft_write_c(c, menu->fd);
		ft_treat_flag(nbr, menu);
	}
}
