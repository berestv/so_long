/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:43:07 by marvin            #+#    #+#             */
/*   Updated: 2022/11/07 21:43:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	if (n <= 0)
		return (0);
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n > i)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/* #include <string.h>
#include <stdio.h>
int main () {
   char str1[15] = "abcdef";
   char str2[15] = "ABCDEF";
   int ret;

   ret = fr_memcmp(str1, str2, 5);
   printf("%i - ft_memcmp", ret);

   ret = memcmp(str1, str2, 5);
   printf("%i - memcmp", ret);

   return(0);
} */
