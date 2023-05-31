/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:53:24 by bbento-e          #+#    #+#             */
/*   Updated: 2022/11/22 14:01:44 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*aux;

	n = 0;
	if (!lst)
		return (0);
	aux = lst;
	while (aux->next != NULL)
	{
		aux = aux->next;
		n++;
	}
	if (aux->next == NULL)
		n++;
	return (n);
}
