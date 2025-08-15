######################## SETTINGS ########################

NAME = fdf

CC = cc

FLAGS = -Wall -Wextra -Werror

LINKFLAGS = -lm -lmlx -lXext -lX11 -L minilibx -L libft -lft

CPPFLAGS = -I minilibx -I libft -I libft/includes

INCLUDES =	includes

######################## SOURCES ########################

SRCS_NAMES =	main.c \
				exit.c \
				parsing.c \
				init.c \
				handler.c \
				handler_utils.c \
				draw.c \
				draw_utils.c \
				transform_pos.c \
				utils.c \
				colors.c \
				debug.c

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.c=.o}}

######################## BASIC RULES ########################

all : ${NAME}

re : fclean
	${MAKE} all

clean :
	${foreach lib, ${LIBS}, ${MAKE} clean -C ${lib}}
	rm -rf ${OBJS_DIR}

fclean : clean
	${foreach lib, ${LIBS}, ${MAKE} fclean -C ${lib}}
	rm -f ${NAME}

norm :
	${foreach lib, ${LIBS}, ${MAKE} norm -C ${lib}}
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCLUDES}

######################## COMPILATION ########################

${NAME} : SUB_MODULE ${OBJS_DIR} ${OBJS}
	${MAKE} -C minilibx
	${MAKE} -C libft
	${CC} ${FLAGS} ${OBJS} -o $@ ${LINKFLAGS}

debug : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} -g3 -fsanitize=address ${OBJS} -o ${NAME} ${LINKFLAGS}

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}%.o : ${SRCS_DIR}%.c
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@

SUB_MODULE :
	git submodule update --init
######################## TEST ########################

test : square

42 : all
	./${NAME} maps/42.fdf

square : all
	./${NAME} maps/square.fdf

long : all
	./${NAME} maps/long.fdf

error : all
	./${NAME} maps/invalid.fdf

pylone : all
	./${NAME} maps/pylone.fdf

pyramide : all
	./${NAME} maps/pyramide.fdf
