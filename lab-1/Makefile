EXE_1	=	task_1
EXE_2	=	task_2
EXE_3	=	task_3

SRC_1	=	main-1.c
SRC_2	=	main-2.c
SRC_3	=	main-3.c

OBJ_1	=	${SRC_1:.c=.o}
OBJ_2	=	${SRC_2:.c=.o}
OBJ_3	=	${SRC_3:.c=.o}

FLAGS	=	-Wall -Wextra -Werror

all: $(EXE_1) $(EXE_2) $(EXE_3)

$(EXE_1): $(OBJ_1)
	gcc $< -o $@

$(EXE_2): $(OBJ_2)
	gcc $< -o $@

$(EXE_3): $(OBJ_3)
	gcc $< -o $@

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ_1) $(OBJ_2) $(OBJ_3)
		
fclean: clean
		rm -f $(EXE_1) $(EXE_2) $(EXE_3)

.PHONY: clean fclean all EXE_1 EXE_2 EXE_3
