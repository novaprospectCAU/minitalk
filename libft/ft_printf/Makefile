CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c split.c print.c node/node.c \
		char/char.c addr/addr.c uint/uint.c \
		int/int.c hex/hex.c string/string.c
BONUSSRCS =	ft_printf_bonus.c split_bonus.c print_bonus.c \
		node_bonus/node_bonus.c node_bonus/fill_node_bonus.c \
		char_bonus/char_bonus.c char_bonus/char_write_bonus.c \
		addr_bonus/addr_bonus.c addr_bonus/addr_write_bonus.c \
		uint_bonus/uint_bonus.c uint_bonus/uint_write_bonus.c \
		int_bonus/int_bonus.c int_bonus/int_write_bonus.c \
		hex_bonus/hex_bonus.c hex_bonus/hex_write_bonus.c \
		string_bonus/string_bonus.c string_bonus/string_write_bonus.c
OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

ifndef EXISTBONUS
	ALLOBJS = $(OBJS)
else
	ALLOBJS = $(BONUSOBJS)
endif

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus :
	@make EXISTBONUS=1 all

$(NAME) : $(ALLOBJS)
	@ar -rc $@ $^

clean :
	@rm -rf $(OBJS) $(BONUSOBJS)

fclean : clean
	@rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus
