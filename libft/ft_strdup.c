/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:13:00 by myyou             #+#    #+#             */
/*   Updated: 2022/06/07 11:39:41 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*pt;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	pt = (char *) malloc(sizeof(char) * (len + 1));
	if (!pt)
		return (NULL);
	while (i < len)
	{	
		pt[i] = src[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
