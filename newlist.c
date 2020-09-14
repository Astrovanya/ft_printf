/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:46:40 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:21:20 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

t_list	*new_struct(char *line)
{
	t_list		*new;
	t_list		*lst;
	t_list		*tmp;

	lst = NULL;
	while (line && *line)
	{
		tmp = lst;
		new = new_list(&line);
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			lst = new;
	}
	return (lst);
}

t_list	*new_list(char **line)
{
	t_list		*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->pretext = text_parser(line);
	new->flag = flag_parser(line);
	new->width = wigth_parser(line);
	new->star_w = star_w_parser(line);
	if ((new->prec = prec_parser(line)))
		new->star_prec = star_e_parser(line);
	else
		new->prec = 0;
	new->type = type_parser(line);
	new->next = NULL;
	return (new);
}

void	ft_free_struct(t_list **container)
{
	t_list	*tmp;

	if (!container || !*container)
		return ;
	while (*container != NULL)
	{
		tmp = *container;
		if ((*container)->pretext)
			free((*container)->pretext);
		*container = (*container)->next;
		free(tmp);
		tmp = NULL;
	}
}

int		free_buf(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (0);
}

int		star_e_parser(char **line)
{
	int		i;
	char	*tmp;

	if (!line || !*line || !**line)
		return (0);
	tmp = *line;
	i = 0;
	if (tmp && tmp[i])
	{
		if (tmp[i] == '*')
		{
			*line = *line + 1;
			return (-1);
		}
		while (tmp[i] >= '0' && tmp[i] <= '9')
			i++;
		*line = *line + i;
		return (ft_atoi(tmp));
	}
	return (0);
}
