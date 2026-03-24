NAME = libasm.a
TEST = test

CC = gcc
AS = nasm
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -no-pie
ASFLAGS = -f elf64

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.s=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

# Ejecutable para probar
$(TEST): $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re test
