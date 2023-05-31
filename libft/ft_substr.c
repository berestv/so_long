/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:30:48 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	a;
	size_t	i;

	i = 0;
	a = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && a < len)
		{
			sub[a] = s[i];
			a++;
		}
		i++;
	}
	sub[a] = '\0';
	return (sub);
}
/* #include <stdio.h>
int main()
{
	char *s = "Hello world";
	printf("%s", ft_substr(s, 6, 5));
	return 0;
} */
