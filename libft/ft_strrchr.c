/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:53:46 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/10 12:43:27 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*aux;

	aux = (char *)str;
	i = 0;
	while (aux[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (aux[i] == c)
			return (aux + i);
		i--;
	}
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '\0';
   char *ret;

   ret = ft_strrchr(str, ch);
   printf("String after |%c| is - |%s| - Powered by ft_strrchr\n", ch, ret);

   ret = strrchr(str, ch);
   printf("String after |%c| is - |%s| - Powered by strrchr\n", ch, ret);

   return(0);
} */
