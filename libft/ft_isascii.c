/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:01:55 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 16:02:01 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int i;
	unsigned char c;

	i = 0;
	while (i <= 1025)
	{
		c = i;
		if ((isascii(c) != 0 && ft_isascii(c) == 0) || (isascii(c) == 0 &&
		 ft_isascii(c) != 0))
		{
			printf("Error! \nchar {%c} : ascii {%d} ERROR\nisascii:
			 %d\nft_isascii: %d", c, c, isascii(c), ft_isascii(c));
			return (0);
		}
		printf("Char {%c} : {%d} OK\n", c, c);
		i++;
	}
	return (printf("OK!"));
	return (0);
} */