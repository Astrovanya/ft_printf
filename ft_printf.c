/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:59:54 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:26:23 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int		ft_printf(const char *line, ...)
{
	t_list	*container;
	char	*tmp;
	int		ret;
	va_list	arg;

	ret = 0;
	tmp = (char*)line;
	container = new_struct(tmp);
	va_start(arg, line);
	ret = ft_printer(arg, container, 0);
	va_end(arg);
	ft_free_struct(&container);
	return (ret);
}

int		ft_printer(va_list print, t_list *container, int ret)
{
	while (container != NULL)
	{
		if (container->star_w)
			container->width = va_arg(print, int);
		if (container->star_prec == -1)
			container->star_prec = va_arg(print, int);
		if (container->pretext)
			ret += ft_putstr(container->pretext);
		ret += ft_print_from_struct(print, container);
		container = container->next;
	}
	return (ret);
}

int		ft_print_from_struct(va_list print, t_list *container)
{
	int	ret;

	ret = 0;
	if ((container->type > 0 && container->type <= 2) ||
			container->type == 6)
		ret += ft_print_num(va_arg(print, int), container);
	if (container->type == 3)
		ret += ft_print_u(va_arg(print, unsigned int), container);
	if (container->type > 3 && container->type <= 5)
		ret += ft_print_num(va_arg(print, size_t), container);
	if (container->type == 7)
		ret += ft_print_s(va_arg(print, char*), container);
	if (container->type == 8)
		ret += ft_print_p(va_arg(print, size_t), container);
	if (container->type == 9)
		ret += ft_print_percent("%", container);
	return (ret);
}
