/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:37:29 by fcaetano          #+#    #+#             */
/*   Updated: 2022/05/30 16:50:02 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	size_t	len;
	int		end;

	start = 0;
	len = 0;
	if (s1 == NULL)
		return (NULL);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[end]) && end > start)
		end--;
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}

/* #include <stdio.h>
int main(void)
{
	char *s1 = "       ";
	char *set = " ";
	
	printf("%s", ft_strtrim(s1, set));
} */