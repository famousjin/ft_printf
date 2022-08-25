/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:09:33 by myyou             #+#    #+#             */
/*   Updated: 2022/06/07 11:04:50 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	size;
	t_list			*elem;

	size = 0;
	if (lst == NULL)
		return (size);
	elem = lst;
	while (elem != NULL)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}
