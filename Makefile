# -variables
NAME = fractol
# --libaries
LIBFT = libft/libft.a
LIBFTDIR = libft/
LIBPRINTFDIR = ft_printf/
FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTFDIR = ft_printf/include
MLX = minilibx-linux/libmlx_Linux.a
MLXDIR = minilibx-linux/
# --directories
SRCDIR = src/
OBJDIR = obj/
INCDIR = include/

# -flags
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -I ${FT_PRINTFDIR} -I ${LIBFTDIR} -I ${MLXDIR} -I ${INCDIR}
LIBFLAGS = -lmlx -lm -lbsd -lXext -lX11 -lft -lftprintf
CC = cc -O3
CC += -march=native -mno-vzeroupper

#-I include = header
#-L directory = library
#-l file inside directory = library (no -ib or .a)

# -find files in N directory
FILES = main.c exit.c handle_events.c render.c init.c set_data.c \
		draw.c math.c
SRC = ${addprefix ${SRCDIR}, ${FILES}}
OBJ = ${addprefix ${OBJDIR}, ${FILES:.c=.o}}

# commands
# comando -> o que precisa
# o que vai executar
all: ${NAME}

# create dir if not exists
${OBJDIR}:
	mkdir -p ${OBJDIR}

# create binary .o files
${OBJDIR}%.o: ${SRCDIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

# run main program
${NAME}: ${MLX} ${FT_PRINTF} ${LIBFT} ${OBJDIR} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} \
	-L ${LIBPRINTFDIR} -lftprintf -L ${MLXDIR} ${LIBFLAGS} -o ${NAME}

# compile libs if not exist
# -C enters on directory
${LIBFT}:
	make -C ${LIBFTDIR}

${FT_PRINTF}:
	make -C ${FT_PRINTF}

${MLX}:
	make -C ${MLXDIR}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: re fclean clean all norm