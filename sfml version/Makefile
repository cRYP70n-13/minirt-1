CC = g++
LOPTS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
COPTS = -c
OBJS = main.o

NAME = main
all:$(NAME)
$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o main $(LOPTS)

main.o : main.cpp
	$(CC) $(COPTS) main.cpp




clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all