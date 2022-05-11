# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 15:49:51 by tbouma            #+#    #+#              #
#    Updated: 2022/05/11 11:22:34 by tbouma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
OBJFILES := obj/main.o obj/status.o obj/utils/node.o obj/utils/operations.o obj/utils/print.o
LIBFT := includes/libft/libft.a
HEADERS := -I includes/libft/
CFLAGS := -Wall -Wextra -Werror
CC := gcc

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./includes/libft

$(NAME): $(OBJFILES)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT) $(HEADERS) -o $(NAME)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)
	make clean -C ./includes/libft

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./includes/libft

re: fclean all

.PHONY: clean all fclean re