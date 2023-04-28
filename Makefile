CC = cc
CFLAGS = -Wall -Werror -Wextra
CLINAME = client
CLISRCS = client.c
SERNAME = server
SERSRCS = server.c
PRINTDIR = ft_printf
LIBFTDIR = libft
OBJS = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(ALLOBJS)
	@ar -rc $@ $^

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf 
	@rm -rf $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus
