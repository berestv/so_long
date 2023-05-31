/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:32:00 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/03 18:46:36 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	aux;

	i = 0;
	aux = 0;
	while (src[aux] != '\0')
		aux++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (aux);
}
/* #include <stdio.h>
#include <bsd/string.h>
int main(void)
{
	char src[] = "Hello world";
	char dest[] = "abc";
	char src2[] = "Hello world";
	char dest2[] = "abc";
	printf("Return: %zu\n", ft_strlcpy(dest, src, 5));
	printf("Correct return: %zu\n", strlcpy(dest2, src2, 5));
	printf("Dest value: %s\n", dest);
	printf("Correct dest value: %s", dest2);
	return 0;
}
 */
