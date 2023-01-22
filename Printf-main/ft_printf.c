/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milhan <milhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:34:53 by milhan            #+#    #+#             */
/*   Updated: 2023/01/22 20:34:56 by milhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long n)
{
	int	ret;
	int	rem;

	ret = 0;
	if (n > 15)
		ret += ft_pointer(n / 16);
	rem = n % 16;
	if (rem >= 0 && rem <= 9)
		ret += ft_putchar(rem + 48);
	else if (rem > 9 && rem < 16)
		ret += ft_putchar (rem + 87);
	return (ret);
}

int	ft_pointer_upper(unsigned long long n)
{
	int	ret;
	int	rem;

	ret = 0;
	if (n > 15)
		ret += ft_pointer_upper (n / 16);
	rem = n % 16;
	if (rem >= 0 && rem <= 9)
		ret += ft_putchar(rem + 48);
	else if (rem > 9 && rem < 16)
		ret += ft_putchar(rem + 55);
	return (ret);
}

int	num(long long n)
{
	int			ret;
	long long	rem;

	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ret += num (n / 10);
	rem = n % 10;
	ret += ft_putchar(rem + 48);
	return (ret);
}

int	func(char *var, va_list lst)
{
	if (*var == 'c')
		return (ft_putchar(va_arg(lst, int)));
	if (*var == 's')
		return (ft_putstr(va_arg(lst, char *)));
	if (*var == 'p')
	{
		ft_putstr("0x");
		return (ft_pointer(va_arg(lst, unsigned long long)) + 2);
	}
	if (*var == 'u')
		return (num(va_arg(lst, unsigned int)));
	if (*var == 'x')
		return (ft_pointer(va_arg(lst, unsigned int)));
	if (*var == 'X')
		return (ft_pointer_upper(va_arg(lst, unsigned int)));
	if (*var == 'd' || *var == 'i')
		return (num(va_arg(lst, int)));
	if (*var == '%')
		return (ft_putchar ('%'));
	return (0);
}

int	ft_printf(const char *var, ...)
{
	int		ret;
	va_list	lst;

	va_start(lst, var);
	ret = 0;
	while (*var)
	{
		if (*(var) == '%')
		{
			var++;
			ret += func((char *)var, lst);
		}
		else
			ret += ft_putchar(*var);
		var++;
	}
	va_end(lst);
	return (ret);
}

// int sum(int num, ...)
// {
// 	int toplam = 0;
// 	va_list ap;
// 	int i;
// 	va_start(ap,num);
// 	for(i = 0;i<num;i++)
// 	{
// 		toplam += va_arg(ap,int);
// 	}
// 	va_end(ap);
// 	return(toplam);
// }
// int main()
// {
// 	int i = 99;
// 	ft_printf("%d",sum(8,1,2,3,4,5,6,7,8));
// 	ft_printf("%i",ft_printf("%i",i));
// }
	