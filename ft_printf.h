/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:05 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/22 18:01:46 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		check_str(const char *str, va_list params);
void	print_str(char c, va_list params, int n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	check_unsigned(int n);
int		ft_strlen(char *str);
int		check_sign(char *nbr);
int		ft_power(int nb, int power);
int		ft_in_base(char c, char *base);
char	*ft_convert_pos(char *ret, int size, int bten, char *base);
char	*ft_convert_neg(char *ret, int size, int bten, char *base);
int		ft_check_sign(char *nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	print_lowerx(int n);
char	*ft_itoa(int n);
void	print_upperx(int n);

#endif