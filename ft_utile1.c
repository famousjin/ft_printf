/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:03:50 by myyou             #+#    #+#             */
/*   Updated: 2022/07/08 13:06:18 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)//%c
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)//%d
{
    if (!s)
    {
        write(1, "(null)", ft_strlen("(null)"));//널문자로 반환하지 않으면 중국어가 출력됨...!
        return (ft_strlen("(null)"));
    }
    write(1, s, strlen(s));
    return (ft_strlen(s));
}

size_t  ft_strlen(const char *s)//size_t는 각 시스템의 bit안에서 가장 큰 unsigned int타입을 담을 수 있는 유형!
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_puthexmin(unsigned long long nb)//%p
{
    static int  i;//정적 변수. 초기화 하지 않아도 0이 나온다. 이 경우에는 내부정적변수. 다음 함수를 시작했을 때 마지막 값을 기억하고 있다! 그냥 int i = 0이었으면 계속 0 0 0 static int i = 0 이면 0 1 2

    i = 0;
    if (nb >= 16)
            ft_puthexmin(nb / 16);
    ft_putchar("0123456789abcdef"[nb % 16]);
    i++;
    return (i);
}

