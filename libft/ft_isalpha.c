/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:54:17 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 15:54:22 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	while (i <= 255)
	{
		c = i;
		if ((isalpha(c) != 0 && ft_isalpha(c) == 0) || (isalpha(c) == 0 &&
		 ft_isalpha(c) != 0))
		{
			printf("Error! \nchar {%c} : ascii {%d} ERROR\nisalpha:
			 %d\nft_isalpha: %d", c, c, isalpha(c), ft_isalpha(c));
			return (0);
		}
		printf("char {%c} : ascii {%d} OK\n", c, c);
		i++;
	}
	return (printf("OK!"));
	return (0);
} */