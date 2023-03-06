/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:55:00 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/23 16:33:41 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptrdest;
	const char	*ptrsrc;

	if (!dest && !src)
		return (NULL);
	ptrdest = dest;
	ptrsrc = src;
	while (n > 0)
	{
		ptrdest[n - 1] = ptrsrc[n - 1];
		n--;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
	char csrc[] = "Ousadia e Alegria";
	char cdest[100];
	char csrc1[] = "Ousadia e Alegria";
	char cdest1[100];
	memcpy(cdest, csrc, strlen(csrc)+1);
	ft_memcpy(cdest1, csrc1, strlen(csrc)+1);
	printf("Copied string is (memcpy)	%s\n", cdest);
	printf("Copied string is(ft_memcpy)	%s\n", cdest1);

	int isrc[] = {10, 20, 30, 40, 50};
	int n = sizeof(isrc)/sizeof(isrc[0]);
	int isrc1[] = {10, 20, 30, 40, 50};
	int n1 = sizeof(isrc1)/sizeof(isrc1[0]);
	int idest[n], idest1[n], i;
	memcpy(idest, isrc,  sizeof(isrc));
	ft_memcpy(idest1, isrc1,  sizeof(isrc1));
	printf("\nCopied array is (memcpy)	");
	for (i=0; i<n; i++)
		printf("%d ", idest[i]);
	printf("\nCopied array is (ft_memcpy)	");
	for (i=0; i<n1; i++)
		printf("%d ", idest1[i]);
	printf("\n");
	return 0;
} */