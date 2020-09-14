/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:41:37 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:26:41 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int	ft_print_num(size_t argint, t_list *container)
{
	char	*number;

	if (container->width < 0)
	{
		container->width = -1 * container->width;
		container->flag = 1;
	}
	if (container->type == 5)
		number = ft_convert_x(argint);
	else if (container->type == 4)
		number = ft_convert_xx(argint);
	else if (container->type == 6)
		return (ft_print_c(argint, container));
	else
		number = ft_itoa(argint);
	if ((container->prec == 0 || container->prec < 0) && \
			container->flag == 2)
		number = ft_is_null(&number, container->width);
	if (container->prec && container->prec >= 0)
		number = ft_prec(&number, container->star_prec);
	if (container->flag != 1 && container->width)
		number = ft_width(&number, container->width);
	if (container->flag == 1 && container->width)
		number = ft_width_right(&number, container->width);
	return (ft_putstr(number) + free_buf(&number));
}

int	ft_print_u(unsigned long long argint, t_list *container)
{
	char	*number;
	int		ret;

	number = ft_itoa_long(argint);
	if ((container->prec == 0 || container->star_prec < 0) && \
			container->flag == 2)
		number = ft_is_null(&number, container->width);
	if (container->prec && container->star_prec >= 0)
		number = ft_prec(&number, container->star_prec);
	if (container->flag != 1 && container->width)
		number = ft_width(&number, container->width);
	if (container->flag == 1 && container->width)
		number = ft_width_right(&number, container->width);
	ret = ft_putstr(number);
	if (number)
		free(number);
	return (ret);
}

int	ft_print_s(char *str, t_list *container)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	if (!tmp)
		tmp = ft_strdup("(null)");
	if (container->width < 0)
	{
		container->width = -1 * container->width;
		container->flag = 1;
	}
	if (container->prec && container->star_prec >= 0)
		tmp = ft_prec_s(&tmp, container->star_prec);
	if ((container->prec == 0 || container->star_prec <= 0) && \
			container->flag == 2)
		tmp = ft_is_null(&tmp, container->width);
	if (!container->flag && container->width)
		tmp = ft_width(&tmp, container->width);
	if (container->flag == 1 && container->width)
		tmp = ft_width_right(&tmp, container->width);
	i = ft_putstr(tmp);
	free_buf(&tmp);
	return (i);
}

int	ft_print_p(size_t pointer, t_list *container)
{
	char	*number;
	int		ret;
	char	*buf;

	buf = ft_convert_p(pointer);
	number = ft_strjoin("0x", buf);
	free_buf(&buf);
	if (container->prec == 0 && container->flag == 2)
		number = ft_is_null(&number, container->width);
	if (container->prec && pointer == 0)
		number = ft_strdup("0x");
	if (!container->flag && container->width)
		number = ft_width(&number, container->width);
	if (container->flag == 1 && container->width)
		number = ft_width_right(&number, container->width);
	ret = ft_putstr(number);
	free_buf(&number);
	return (ret);
}

int	ft_print_c(size_t argint, t_list *container)
{
	int		count;
	int		len;

	count = 0;
	if (!container->width)
		count += write(1, &argint, 1);
	if ((len = container->width) && container->flag == 0)
	{
		while (--len > 0)
			count += ft_putchar(' ');
		count += write(1, &argint, 1);
	}
	if ((len = container->width) && container->flag == 1)
	{
		count += write(1, &argint, 1);
		while (--len > 0)
			count += ft_putchar(' ');
	}
	return (count);
}
