/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:54:40 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/23 16:43:31 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int i;
	char c;

	i = 0;
	while (i <= 255)
	{
		c = i;
		if ((isprint(c) != 0 && ft_isprint(c) == 0) || (isprint(c) ==
		 0 && ft_isprint(c) != 0))
		{
			printf("Erro! Divergência no char: {%c} : {%d}\n", c, c);
			return (0);
		}
		printf("Char {%c} : {%d} OK\n", c, c);
		i++;
	}
	return (printf("OK!"));
	return (0);
} */