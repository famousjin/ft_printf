/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:24:41 by myyou             #+#    #+#             */
/*   Updated: 2022/06/07 12:16:14 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	*ft_strtrim(char const *s1, char const *set);
//{
//	size_t	start;
//	size_t	end;
//	char	*str;
//}
int	ft_isin(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

int	ft_findstart(char const *s1, char const *set)
{
	int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (ft_isin(s1[index], set) == 0)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_findend(char const *s1, char const *set)
{
	int	index;

	index = (int)(ft_strlen(s1)) - 1;
	while (index >= 0)
	{
		if (ft_isin(s1[index], set) == 0)
			return (index);
		index--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		index;

	str = NULL;
	index = 0;
	start = ft_findstart(s1, set);
	end = ft_findend(s1, set);
	if (start == -1 || end == -1)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	while (start <= end)
			str[index++] = s1[start++];
	str[index] = '\0';
	return (str);
}
