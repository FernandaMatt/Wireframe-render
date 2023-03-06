/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:02:18 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 16:02:28 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((char)c == ((char)((char *)s)[i++]))
			return ((void *)s + --i);
	}
	return (0);
}

/* #include <stdio.h>
int main(void)
{
    char s[] = "qwe\0eretyu";
    int c;
    char *ret;

    c = 'e';
    printf("%s\n", s);
    ret = memchr(s, c, 3);
    printf("%s\n", ret);
    return (0);
} */