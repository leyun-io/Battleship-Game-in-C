CC=gcc

CFLAGS=-Wall -ansi -pedantic
OBJ=main.o grid_initialise.o read_ship_details.o user_interface.o update_grid.o linked_list.o file_save_n_read.o
NORMALOBJ=print_grid.o 
EXEC=battleship

DEBUGFLAGS=-Wall -ansi -pedantic -D DEBUG
DEBUGOBJ=print_grid_debug.o
DEBUGEXEC=battleship_debug

all: $(EXEC) $(DEBUGEXEC)

$(EXEC): $(OBJ) $(NORMALOBJ)
	$(CC) $(OBJ) $(NORMALOBJ) -o $(EXEC)

$(DEBUGEXEC): $(OBJ) $(DEBUGOBJ)
	$(CC) $(OBJ) $(DEBUGOBJ) -o $(DEBUGEXEC)

main.o: main.c read_ship_details.h grid_initialise.h print_grid.h constant.h user_interface.h update_grid.h linked_list.h file_save_n_read.h
	$(CC) -c main.c $(CFLAGS) 

grid_initialise.o: grid_initialise.c grid_initialise.h constant.h
	$(CC) -c grid_initialise.c $(CFLAGS)

print_grid_debug.o: print_grid.c print_grid.h constant.h
	$(CC) -c print_grid.c $(DEBUGFLAGS) -o print_grid_debug.o 

print_grid.o: print_grid.c print_grid.h constant.h
	$(CC) -c print_grid.c $(CFLAGS)

read_ship_details.o: read_ship_details.c read_ship_details.h constant.h
	$(CC) -c read_ship_details.c $(CFLAGS)

user_interface.o: user_interface.c user_interface.h print_grid.h
	$(CC) -c user_interface.c $(CFLAGS)

update_grid.o: update_grid.c update_grid.h print_grid.h constant.h
	$(CC) -c update_grid.c $(CFLAGS)

linked_list.o: linked_list.c linked_list.h
	$(CC) -c linked_list.c $(CFLAGS)

file_save_n_read.o: file_save_n_read.c file_save_n_read.h linked_list.h constant.h
	$(CC) -c file_save_n_read.c $(CFLAGS)

clean:
	rm -f $(OBJ) $(NORMALOBJ) $(DEBUGOBJ) $(EXEC) $(DEBUGEXEC)
