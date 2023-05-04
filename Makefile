CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIENTTARGET = client
CLIENTSRCS = client.c
SERVERTARGET = server
SERVERSRCS = server.c
LIBFT = libft
LIBFTLIB = libft/libft.a libft/ft_printf/libftprintf.a
CLIENTOBJS = $(CLIENTSRCS:.c=.o)
SERVEROBJS = $(SERVERSRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $^

$(CLIENTTARGET) : $(CLIENTOBJS)
	@$(CC) $(CFLAGS) $^ $(LIBFTLIB) -o $@

$(SERVERTARGET) : $(SERVEROBJS)
	@make -C $(LIBFT) all
	@$(CC) $(CFLAGS) $^ $(LIBFTLIB) -o $@

all : $(SERVERTARGET) $(CLIENTTARGET)

clean :
	@rm -rf $(CLIENTOBJS) $(SERVEROBJS)
	@make -C $(LIBFT) clean

fclean : clean
	@rm -rf $(SERVERTARGET) $(CLIENTTARGET)
	@make -C $(LIBFT) fclean

re : 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re bonus
