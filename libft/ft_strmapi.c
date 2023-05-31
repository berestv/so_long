/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:23:13 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/22 13:47:21 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		a;
	char	*aux;

	i = 0;
	a = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	aux = malloc(sizeof(char) * i + 1);
	if (!aux)
		return (NULL);
	while (a < i)
	{
		aux[a] = f(a, s[a]);
		a++;
	}
	aux[a] = '\0';
	return (aux);
}
