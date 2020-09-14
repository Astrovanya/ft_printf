/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:15:20 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:18:36 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

char	*ft_is_null(char **num, int size)
{
	int		i;
	char	*dest;
	char	*tmp;

	i = ft_strlen(*num);
	dest = NULL;
	if (i < size)
		dest = ft_fill((size - i), sizeof(char), '0');
	if (*num && (*num)[0] != '-')
	{
		tmp = dest;
		dest = ft_strjoin(dest, *num);
		free_buf(&tmp);
	}
	if (*num && (*num)[0] == '-')
	{
		tmp = dest;
		dest = ft_strjoin(dest, *num + 1);
		free_buf(&tmp);
		tmp = dest;
		dest = ft_strjoin("-", dest);
		free_buf(&tmp);
	}
	free_buf(num);
	return (dest);
}

char	*ft_prec_s(char **num, int size)
{
	int		i;
	char	*dest;
	char	*tmp;

	i = ft_strlen(*num);
	dest = NULL;
	tmp = ft_strdup(*num);
	if (i > size && (*num)[0] != '%')
		tmp[size] = '\0';
	dest = ft_strjoin(dest, tmp);
	if (size == 0 && (*num)[0] != '%')
	{
		free(dest);
		dest = NULL;
	}
	free_buf(&tmp);
	if (*num)
	{
		free(*num);
		*num = NULL;
	}
	return (dest);
}

char	*ft_prec(char **num, int size)
{
	int		i;
	char	*dest;
	char	*tmp;

	i = ft_strlen(*num);
	dest = NULL;
	tmp = ft_strdup(*num);
	if (i < size && *num && (*num)[0] != '-')
		dest = ft_fill((size - i), sizeof(char), '0');
	if (i <= size && *num && (*num)[0] == '-')
		dest = ft_fill((size - i + 1), sizeof(char), '0');
	ft_prec_second(num, tmp, &dest);
	if (size == 0 && (*num)[0] == '0')
		free_buf(&dest);
	free_buf(&tmp);
	free_buf(&(*num));
	return (dest);
}

void	ft_prec_second(char **num, char *tmp, char **dest)
{
	char	*buf;

	if (*num && (*num)[0] != '-')
	{
		buf = *dest;
		*dest = ft_strjoin(*dest, tmp);
		free_buf(&buf);
	}
	if (*num && (*num)[0] == '-')
	{
		buf = *dest;
		*dest = ft_strjoin(*dest, tmp + 1);
		free_buf(&buf);
		buf = *dest;
		*dest = ft_strjoin("-", *dest);
		free_buf(&buf);
	}
}
