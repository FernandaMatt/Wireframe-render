/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:55:41 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/23 18:25:44 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
		return (ft_strlen((char *)src));
	while (src[i] && i < destsize - 1 && i != destsize)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen((char *)src));
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char string[] = "Fala ai cadete!";
    char buffer[16];
    char buffer2[16];
	size_t size;

	size = 16;
	strlcpy(buffer, string, size);
	printf(" ---  Função original   ---\n%s\n\n", buffer);
	ft_strlcpy(buffer2, string, size);
	printf(" --- Função ft_original ---\n%s\n\n", buffer2);
    return (0);
} */