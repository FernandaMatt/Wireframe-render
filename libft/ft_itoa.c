/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:59:58 by fcaetano          #+#    #+#             */
/*   Updated: 2022/06/02 15:30:36 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mod(int n)
{
	if (n >= 0)
		return (n);
	return (n * -1);
}

static int	ft_strsize(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n <= -1 || n >= 1)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ret;

	size = ft_strsize(n);
	ret = malloc((size + 1) * sizeof(char));
	if (!ret)
		return (ret);
	ret[size--] = 0;
	if (n == 0)
		ret[size--] = 0 + '0';
	while (n <= -1 || n >= 1)
	{
		ret[size--] = ft_mod(n % 10) + '0';
		n /= 10;
	}
	if (size == 0)
		ret[size] = '-';
	return (ret);
}

/* #include <stdio.h>
int main(void)
{
	int n = 0;

	printf("%s\n", ft_itoa(n));
} */