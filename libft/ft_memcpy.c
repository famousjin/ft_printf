/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:12:33 by myyou             #+#    #+#             */
/*   Updated: 2022/06/07 10:23:15 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	char		*src2;

	dst2 = dst;
	src2 = (char *)src;
	i = 0;
	if (dst2 == src2)
		return (dst2);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
