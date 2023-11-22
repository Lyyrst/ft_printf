/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:07 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/22 17:27:17 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_check(char *base)
{
	int	i;
	int	k;

	k = -1;
	i = -1;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[++i])
	{
		if ((base[i] == 43 || base[i] == 45)
			|| (base[i] >= 9 && base[i] <= 13)
			|| base[i] == 32)
			return (0);
		k = 0;
		while (base[++k + i])
		{
			if (base[i] == base[k + i])
				return (0);
		}
	}
	return (1);
}

int	ft_basepos(char n, char *base)
{
	int	count;

	count = -1;
	while (base[++count])
	{
		if (base[count] == n)
			return (count);
	}
	return (count);
}

int	ft_bten(char *nbr, char *b)
{
	int		i;
	int		ret;
	int		l;
	int		p;

	i = -1;
	ret = 0;
	l = 0;
	p = 0;
	while ((nbr[++i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		l++;
	while (nbr[i] == 43 || nbr[i] == 45)
	{
		l++;
		i++;
	}
	while (ft_in_base(nbr[l], b) == 1)
			l++;
	while (nbr[i] && ft_in_base(nbr[i], b) == 1)
	{
		ret += (ft_basepos(nbr[l-- - 1], b) * ft_power(ft_strlen(b), p++));
		i++;
	}
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		count;
	int		bten;
	char	*ret;

	if (!(ft_check(base_from) == 1 && ft_check(base_to) == 1)
		|| (base_from == NULL || base_to == NULL))
		return (NULL);
	count = 0;
	bten = ft_bten(nbr, base_from);
	while ((bten / ft_strlen(base_to)) > 0)
	{
		bten = bten / ft_strlen(base_to);
		count++;
	}
	if (ft_check_sign(nbr, base_from) == 1 || (ft_bten(nbr, base_from) == 0))
	{
		ret = malloc(sizeof(char) * count + 2);
		ret = ft_convert_pos(ret, count + 1, ft_bten(nbr, base_from), base_to);
	}
	else
	{
		ret = malloc(sizeof(char) * count + 3);
		ret = ft_convert_neg(ret, count + 1, ft_bten(nbr, base_from), base_to);
	}
	return (ret);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}*/
