/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:38:49 by fcaetano          #+#    #+#             */
/*   Updated: 2022/08/17 17:38:12 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftpf_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return (1);
		s++;
	}
	if ((char)c == *s)
		return (1);
	return (0);
}

int	ftpf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ftpf_putstr(char *s)
{
	if (s == 0)
		return (write(1, "(null)", 6));
	write(1, s, ftpf_strlen(s));
	return (ft_strlen(s));
}

int	ftpf_strlen(const char *str)
{
	int	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}
