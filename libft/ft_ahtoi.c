/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:20:04 by fcaetano          #+#    #+#             */
/*   Updated: 2023/01/16 11:20:07 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cathnbr(char *str)
{
	unsigned int	c;
	unsigned int	mult;
	int				result;
	int				n;

	c = ft_strlen(str);
	mult = 1;
	result = 0;
	while (c > 0)
	{
		if (str[c - 1] >= '0' && str[c - 1] <= '9')
			n = str[c - 1] - '0';
		else if (str[c - 1] > 64 && str[c - 1] < 71)
			n = str[c - 1] - 55;
		else
			n = str[c - 1] - 87;
		result += n * mult;
		mult *= 16;
		c--;
	}
	return (result);
}

int	ft_ahtoi(char *str)
{
	int	result;

	result = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			result = -1;
		str++;
	}
	result *= ft_cathnbr(str);
	return (result);
}
