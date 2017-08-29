##
## Makefile for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc
## 
## Made by Gregoire Renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Mar 20 09:56:02 2017 Gregoire Renard
## Last update Sun Apr  2 23:39:35 2017 Gregoire Renard
##

CC	=	gcc -Iinclude/ -g3

RM	=	rm -fr

NAME	=	lemipc

SRCS	=	main.c \
		src/fill_info.c \
		src/set_map.c \
		src/print_map.c \
		src/printf_error.c \
		src/all_process.c \
		src/set_all.c \
		src/map_function.c \
		src/start_work.c \
		src/convert_in_char.c \
		src/pop.c \
		src/move.c \
		src/create_shm.c \
		src/get_shm.c \
		src/create_semaphore.c \
		src/semaphore_inc_dec.c \
		src/get_sem.c \
		src/create_msg.c \
		src/get_msg.c \
		src/attack.c \
		src/enemy.c \
		src/sms.c \
		src/restart_first.c \
		src/init_or_end.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Werror -Wextra -Wall

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(SRCS) -lncurses -lpthread -g3

re	:	fclean all

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

.PHONY	:	all re clean fclean
