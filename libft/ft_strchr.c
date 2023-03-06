/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:55:20 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/23 17:38:28 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

/* #include <stdio.h>
int main(void)
{
    char s[] = "qweretyu";
    int c;
    char *ret;

    c = 'a';
    printf("%s\n", s);
    ret = ft_strchr(s, c);
    printf("%s\n", ret);
    return (0);
} */