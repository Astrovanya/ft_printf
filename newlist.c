/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:46:40 by mleann            #+#    #+#             */
/*   Updated: 2020/07/16 23:16:50 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printflib.h"

t_list	*new_struct(char *format)
{
	t_list		*new;
	t_list		*lst;
	t_list		*tmp;

	lst = NULL;
	while (format && *format)
	{
		tmp = lst;
		new = new_list(&format);
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

t_list	*new_list(char **format)
{
	t_list		*new;

	new = malloc(sizeof(t_list));
	new->pretext = text_parser(format);
//	ft_putstr(*format);
//	ft_putchar(' ');
	new->flag = flag_parser(format);
//	ft_putstr(*format);
//	ft_putchar(' ');
	new->width = wigth_parser(format);
//	ft_putstr(ft_itoa(new->width));
//	ft_putchar(' ');
	new->prec = prec_parser(format);
//	ft_putstr(ft_itoa(new->prec));
//	ft_putchar(' ');
	new->type = type_parser(format);
//	ft_putstr(&new->type);
//	ft_putchar(' ');
	new->next = NULL;
	return (new);
}
/*

int main()
{
//	ft_printf("%5d\n",6);
//	ft_printf("%10.3s\n","Hello");

	
//	ft_printf("01) my       PRINTF : |%c|\n", 'a');
	
//	ft_printf("02) my       PRINTF : |%-c|\n", 'z');
	
//	ft_printf("03) my       PRINTF : |%-----c|\n", '!');
	
	ft_printf("%5.5c|\n", 'R');
	ft_printf("%5c|\n", 'R');
	
	ft_printf("05) my       PRINTF : |%-5c|\n", 'R');
	
	ft_printf("06) my       PRINTF : |%1c|\n", '3');
	
	ft_printf("07) my       PRINTF : |%c|\n", '\0');
	
	ft_printf("08) my       PRINTF : |%5c|\n", '\0');
	
	ft_printf("09) my       PRINTF : |%-5c|\n", '\0');
	
	ft_printf("10} my       PRINTF : |%1c|\n", '\0');
	return (0);
}  
*/