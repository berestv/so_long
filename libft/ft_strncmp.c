/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:03:05 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/11 12:43:20 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((str1[i] != '\0' && str2[i] != '\0') && (i < n))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
/* #include <stdio.h>
#include <string.h>

int main ()
{
   char str1[15] = "abcdef";
   char str2[15] = "ABCDEF";
   int ret;

   ret = ft_strncmp(str1, str2, 4);
   printf("ft_strncmp: %i\n", ret);

   ret = strncmp(str1, str2, 4);
   printf("strncmp: %i\n", ret);

   return(0);
} */
