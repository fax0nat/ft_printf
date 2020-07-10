# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhershel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 19:07:02 by yhershel          #+#    #+#              #
#    Updated: 2020/07/10 22:31:13 by yhershel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
CC = clang
FLAG = -Wall -Werror -Wextra -g

OBJDIR = objs
SRCDIR = srcs
INCDIR = incs

LINE = ''

SRC = ft_printf.c\
ft_printf_2.c\
dothething.c\
dothething_2.c\
helpers.c\
helpers_2.c\
helpers_3.c\
dth_s.c\
dth_prc.c\
dth_p.c\
dth_i_d.c\
dth_i_d_2.c\
dth_i_d_3.c\
dth_u.c\
dth_u_2.c\
dth_x.c\
actions.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo $(LINE)
	#### LIBFT COMPILE ####

	@make -C $(LIBFT)

	@echo $(LINE)
	#### SRCS OF PRINTF COMPILE ####

	@cd $(SRCDIR) && $(CC) -c $(FLAG) $(SRC) && mv *.o ../$(OBJDIR) && cd ..

	@echo $(LINE)
	#### LIBFTPRINTF COMPILE ####
	
	@cd $(OBJDIR) && ar rc $(NAME) $(OBJ) ../libft/*.o && mv $(NAME) .. && cd ..

%.o: %.c $(SRCDIR)/$(SRC)
	$(CC) -c -o $(FLAG) %.o %.c

clean:
	@echo $(LINE)
	#### DELETE OBJS ####

	make clean -C $(LIBFT)
	cd $(OBJDIR) && rm -fr && cd .. 

fclean: clean
	@echo $(LINE)
	#### DELETE $(NAME) ####

	make fclean -C $(LIBFT)
	rm -fr $(NAME)

re: fclean all
	@echo $(LINE)
	#### CLEAN AND REPEAT ####
	
	make re -C $(LIBFT)