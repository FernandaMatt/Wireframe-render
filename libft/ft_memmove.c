/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:02:48 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/23 16:40:28 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*tdest;
	char	*tsrc;

	if (!dest && !src)
		return (NULL);
	tdest = dest;
	tsrc = (char *)src;
	if (tdest < tsrc)
	{
		while (len--)
			*tdest++ = *tsrc++;
	}
	else
	{
		tsrc += len - 1;
		tdest += len - 1;
		while (len--)
			*tdest-- = *tsrc--;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Ousadia e Alegria";
    char str1[] = "Ousadia e Alegria";
    char *src = &str[10];
    char *dst = &str[11];
    char *src1 = &str1[10];
    char *dst1 = &str1[11];
    memmove(src, dst, 3);
    ft_memmove(src1, dst1, 3);
    printf("Copied string is (memmove)    %s\n", dst);
    printf("Copied string is(ft_memmove)    %s\n", dst1);
    return 0;
} */