/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milhan <milhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:35:38 by milhan            #+#    #+#             */
/*   Updated: 2023/01/22 20:35:40 by milhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *var)
{
	int	i;

	if (!var)
		return (ft_putstr("(null)"));
	i = 0;
	while (var[i] != '\0')
		ft_putchar(var[i++]);
	return (i);
}
