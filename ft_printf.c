/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myyou <myyou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:40:31 by myyou             #+#    #+#             */
/*   Updated: 2022/07/08 12:51:48 by myyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char const *str, va_list ap, int i)
{
	int	print_size;

	print_size = 0;
	if (str[i] == 'c')
		print_size += ft_putchar(va_arg(ap, int));//va_arg는 실제로 값을 가져올 수 있는 매크로! 타입을 정의해 줘서 얼마만큼 정보를 쪼개야할지 계산한다. (int형 4바이트만큼 ap을 입력한다)
	else if (str[i] == 's')
		print_size += ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'p')//포인터의 주소를 출력
	{
		print_size += ft_putstr("0x");
		print_size += ft_puthexmin(va_arg(ap, unsigned long long));
	}
	else if ((str[i] == 'd') || (str[i] == 'i')) //d, i는 부호있는 10진수 정수
		print_size += ft_putnbr(va_arg(ap, int));
	else if ((str[i] == 'u'))//부호없는 10진수 출력
		print_size += ft_putten(va_arg(ap, unsigned int));
	else if ((str[i] == 'x'))
		print_size += ft_puthexmin(va_arg(ap, unsigned int));
	else if ((str[i] == 'X'))
		print_size += ft_puthexmax(va_arg(ap, unsigned int));
	else if ((str[i] == '%'))//%를 쓰기 위해서는 이렇게 써야함. 예를 들어서 "를 쓰려면 중복을 방지하기 위해 \"이렇게 쓰는데 %문자는 \% 이렇게 쓰면 제어문자라고 입력받는다. 그래서 %를 문자라고 %로 한번 더 찍어주는 것.
		print_size += ft_putchar('%');
	return (print_size);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;//va_list는 단지 *char일 뿐! 1바이트의 형태도 4바이트의 형태로 바꿔준다.
	int		print_size;
	int		i;

	va_start(ap, str);//포인터의 주소를 선언해 준다.
	print_size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
				print_size += ft_specifier(str, ap, ++i);
		else
		{
			ft_putchar(str[i]);
			print_size++;
		}
		i++;
	}
	va_end(ap);//NULL문자로 끝내 준다.
	return (print_size);//몇개의 문자가 적혔는지 숫자를 반환해 준다.
}
