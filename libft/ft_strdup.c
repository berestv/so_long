/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:46:23 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/10 12:45:51 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (s[a] != '\0')
		a++;
	aux = (char *)malloc(sizeof(char) * (a + 1));
	if (!aux)
		return (NULL);
	while (i < a)
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
/* #include<stdio.h>
#include<string.h>
int main()
{
	char source[] = "GeeksForGeeks";
	char *target;

	target = ft_strdup(source);
	printf("%s - ft_strdup\n", target);

	target = strdup(source);
	printf("%s - strdup\n", target);
	return 0;
} */
