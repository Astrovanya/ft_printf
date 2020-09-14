/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:09:45 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:25:21 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

size_t					ft_strlen(const char *str)
{
	size_t				i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char					*ft_strdup(const char *str)
{
	char				*dest;
	int					i;

	i = 0;
	if (!str)
		return (NULL);
	dest = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char					*ft_itoa(int n)
{
	size_t				len;
	char				*res;
	int					negative;
	int					tmp;

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

char					*ft_itoa_long(long long n)
{
	unsigned int		size;
	unsigned long long	temp;
	int					sign;
	char				*dest;

	if (!n)
		return (ft_strdup("0"));
	if (n == LLONG_MIN)
		return (ft_strdup("−9223372036854775808"));
	sign = n > 0 ? 1 : -1;
	temp = n * sign;
	size = n < 0 ? 2 : 1;
	while ((n /= 10))
		size++;
	if (!(dest = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	if (sign < 0)
		dest[0] = '-';
	size--;
	while (temp)
	{
		dest[size--] = temp % 10 + '0';
		temp /= 10;
	}
	return (dest);
}
