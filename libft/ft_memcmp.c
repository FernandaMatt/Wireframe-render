/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:50:14 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 15:50:41 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((((char *)s1)[i] == ((char *)s2)[i]) && i < n - 1)
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[7] = "laAasd";
	char s2[7] = "laAasd";
	printf("ft_strncmp: %d\n", ft_memcmp(s1, s2, 7));
	printf("   strncmp: %d\n", memcmp(s1, s2, 7));
} */