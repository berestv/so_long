/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:59:26 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/22 13:41:21 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	len;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	aux = malloc(sizeof(char) * (len + 1));
	if (!aux || !s1)
		return (0);
	if (s1 && !s2)
		return ((char *) s1);
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2[a])
		aux[i++] = s2[a++];
	aux[i] = '\0';
	return (aux);
}
/* #include <stdio.h>
int main()
{
	char *s1 = "Hello";
	char *s2 = " world";
	printf("%s", ft_straoin(s1, s2));
	return 0;
} */
