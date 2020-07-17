/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:57:38 by mleann            #+#    #+#             */
/*   Updated: 2020/07/15 15:05:13 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int		ft_putstr(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\0');
	return (i);
}

int		ft_putchar(char c)
{
	write(0, &c, 1);
	return (1);
}

int		ft_atoi(const char *num)
{
	int			i;
	int			sign;
	long int	res;

	sign = 1;
	res = 0;
	i = 0;
	while (((num[i] >= 9 && num[i] <= 13) || num[i] == ' ') && num)
		i++;
	if (num[i] == '-')
		sign = -1;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i] >= '0' && num[i] <= '9')
	{
		if ((res * 10) < res)
			return ((sign < 0) ? 0 : -1);
		res = res * 10 + (num[i++] - '0');
	}
	return ((int)(res * sign));
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*str;

	l = ft_strlen(s1);
	str = malloc(sizeof(*str) * (l + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < l)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t num, size_t size)
{
	void *ptr;

	ptr = malloc(num * size);
	if (ptr)
		ft_bzero(ptr, (num * size));
	return (ptr);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n > i)
	{
		*((char *)s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;
	int		negative;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 0;
	while (tmp /= 10)
		len++;
	negative = n < 0 ? 1 : 0;
	if (n < 0 && (negative = 1))
		n = -n;
	if (!(res = (char *)malloc(sizeof(char) * ((len += negative + 1) + 1))))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = ((n % 10) + 48);
		n /= 10;
	}
	if (negative)
		res[0] = '-';
	return (res);
}