/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:30 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 15:49:38 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
		if ((isdigit(c) != 0 && ft_isdigit(c) == 0) || (isdigit(c) == 0 &&
		 ft_isdigit(c) != 0))
		{
			printf("Error! \nchar {%c} : ascii {%d} ERROR\nisdigit:
			 %d\nft_isdigit: %d", c, c, isdigit(c), ft_isdigit(c));
			return (0);
		}
		printf("char {%c} : ascii {%d} OK\n", c, c);
		i++;
	}
	return (printf("OK!"));
	return (0);
} */