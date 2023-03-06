/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:06:20 by fcaetano          #+#    #+#             */
/*   Updated: 2022/06/03 15:53:53 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/*
void	ft_toupper(unsigned int i, char* c)
{
	i = 0;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}
#include <stdio.h>
int main(void)
{
	char *str = "teste";

	ft_striteri(str, ft_toupper);
	printf("%s", str);
	return (0);	
}
*/