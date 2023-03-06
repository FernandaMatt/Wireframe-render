/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:03:47 by fcaetano          #+#    #+#             */
/*   Updated: 2022/06/09 12:33:35 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
		n++;
	return (n);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char string[] = "Hello world! Cachaça";

	printf("Função original:	%ld\n", strlen(&string[0]));
	printf("Função ft:		%ld\n", ft_strlen(&string[0]));
} */
