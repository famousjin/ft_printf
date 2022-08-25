/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:11:29 by myyou             #+#    #+#             */
/*   Updated: 2022/06/07 11:41:31 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;

	if (size != 0 && nmemb * size / size != nmemb)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, nmemb * size);
	return (tmp);
}
