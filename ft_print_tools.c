/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:23:30 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:26:09 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int		ft_print_percent(char *str, t_list *container)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	if (container->width < 0)
	{
		container->width = -1 * container->width;
		container->flag = 1;
	}
	if (container->flag == 2)
		tmp = ft_is_null(&tmp, container->width);
	if (container->prec && container->star_prec >= 0)
		tmp = ft_prec_s(&tmp, container->star_prec);
	if (!container->flag && container->width)
		tmp = ft_width(&tmp, container->width);
	if (container->flag == 1 && container->width)
		tmp = ft_width_right(&tmp, container->width);
	i = ft_putstr(tmp);
	if (tmp)
		free(tmp);
	return (i);
}

void	*ft_fill(size_t num, size_t size, char c)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char*)malloc((num + 1) * size);
	if (!dest)
		return (NULL);
	while (i < num * size)
	{
		dest[i] = c;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_width_right(char **num, int size)
{
	int		i;
	char	*dest;
	char	*tmp;

	i = ft_strlen(*num);
	dest = NULL;
	if (i < size)
		dest = ft_fill((size - i), sizeof(char), ' ');
	tmp = dest;
	dest = ft_strjoin(*num, dest);
	free_buf(&tmp);
	if (*num)
	{
		free(*num);
		*num = NULL;
	}
	return (dest);
}

char	*ft_width(char **num, int size)
{
	int		i;
	char	*dest;
	char	*tmp;

	i = ft_strlen(*num);
	dest = NULL;
	if (i < size)
		dest = ft_fill((size - i), sizeof(char), ' ');
	tmp = dest;
	dest = ft_strjoin(dest, *num);
	free_buf(&tmp);
	if (*num)
	{
		free(*num);
		*num = NULL;
	}
	return (dest);
}
