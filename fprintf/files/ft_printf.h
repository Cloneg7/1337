/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:14:55 by hboudar           #+#    #+#             */
/*   Updated: 2023/12/17 22:48:46 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_menu
{
	int		fd;
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
int		ft_flags(char *s, t_menu *flags, int fd);
void	ft_print_c(char s, t_menu *menu, char c);
void	ft_print_di(long int n, t_menu *menu, char c);
void	ft_print_s(char *s, t_menu *menu, char c);
void	ft_print_u(unsigned int nbr, t_menu *menu, char c);
void	ft_print_x(unsigned int nbr, t_menu *menu, char c);
void	ft_print_xx(unsigned int n, t_menu *menu, char c);
void	ft_print_p(unsigned long long nbr, t_menu *menu, char c);
int		ft_write_c(int c, int fd);
void	ft_write_s(char *s, t_menu *menu);
void	ft_special_di(t_menu *menu);
void	ft_precision_di(long int n, t_menu *menu);
void	ft_special_x(t_menu *menu);

#endif
