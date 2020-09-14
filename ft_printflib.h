/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:44:19 by mleann            #+#    #+#             */
/*   Updated: 2020/07/21 18:28:22 by mleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFLIB_H
# define FT_PRINTFLIB_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_list
{
	char			*pretext;
	int				flag;
	int				width;
	int				star_w;
	int				prec;
	int				star_prec;
	int				type;
	struct s_list	*next;
}					t_list;

int					ft_putchar(int c);
int					ft_putstr(char *s);
int					ft_atoi(char *str);
char				*ft_strjoin(char *l1, char *l2);
void				*ft_calloc(size_t num, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_long(long long n);
void				ft_free_struct(t_list **container);
int					free_buf(char **buf);
int					ft_printf(const char *line, ...);
t_list				*new_struct(char *line);
t_list				*new_list(char **line);
char				*text_parser(char **line);
int					flag_parser(char **line);
int					wigth_parser(char **line);
int					star_w_parser(char **line);
int					prec_parser(char **line);
int					star_e_parser(char **line);
int					type_parser(char **line);
int					write_type(char *t);
int					ft_printer(va_list print, t_list *container, int ret);
int					ft_print_from_struct(va_list print, t_list *container);
int					ft_print_num(size_t argint, t_list *container);
int					ft_print_u(unsigned long long argint, t_list *container);
int					ft_print_s(char *str, t_list *container);
int					ft_print_p(size_t pointer, t_list *container);
int					ft_print_c(size_t argint, t_list *container);
char				*ft_is_null(char **num, int size);
char				*ft_prec_s(char **num, int size);
char				*ft_prec(char **num, int size);
void				ft_prec_second(char **num, char *tmp, char **dest);
char				*ft_convert_x(unsigned int number);
char				*ft_convert_p(size_t number);
char				*ft_convert_xx(unsigned int number);
char				*ft_width(char **num, int size);
void				*ft_fill(size_t num, size_t size, char c);
char				*ft_width_right(char **num, int size);
int					ft_print_percent(char *str, t_list *pars_form);
#endif
