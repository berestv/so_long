/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:30:48 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/28 13:51:22 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = start;
	j = 0;
	if (!str)
		return (0);
	if (start >= ft_strlen((char *)str))
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (0);
		substr[0] = 0;
		return (substr);
	}
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (0);
	while (str[i] && j < len)
		substr[j++] = str[i++];
	substr[j] = '\0';
	return (substr);
}
