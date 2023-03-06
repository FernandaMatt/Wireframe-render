/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:58:18 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/09 15:58:51 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	is;
	size_t	jt;

	if (*to_find == 0)
		return ((char *)str);
	is = 0;
	jt = 0;
	while (str[is] != '\0' && (is + jt) < len)
	{
		jt = 0;
		while (str[is + jt] == to_find[jt] && (is + jt) < len)
		{
			jt++;
			if (to_find[jt] == 0)
				return (&((char *)str)[is]);
		}
		is++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
    char string1[] = "see FF your FF return FF now FF";
    char string2[] = "FF";
	int len = 31;
    printf("%s\n", ft_strnstr(string1, string2, len));
    // printf("%s\n", strnstr(string1, string2, len));
    return(0);
} */