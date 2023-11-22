/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:47:12 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/22 17:27:00 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_power(int nb, int power)
{
	int	i;
	int	ret;

	i = -1;
	ret = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (++i < power - 1)
	{
		ret *= nb;
	}
	return (ret);
}

int	ft_in_base(char c, char *base)
{
	int	count;

	count = -1;
	while (base[++count])
	{
		if (base[count] == c)
			return (1);
	}
	return (0);
}

int	ft_check_sign(char *nbr, char *base)
{
	int	i;
	int	par;

	i = -1;
	par = 0;
	while (nbr[++i] && (ft_in_base(nbr[i], base) == 0))
	{
		if (nbr[i] == 45)
			par++;
	}
	if ((par % 2) == 0)
		return (1);
	else
		return (0);
}

char	*ft_convert_pos(char *ret, int size, int bten, char *base)
{
	int		i;
	int		j;
	char	temp;

	i = -1;
	temp = 0;
	while (size-- > 0)
	{
		ret[++i] = base[bten % ft_strlen(base)];
		bten = bten / ft_strlen(base);
	}
	i = 0;
	j = ft_strlen(ret) - 1;
	while (i < (ft_strlen(ret) / 2))
	{
		temp = ret[i];
		ret[i] = ret[j];
		ret[j] = temp;
		i++;
		j--;
	}
	ret[size] = 0;
	return (ret);
}

char	*ft_convert_neg(char *ret, int size, int bten, char *base)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	temp = 0;
	ret[0] = '-';
	while (size-- > 0)
	{
		ret[++i] = base[bten % ft_strlen(base)];
		bten = bten / ft_strlen(base);
	}
	i = 0;
	j = ft_strlen(ret) - 1;
	while (i++ < (ft_strlen(ret) / 2))
	{
		temp = ret[i];
		ret[i] = ret[j];
		ret[j--] = temp;
	}
	ret[size] = 0;
	return (ret);
}
