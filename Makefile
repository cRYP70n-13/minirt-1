CC = gcc
LOPTS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
# LOPTS = -lcsfml-graphics -lcsfml-window -lm
MCOPTS = -O3 -O2 -I /usr/local/include
COPTS = -c
OBJS =  main.o rays.o vec3f.o s_vec3f.o image.o hittable.o hittable_list.o sphere.o garrptr.o camera.o tools.o bmp.o
# OBJS =  main_csfml.o rays.o vec3f.o s_vec3f.o hittable.o hittable_list.o sphere.o garrptr.o camera.o tools.o csfml.o

NAME = main
all:$(NAME)
$(NAME) : $(OBJS)
	$(CC) $(MCOPTS) $(OBJS) -o $(NAME) $(LOPTS)

main.o : main.c 
	$(CC) $(COPTS) main.c

bmp.o : bmp.c
	$(CC) $(COPTS) bmp.c

tools.o : tools.c
	$(CC) $(COPTS) tools.c

sphere.o : hittable/sphere.c
	$(CC) $(COPTS) hittable/sphere.c

hittable_list.o : hittable/hittable_list.c 
	$(CC) $(COPTS) hittable/hittable_list.c

hittable.o : hittable/hittable.c 
	$(CC) $(COPTS) hittable/hittable.c

rays.o : rays/rays.c
	$(CC) $(COPTS) rays/rays.c

vec3f.o : vec3f/vec3f.c
	$(CC) $(COPTS) vec3f/vec3f.c

s_vec3f.o : vec3f/s_vec3f.c
	$(CC) $(COPTS) vec3f/s_vec3f.c

image.o : image/image.c image/image.h
	$(CC) $(COPTS) image/image.c

# csfml.o : csfml.c csfml.h
	# $(CC) $(COPTS) csfml.c

garrptr.o : generic_arrptr/garrptr.c generic_arrptr/garrptr.h
	$(CC) $(COPTS) generic_arrptr/garrptr.c
	
camera.o : camera.c 
	$(CC) $(COPTS) camera.c
	

clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all