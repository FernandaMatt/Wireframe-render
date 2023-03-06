/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:53:47 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 15:53:58 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n > 0)
	{
		ptr[n - 1] = 0;
		n--;
	}
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "String antes da chamada de bzero()";
	char str2[] = "String antes da chamada de ft_bzero()";
	void *ptr;
	void *ptr2;
	int n;
	int i;

	n = 6;
	ptr = &str;
	ptr2 = &str2;
	printf("\n--- Função Original ---\n%s\n", str);
	bzero(ptr, n);
	i = 0;
	while (i < 35)
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n---    Função ft_   ---\n%s\n", str2);
	ft_bzero(ptr2, n);
	i = 0;
	while (i < 35)
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
} */