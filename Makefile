CC = cc
CFLAGS = -Wall -Werror -Wextra
CLINAME = client
CLISRCS = client.c
SERNAME = server
SERSRCS = server.c
LIBFT = libft
CLIOBJS = $(CLISRCS:.c=.o)
SEROBJS = $(SERSRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(CLINAME) : $(CLIOBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(SERNAME) : $(SEROBJS)
	@$(CC) $(CFLAGS) -o $@ $^

all : $(CLINAME) $(SERNAME)
	@make -C $(LIBFT) all

clean :
	@rm -rf $(CLIOBJS) $(SEROBJS)
	@make -C $(LIBFT) clean

fclean : clean
	@rm -rf $(SERNAME) $(CLINAME)
	@make -C $(LIBFT) fclean

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus
