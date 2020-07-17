/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:44:19 by mleann            #+#    #+#             */
/*   Updated: 2020/07/16 13:01:58 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			*pretext;
	int				flag;
	int				width;
	int				prec;
	char			type;
}					t_list;

int		ft_printf(const char *line, ...);
t_list	*new_struct(char *format);
t_list	*new_list(char **format);
char	*text_parser(char **line);
int		flag_parser(char **line);
int		returner(int minus, int zero);
int		wigth_parser(char **format);
int		prec_parser(char **format);
char		type_parser(char **format);
int		type_scun(va_list print, t_list *pars_form, int res);
int		print_struct(va_list print, t_list *parsed, int ret);
int		ft_print_i_d(int n, t_list struc);
int		ft_print_u(unsigned int n, t_list struc);
int		ft_print_p(size_t p, t_list struc);
int		ft_print_x(unsigned int x, t_list struc);
char	*ft_x_convert(unsigned int number);
int		ft_print_xx(unsigned int x, t_list struc);
char	*ft_xx_convert(unsigned int number);
int		ft_print_c(size_t c, t_list struc);
int		ft_print_s(char *s, t_list struc);
int		ft_atoi(const char *num);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t num, size_t size);
size_t		ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_itoa(int n);
void	ft_free_struct(t_list **pars_form);
int		ft_print_percent(char *str, t_list *pars_form);
