# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleann <mleann@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 17:45:11 by mleann            #+#    #+#              #
#    Updated: 2020/07/21 18:10:16 by mleann           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -c -Wall -Wextra -Werror

NAME = libftprintf.a

FUNC = ft_printf.c\
basic_tools.c\
ft_convertor.c\
ft_flags.c\
ft_print.c\
ft_print_tools.c\
ft_utils.c\
newlist.c\
parser.c


OBJ = $(FUNC:.c=.o)

HEADER = ft_printflib.h

.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c $(HEADER)
	clang  $(FLAG)  -c $< -o $@

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJ) $(O_BONUS)
	ar -rc $(NAME) $(OBJ) $(O_BONUS)

clean:
	rm -f $(OBJ) $(O_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
