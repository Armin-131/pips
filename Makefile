NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

SRC = \
		pipex.c\
		children.c\

OBJS = $(SRC:.c=.o)

RM = rm -f

#libs
LIBFT_PATH = ./include/libft
LIBFT = $(LIBFT_PATH)/libft.a
VPATH = source

%.o: %.c
		$(CC) $(CFLAGS) -c $< -I$(LIBFT_PATH) -I include -o $@

all: $(NAME)

$(LIBFT):
		make -C $(LIBFT_PATH)
		
$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH)  -lft -o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -s -C $(LIBFT_PATH)

fclean:
		$(RM) $(NAME) $(OBJS)
		make fclean -s -C $(LIBFT_PATH)

cleantxt:
		$(RM) *.txt

re: 	fclean all

.PHONY: all clean fclean cleantxt re