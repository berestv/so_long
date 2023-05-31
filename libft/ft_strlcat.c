/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:18:01 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/22 14:53:26 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	a = ft_strlen(dst);
	while (a + 1 < size && src[i] != '\0')
	{
		dst[a] = src[i];
		i++;
		a++;
	}
	dst[a] = '\0';
	return (a + ft_strlen(&src[i]));
}
/* #include <stdio.h>
#include <bsd/string.h>
int main(void)
{
	char dest[] = "rrrrrrrrrrrrrrr";
	char src[] = "Ola";
	char src2[] = "Ola";
	char dest2[] = "Hello";
	int size = 8;
	printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	// printf("%zu\n", strlcat("rrrrrrrrrrrrrr", "lorem ipsum dolor sit amet", 5));
	printf("Dest: %s\n", dest);
	// printf("True Dest: %s", dest2);
	return (0);
} */
