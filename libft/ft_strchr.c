/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:42:03 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/11 15:59:58 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)str;
	while (aux[i] != c)
	{
		if (aux[i] == '\0')
			return (0);
		i++;
	}
	return (aux + i);
}
/* #include <stdio.h>
#include <string.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_strchr(str, ch);
   printf("String after |%c| is - |%s| - Powered by ft_strchr\n", ch, ret);

   ret = strchr(str, ch);
   printf("String after |%c| is - |%s| - Powered by strchr\n", ch, ret);
   return(0);
} */
