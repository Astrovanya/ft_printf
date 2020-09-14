/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:18:48 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:20:36 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

char	*ft_convert_x(unsigned int number)
{
	unsigned long int	tmp;
	int					i;
	char				*num;

	tmp = number;
	i = 0;
	if (tmp == 0)
		i++;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	num = ft_calloc(i + 1, sizeof(char));
	tmp = number;
	while (i > 0 && tmp >= 0)
	{
		num[i - 1] = (((tmp % 16) > 9) ? tmp % 16 - 10 + 'a' : tmp % 16 + '0');
		tmp = tmp / 16;
		i--;
	}
	if (i > 0)
		num[i - 1] = number;
	return (num);
}

char	*ft_convert_p(size_t number)
{
	unsigned long int	tmp;
	int					i;
	char				*num;

	tmp = number;
	i = 0;
	if (tmp == 0)
		i++;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	num = ft_calloc(i + 1, sizeof(char));
	tmp = number;
	while (i > 0 && tmp >= 0)
	{
		num[i - 1] = (((tmp % 16) > 9) ? tmp % 16 - 10 + 'a' : tmp % 16 + '0');
		tmp = tmp / 16;
		i--;
	}
	if (i > 0)
		num[i - 1] = number;
	return (num);
}

char	*ft_convert_xx(unsigned int number)
{
	unsigned int	tmp;
	int				i;
	char			*num;

	tmp = (unsigned)number;
	i = 0;
	if (tmp == 0)
		i++;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	num = ft_calloc(i + 1, sizeof(char));
	tmp = (unsigned)number;
	while (i > 0 && tmp >= 0)
	{
		num[i - 1] = (((tmp % 16) > 9) ? tmp % 16 - 10 + 'A' : tmp % 16 + '0');
		tmp = tmp / 16;
		i--;
	}
	if (i > 0)
		num[i - 1] = number;
	return (num);
}

int		write_type(char *t)
{
	if (*t == 'd')
		return (1);
	if (*t == 'i')
		return (2);
	if (*t == 'u')
		return (3);
	if (*t == 'X')
		return (4);
	if (*t == 'x')
		return (5);
	if (*t == 'c')
		return (6);
	if (*t == 's')
		return (7);
	if (*t == 'p')
		return (8);
	if (*t == '%')
		return (9);
	return (0);
}

int		type_parser(char **line)
{
	char	*t;

	if (!line || !*line || !**line)
		return (0);
	t = *line;
	if (*t == 'd' || *t == 'i' || *t == 'u' || *t == 'c' || *t == 's' ||
			*t == 'p' || *t == 'x' || *t == 'X' || *t == '%')
	{
		*line = *line + 1;
		return (write_type(t));
	}
	return (0);
}
