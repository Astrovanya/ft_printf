/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:44:00 by mleann            #+#    #+#             */
/*   Updated: 2020/07/16 23:30:20 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

char		type_parser(char **format)
{
	char	*t;

	if (!format || !*format || !**format)
		return (0);
	t = *format;
	if (*t == 'd' || *t == 'i' || *t == 'u' || *t == 'c' || *t == 's' ||
			*t == 'p' || *t == 'x' || *t == 'X' || *t == '%')
	{
		*format = *format + 1;
		return (*t);
	}
	return (0);
}

int		prec_parser(char **format)
{
	int		i;
	char	*tmp;

	if (!format || !*format || !**format)
		return (0);
	tmp = ft_strdup(*format);
	i = 0;
	if (tmp && tmp[i] == '.')
	{
		i++;
	}
	if (tmp && tmp[i])
	{
		if (tmp[i] == '*')
		{
			*format = *format + 1;
			return (-1);
		}
		while (tmp[i] >= '0' && tmp[i] <= '9')
			i++;
		*format = *format + i;
		return (ft_atoi(++tmp));
	}
	return (0);
}

int		wigth_parser(char **format)
{
	int		i;
	char	*tmp;

	if (!format || !*format || !**format)
		return (0);
	i = 0;
	tmp = *format;
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		i++;
		//*format = *format + i;
		//return (ft_atoi(tmp));
	}
	if (tmp && tmp[i] == '*')
	{
		*format = *format + i;
		return (-1);
	}
	*format = *format + i;
	return (ft_atoi(tmp));
}

// возвращает 1 если минус и 2 если ноль
int		flag_parser(char **line)
{
	int		i;
	char	*tmp;
	int		zero;
	int		minus;

	i = 0;
	zero = 0;
	minus = 0;
	if (!line || !*line || !**line)
		return (0);
	tmp = *line;
	while (tmp && (tmp[i] == '-' || tmp[i] == '0'))
		{
			if (tmp[i] == '-')
				minus++;
			if (tmp[i] == '0')
				zero++;
			i++;
		}
	*line = *line + i;
	return (returner(minus, zero));
}

int		returner(int minus, int zero)
{
	if (minus > 0)
		return (1);
	else if (zero > 0)
		return (2);
	else
		return (0);
}

char	*text_parser(char **line)
{
	int i;
	char *tmp;

	if (!line || !*line)
		return (0);
	tmp = ft_strdup(*line);
	i = 0;
	while (tmp[i] && tmp[i] != '%')
		i++;
	if (tmp[i] == '%')
	{
		tmp[i] = '\0';
		i++;
	}
	*line = *line + i;
	return (tmp);
}