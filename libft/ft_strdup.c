/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:03:23 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/30 16:33:46 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		c;

	c = ft_strlen(src) + 1;
	ret = malloc(c * sizeof(*ret));
	if (!ret)
		return (ret);
	c = 0;
	while (src[c])
	{
		ret[c] = src[c];
		c++;
	}
	ret[c] = 0;
	return (ret);
}

/* #include <stdio.h>
int main(void)
{
	char src[] = "Depois uma string longa, tão longa quanto moulinette deixa.";
	char c[] = "Antes";
	char *targ;

	targ = c;
	printf("%s\n", targ);
	targ = ft_strdup(src);
	printf("%s\n", targ);
	return (0);
} */