/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:55:12 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/19 16:57:21 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_hex(char *hex)
{
	size_t	i;
	size_t	sz;

	sz = ft_strlen(hex);
	if (hex[0] != '0' || hex[1] != 'x' || sz > 8)
		return (0);
	i = 2;
	while (hex[i])
	{
		if (hex[i] > 47 && hex[i] < 58)
			i++;
		else if (hex[i] > 64 && hex[i] < 71)
			i++;
		else if (hex[i] > 60 && hex[i] < 103)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_max(char *str, char *max, char *min)
{
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		max = min;
	}
	if (ft_strlen(str) > 10)
		return (1);
	else if (ft_strlen(str) < 10)
		return (0);
	while (*str && *max)
	{
		if (*str < *max)
			return (0);
		else if (*str == *max)
		{
			str++;
			max++;
		}
		else
			return (1);
	}
	return (0);
}

int	check_int(char *number)
{
	if ((*number == '+' || *number == '-') && ft_strlen(number) > 1)
		number++;
	while (*number)
	{
		if (!ft_isdigit(((int)*number)))
			return (0);
		number++;
	}
	return (1);
}
