/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:41:37 by mleann            #+#    #+#             */
/*   Updated: 2020/07/16 23:34:08 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int		ft_print_u(unsigned int n, t_list struc)
{
	int res;
	int zeros;
	int max;
	res = 0;
	zeros = struc.prec - ft_strlen(ft_itoa(n));
	max = ft_strlen(ft_itoa(n)) > struc.prec ? ft_strlen(ft_itoa(n)) : struc.prec;
	max = struc.width - max;
	while (max-- > 0 && struc.flag == 0)
		res += ft_putchar(' ');
	while (max-- > 0 && struc.flag == 2 && struc.prec == 0)
		res += ft_putchar('0');
	while (zeros-- > 0)
		res += ft_putchar('0');
	res += ft_putstr(ft_itoa(n));
	while (max-- > 0 && struc.flag == 1)
		res += ft_putchar(' ');
	return (res);
}

int		ft_print_i_d(int n, t_list struc)
{
	int res;
	int zeros;
	int max;

	res = 0;
	zeros = struc.prec - ft_strlen(ft_itoa(n));
	max = ft_strlen(ft_itoa(n)) > struc.prec ? ft_strlen(ft_itoa(n)) : struc.prec;
	max = struc.width - max;
	while (max > 0 && struc.flag == 0)
	{
		res += ft_putchar(' ');
		max--;
	}
	while (max > 0 && struc.flag == 2 && struc.prec == 0)
	{
		res += ft_putchar('0');
		max--;
	}
	while (zeros-- > 0)
		res += ft_putchar('0');
	res += ft_putstr(ft_itoa(n));
	while (max > 0 && struc.flag == 1)
	{
		res += ft_putchar(' ');
		max--;
	}
	return (res);
}

int		ft_print_p(size_t p, t_list struc)
{
	int		len;
	size_t	p2;
	char	*line;
	char	*result;

	len = 1;
	p2 = p;
	while (p2 /= 16)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	line = ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = line[p % 16];
		p /= 16;
	}
	len = ft_strlen(result);
	ft_putstr("0x");
	ft_putstr(result);
	return (len);
}

int		ft_print_x(unsigned int x, t_list struc)
{
	char *str;
	int res;
	int zeros;
	int max;

	str = ft_x_convert(x);
	res = 0;
	zeros = struc.prec - ft_strlen(str);
	max = ft_strlen(str) > struc.prec ? ft_strlen(str) : struc.prec;
	max = struc.width - max;
	while (max-- > 0 && struc.flag == 0)
		res += ft_putchar(' ');
	while (max-- > 0 && struc.flag == 2 && struc.prec == 0)
		res += ft_putchar('0');
	while (zeros-- > 0)
		res += ft_putchar('0');
	res += ft_putstr(str);
	while (max-- > 0 && struc.flag == 1)
		res += ft_putchar(' ');
	return (res);
}

char	*ft_x_convert(unsigned int number)
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

int		ft_print_xx(unsigned int x, t_list struc)
{
	char *str;
	int res;
	int zeros;
	int max;

	str = ft_xx_convert(x);
	res = 0;
	zeros = struc.prec - ft_strlen(str);
	max = ft_strlen(str) > struc.prec ? ft_strlen(str) : struc.prec;
	max = struc.width - max;
	while (max-- > 0 && struc.flag == 0)
		res += ft_putchar(' ');
	while (max-- > 0 && struc.flag == 2 && struc.prec == 0)
		res += ft_putchar('0');
	while (zeros-- > 0)
		res += ft_putchar('0');
	res += ft_putstr(str);
	while (max-- > 0 && struc.flag == 1)
		res += ft_putchar(' ');
	return (res);
}

char	*ft_xx_convert(unsigned int number)
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
		num[i - 1] = (((tmp % 16) > 9) ? tmp % 16 - 10 + 'A' : tmp % 16 + '0');
		tmp = tmp / 16;
		i--;
	}
	if (i > 0)
		num[i - 1] = number;
	return (num);
}

int		ft_print_c(size_t c, t_list struc)
{
	int		res;
	int		len;
	int i;

	res = 0;
//	if (!struc.width && struc.width == 1)
//		res += write(1, &c, 1);
	if (struc.width > 1)
  	{
 		i = struc.width - 1;
   		while (i > 0 && struc.flag == 0)
		{
     		len += ft_putchar(' ');
			i--;
		}
   		ft_putchar(c);
   		while (i && struc.flag == 1)
		{
     		len += ft_putchar(' ');
			i--;
		}
  	}
  	else
 	ft_putchar(c);
	return (res);
}
/*
int		ft_print_s(char *s, t_list struc)
{
	int len;
	int i;
	char *tmp;

	tmp = ft_strdup(s);
	if (struc.prec && struc.prec < ft_strlen(tmp))
		tmp[struc.prec] = '\0';
	len = ft_strlen(tmp);
	i = 0;
	if (struc.width)
		i = struc.width - len;
	while (i-- > 0 && struc.flag == 0)
		len += ft_putchar(' ');
	ft_putstr(tmp);
	while (i-- && struc.flag == 1)
		len += ft_putchar(' ');
	return (len);
}
*/
int		ft_print_s(char *s, t_list struc)
{
	int len;
	int i;
	char *tmp;
	if (!s)
		return (0);
	tmp = ft_strdup(s);
	if (struc.prec && struc.prec < ft_strlen(tmp))
    	tmp[struc.prec] = '\0';
  	len = ft_strlen(tmp);
  	if (struc.width > len)
  	{
 		i = struc.width - len;
   		while (i > 0 && struc.flag == 0)
		{
     		len += ft_putchar(' ');
			i--;
		}
   		ft_putstr(tmp);
		
   		while (i && struc.flag == 1)
		{
     		len += ft_putchar(' ');
			i--;
		}
  	}
  	else
 	ft_putstr(tmp);
 	return (len);
}
