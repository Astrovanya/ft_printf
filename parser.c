/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:44:00 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:21:24 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

char	*text_parser(char **line)
{
	int		i;
	char	*text;

	if (!line || !*line || !**line)
		return (0);
	i = 0;
	text = ft_strdup(*line);
	while (text && text[i])
	{
		if (text[i] == '%')
		{
			text[i] = '\0';
			*line = *line + i + 1;
			if (i == 0)
			{
				free_buf(&text);
				return (NULL);
			}
			else
				return (text);
		}
		i++;
	}
	*line = *line + i;
	return (text);
}

int		flag_parser(char **line)
{
	int		i;
	char	*tmp;
	int		rez;
	int		minus;
	int		zero;

	i = 0;
	rez = 0;
	zero = 0;
	minus = 0;
	if (!line || !*line || !**line)
		return (0);
	tmp = *line;
	if (tmp && (*tmp == '-' || *tmp == '0'))
		while (*tmp && (tmp[i] == '-' || tmp[i] == '0'))
		{
			if (tmp[i] == '-' && minus++ == 0)
				rez = rez + 1 - 2 * zero;
			if (tmp[i] == '0' && zero++ == 0 && minus == 0)
				rez = rez + 2;
			i++;
		}
	*line = *line + i;
	return (rez);
}

int		wigth_parser(char **line)
{
	int		i;
	char	*tmp;

	if (!line || !*line || !**line)
		return (0);
	i = 0;
	tmp = *line;
	if (tmp && *tmp >= '0' && *tmp <= '9')
	{
		while (tmp[i] >= '0' && tmp[i] <= '9')
			i++;
		*line = *line + i;
		return (ft_atoi(tmp));
	}
	return (0);
}

int		star_w_parser(char **line)
{
	char	*tmp;

	if (!line || !*line || !**line)
		return (0);
	tmp = *line;
	if (tmp && *tmp == '*')
	{
		*line = *line + 1;
		return (1);
	}
	return (0);
}

int		prec_parser(char **line)
{
	int		i;
	char	*tmp;

	if (!line || !*line || !**line)
		return (0);
	tmp = *line;
	i = 0;
	if (tmp && tmp[i] == '.')
	{
		i++;
		*line = *line + i;
		return (1);
	}
	return (0);
}
