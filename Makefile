NAME		=	libftprintf.a

SRCS		=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_isspace.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putendl_fd.c \
				ft_strmap.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strmapi.c \
				ft_putendl.c \
				ft_strjoin.c \
				ft_itoa.c \
				ft_strtrim.c \
				ft_absval.c \
				ft_factorial.c \
				ft_strsplit.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_itoa_base.c \
				ft_putwchar.c \
				ft_putwstr.c \
				ft_wstrlen.c \
				ft_wstrcat.c \
				ft_wstrdup.c \
				ft_wcharlen.c \
				ft_wstrnew.c \
				ft_wcharlen.c \
				ft_wstrjoin.c \
				ft_wstrchr.c \
				ft_wstrcmp.c \
				ft_wstrncmp.c

PF_SRCS		=	ft_printf.c \
				ft_parse.c \
				ft_save.c \
				ft_is.c \
				ft_is2.c \
				ft_preprocess.c \
				ft_process.c \
				ft_toolbox.c \
				ft_toolbox2.c \
				ft_process2.c \
				ft_colors.c \
				ft_preprocess2.c \
				ft_process3.c

OBJS		=	$(addprefix libft/, $(SRCS:.c=.o))

PF_OBJS		=	$(addprefix srcs/, $(PF_SRCS:.c=.o))

INCS		=	./includes

CC			=	clang

FLAGS		=	-Weverything -Werror -pedantic

CNONE		=	\x1b[0m
CGREEN		=	\x1b[32m
CWHITE		=	\x1b[97m

all: $(NAME)

$(NAME): $(OBJS) $(PF_OBJS)
	ar -rcs $(NAME) $(OBJS) $(PF_OBJS)

libft/%.o: libft/%.c
	$(CC) $(FLAGS) -I$(INCS) -o $@ -c $<

srcs/%.o: srcs/%.c
	$(CC) $(FLAGS) -I$(INCS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(PF_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
