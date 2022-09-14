NAME = fractol
LIBFT = libft/libft.a
LIBFTDIR = libft/
LIBPRINTFDIR = ft_printf/
FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTFDIR = ft_printf/include

SRCDIR = src/
OBJDIR = obj/
INCDIR = include/

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -I ${FT_PRINTFDIR} -I ${LIBFTDIR} -I ${INCDIR}
LIBFLAGS = -lmlx -lm -lbsd -lXext -lX11 -lft -lftprintf
CC = cc -O3
CC += -march=native -mno-vzeroupper

FILES = main.c exit.c handle_events.c render.c init.c set_data.c \
		draw.c math.c
SRC = ${addprefix ${SRCDIR}, ${FILES}}
OBJ = ${addprefix ${OBJDIR}, ${FILES:.c=.o}}

all: ${NAME}

${OBJDIR}:
	mkdir -p ${OBJDIR}

${OBJDIR}%.o: ${SRCDIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${FT_PRINTF} ${LIBFT} ${OBJDIR} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} \
	-L ${LIBPRINTFDIR} -lftprintf ${LIBFLAGS} -o ${NAME}

${LIBFT}:
	make -C ${LIBFTDIR}

${FT_PRINTF}:
	make -C ${FT_PRINTF}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: re fclean clean all norm