CC = clang
FLAGS = -Wall -Werror -Wextra
SRC = test_libft.c
OUT = test_libft

test : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(OUT)

debug : $(SRC)
	$(CC) $(FLAGS) -g $(SRC) -o $(OUT)
		
clean: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(OUT)
	rm -rf *.o
