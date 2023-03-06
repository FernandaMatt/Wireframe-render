/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:50:56 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 15:51:08 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n > 0)
	{
		ptr[n - 1] = c;
		n--;
	}
	return (s);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "String antes da chamada de memset()";
	char str2[] = "String antes da chamada de ft_memset()";
	void *ptr;
	void *ptr2;

	ptr = &str;
	ptr2 = &str2;
	printf("\n--- Função Original ---\n%s\n", str);
	memset(ptr, 'A', 6);
	printf("%s\n", str);
	printf("\n---    Função ft_   ---\n%s\n", str2);
	ft_memset(ptr2, 'A', 6);
	printf("%s\n\n", str2);
} */