# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 15:49:51 by tbouma            #+#    #+#              #
#    Updated: 2022/05/27 10:48:07 by tbouma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
OBJFILES := obj/main.o obj/utils/node.o obj/operations/swap.o \
obj/operations/push.o obj/operations/rotate.o obj/utils/print.o obj/sort/sort234.o \
obj/utils/index.o obj/sort/bucket_sort.o obj/sort/bucket_sort2.o obj/utils/bucket.o \
obj/sort/sort5.o
OBJFILES_DEBUG := obj/status.o
LIBFT := includes/libft/libft.a
HEADERS := -I includes/libft/
CFLAGS := -Wall -Wextra -Werror
CFLAGS_DEBUG := -fsanitize=address -g3
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