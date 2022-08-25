/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:17:17 by myyou             #+#    #+#             */
/*   Updated: 2022/06/07 12:41:54 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*result;

	if (alst == NULL || new == NULL)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	result = ft_lstlast(*alst);
	result->next = new;
}
