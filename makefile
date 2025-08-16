# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3

# Nom de l'exécutable
NAME = program

# Sources et objets
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable avec la MLX
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

# Règle générique pour les fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
