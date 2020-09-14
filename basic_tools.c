/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:57:38 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:17:38 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int		ft_putchar(int c)
{
	if (c)
		return (write(1, &c, 1));
	return (0);
}

int		ft_putstr(char *s)
{
	int i;
	int	ret;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	ret = write(1, s, i);
	return (ret);
}

int		ft_atoi(char *str)
{
	int				i;
	int				znak;
	unsigned long	rez;

	i = 0;
	znak = 1;
	rez = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == 127)
		i++;
	if (str[i] == '-')
		znak = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((rez * 10 + (str[i] - '0')) < rez)
			return (znak == 1 ? -1 : 0);
		rez = (rez * 10) + (str[i] - '0');
		i++;
	}
	rez = rez * znak;
	return ((int)rez);
}

char	*ft_strjoin(char *l1, char *l2)
{
	char	*buf;
	int		i;

	if (!l1 && !l2)
		return (NULL);
	buf = (char*)malloc((ft_strlen(l1) + ft_strlen(l2) + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	while (l1 && *l1)
		buf[i++] = *l1++;
	while (l2 && *l2)
		buf[i++] = *l2++;
	buf[i] = '\0';
	return (buf);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char*)malloc(num * size);
	if (!dest)
		return (NULL);
	while (i < ((num - 1) * size))
	{
		dest[i] = 0;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
