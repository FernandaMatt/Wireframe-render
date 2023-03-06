/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:05:45 by fcaetano          #+#    #+#             */
/*   Updated: 2022/06/09 13:06:18 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src,	size_t destsize)
{
	size_t	dest_count;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	dest_count = 0;
	while (dest[dest_count] && dest_count < destsize)
		dest_count++;
	if (dest_count == destsize)
		return (dest_count + s_len);
	i = 0;
	while (src[i] && i < destsize - dest_count - 1)
	{
		dest[dest_count + i] = src[i];
		i++;
	}
	dest[dest_count + i] = 0;
	return (dest_count + s_len);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
	char dest1[50] = "there is no stars in the sky";
	char dest2[50] = "there is no stars in the sky";
	// ft_memset(src, 'r', 15);
    printf(" --- Função ft_original ---\n");
	printf("Valor retornado: %lu\n", ft_strlcat(dest1, src,
	 ft_strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4));
    printf(" ---  Função original   ---\n");
	printf("Valor retornado: %lu\n", strlcat(dest2,
	 src, ft_strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4));
	printf("ft_original: %s\n\n", dest1);
	printf("original: %s\n\n", dest2);
    return(0);
} */