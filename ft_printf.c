/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:59:54 by mleann            #+#    #+#             */
/*   Updated: 2020/07/16 21:01:46 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

int		ft_printf(const char *line, ...)
{
	t_list	*parsed;
	va_list	print;
	char	*tmp;
	int		len;

	len = 0;
	tmp = (char *)line;
	parsed = new_struct(tmp);
	va_start(print, line);
	len = print_struct(print, parsed, 0);
	va_end(print);
	ft_free_struct(&parsed);
	return (len);
}

int		print_struct(va_list print, t_list *parsed, int ret)
{
	while (parsed != NULL)
	{
		if (parsed->width == -1)
			parsed->width = va_arg(print, int);
		if (parsed->prec == -1)
			parsed->prec = va_arg(print, int);
		if (parsed->pretext)
			ret += ft_putstr(parsed->pretext);
		if (parsed->type)
			ret += type_scun(print, parsed, ret);
		parsed = parsed->next;
	}
	return (ret);
}

int		type_scun(va_list print, t_list *parsed, int res)
{
	if (parsed->type == 'i' || parsed->type == 'd')
		res += ft_print_i_d(va_arg(print, int), *parsed);
	else if (parsed->type == 'u')
		res += ft_print_u(va_arg(print, unsigned int), *parsed);
	else if (parsed->type == 'c')
		res += ft_print_c(va_arg(print, int), *parsed);
	else if (parsed->type == 's')
		res += ft_print_s(va_arg(print, char*), *parsed);
	else if (parsed->type == 'p')
		res += ft_print_p((size_t)va_arg(print, void *), *parsed);
	else if (parsed->type == 'x')
		res += ft_print_x(va_arg(print, int), *parsed);
	else if (parsed->type == 'X')
		res += ft_print_xx(va_arg(print, int), *parsed);
	//else if (parsed->type == '%')
		//res += ft_print_persent(va_arg(print, int), &parsed);
	return res;
}

void	ft_free_struct(t_list **pars_form)
{
	t_list	*tmp;

	if (!pars_form || !*pars_form)
		return ;
	while (*pars_form != NULL)
	{
		tmp = *pars_form;
		if ((*pars_form)->pretext)
			free((*pars_form)->pretext);
		*pars_form = (*pars_form)->next;
		free(tmp);
		tmp = NULL;
	}
}
/*
int main()
{
	ft_printf("%10.5d\n",6);
	ft_printf("%10.3s\n","Hello");
	return (0);
}  
*/
