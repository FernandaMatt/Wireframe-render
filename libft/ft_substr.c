/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:56:37 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/30 14:23:25 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		substr = malloc((ft_strlen(s) - start + 1) * sizeof(*s));
	else
		substr = malloc((len + 1) * sizeof(*s));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}

/* #include <stdio.h>
int main(void)
{
	char s[] = "Hakuna Matata";
	unsigned int start = 7;
	size_t len = 6;
	char *ret;
	int i = 0;

	ret = ft_substr(s, start, len);
	printf("%s\n", ret);
	printf("Printing char by char:\nchar:	");
	while (i <= (int)len)
		printf("%c	", ret[i++]);
	printf("\nint:	");
	i = 0;
	while (i <= (int)len)
		printf("%d	", ret[i++]);
	i = 0;
	printf("\npos:	");
	while (i <= (int)len)
		printf("%d	", i++);
	return (0);
} */