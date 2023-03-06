/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:53:00 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/14 12:40:46 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] && s2[i] && (s1[i] == s2[i]))
		{
			i++;
		}
		c1 = s1[i];
		c2 = s2[i];
		return (c1 - c2);
	}
	else
		return (-1);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[7] = "laAd";
	char s2[7] = "laAd";
	printf("ft_strncmp: %d\n", ft_strcmp(s1, s2));
	printf("   strncmp: %d\n", strcmp(s1, s2));
}*/
