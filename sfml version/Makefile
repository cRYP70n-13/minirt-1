CC = g++
LOPTS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
COPTS = -c
OBJS = test_camera.o mlx.o

NAME = test_camera
all:$(NAME)
$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o test_camera $(LOPTS)

test_camera.o : test_camera.cpp mlx.o
	$(CC) $(COPTS) test_camera.cpp

mlx.o : mlx/mlx.cpp mlx/mlx.h
	$(CC) $(COPTS) mlx/mlx.cpp



clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all