/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:40 by bbento-e          #+#    #+#             */
/*   Updated: 2023/02/06 18:37:56 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(va_list va, char c, int *ri)
{
	if (!c)
		return ;
	if (c == 'c')
		*ri += ft_putchar(va_arg(va, int));
	else if (c == 's')
		*ri += ft_putstr(va_arg(va, char *));
	else if (c == 'p')
		*ri += ft_printaddr(va_arg(va, unsigned long));
	else if (c == 'd' || c == 'i')
		*ri += ft_putnbr(va_arg(va, int));
	else if (c == 'u')
		*ri += ft_putunsg(va_arg(va, unsigned int));
	else if (c == 'x' || c == 'X')
		*ri += ft_puthex(va_arg(va, unsigned int), c);
	else if (c == '%')
		*ri += ft_putchar('%');
}

char	spec_chr(const char str)
{
	int		j;
	char	*c;

	j = 0;
	c = "cspdiuxX%";
	if (!str)
		return (0);
	while (str != c[j] || j <= 9)
		j++;
	if (str == c[j])
		return (c[j]);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ri;
	char	aux;
	va_list	va;

	i = 0;
	ri = 0;
	va_start(va, str);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		aux = spec_chr(str[i + 1]);
		if (str[i] == '%' && aux)
		{
			ft_print(va, aux, &ri);
			i++;
		}
		else
			ri += ft_putchar(str[i]);
		i++;
	}
	return (ri);
}
/* #include <stdio.h>
int main()
{
	int		i = 0;
	char	*prt = NULL;
	char	*s = "Hello world";

	ft_printf("ft_printf: ");
	i = ft_printf("1st %% percentage: %p %s - (I hope this worked)", prt, s);
	printf("\nreturn: %i", i);

	printf("\n\n  Printf : ");
	i = printf("1st %% percentage: %p %s - (I hope this worked)", prt, s);
	printf("\nreturn: %i\n", i);

	return 0;
} */
