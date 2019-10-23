NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
HEADER = inc
TEST = printf_tester
LIBFT_HEADER = libft/libft.h
SOURCES := ft_printf.c
SOURCES += parse.c
SOURCES += libft_extra_1.c libft_extra_2.c
SOURCES += handler_1.c handler_2.c
SOURCES += handler_3.c
SOURCES += helper.c
SOURCES := $(SOURCES:%.c=src/%.c)
OBJECTS := $(SOURCES:src/%.c=obj/%.o)


all: $(NAME)

$(NAME): object
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT).a ./$(NAME)
	@ar -rcs $(NAME) $(OBJECTS)
test: $(NAME)
	rm -f ./$(TEST)
	gcc -o $(TEST) -g $(CFLAGS) ../test/main.c $(SOURCES) ./libft/libft.a
	./$(TEST)
object: $(SOURCES)
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(HEADER) -I$(LIBFT_HEADER) -c $(SOURCES)
	@mv *.o obj

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf obj

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -rf ../printf_tester
	@/bin/rm -rf ../printf_tester.dSYM

re: fclean all
