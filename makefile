CC=gcc

CFLAGS=-Wall -ansi -pedantic
OBJ=main.o grid_initialise.o ship_locations.o put_ship.o user_interface.o check_if_hit.o
NORMALOBJ=print_ship.o 
EXEC=battleship

DEBUGFLAGS=-Wall -ansi -pedantic -D DEBUG
DEBUGOBJ=print_ship_debug.o
DEBUGEXEC=battleship_debug

all: $(EXEC) $(DEBUGEXEC)

$(EXEC): $(OBJ) $(NORMALOBJ)
	$(CC) $(OBJ) $(NORMALOBJ) -o $(EXEC)

$(DEBUGEXEC): $(OBJ) $(DEBUGOBJ)
	$(CC) $(OBJ) $(DEBUGOBJ) -o $(DEBUGEXEC)

main.o: main.c ship_locations.h grid_initialise.h print_ship.h constant.h put_ship.h user_interface.h check_if_hit.h
	$(CC) -c main.c $(CFLAGS) 

grid_initialise.o: grid_initialise.c grid_initialise.h constant.h
	$(CC) -c grid_initialise.c $(CFLAGS)

print_ship_debug.o: print_ship.c print_ship.h constant.h
	$(CC) -c print_ship.c $(DEBUGFLAGS) -o print_ship_debug.o 

print_ship.o: print_ship.c print_ship.h constant.h
	$(CC) -c print_ship.c $(CFLAGS)

ship_locations.o: ship_locations.c ship_locations.h constant.h
	$(CC) -c ship_locations.c $(CFLAGS)

put_ship.o: put_ship.c put_ship.h constant.h
	$(CC) -c put_ship.c $(CFLAGS)

user_interface.o: user_interface.c user_interface.h print_ship.h
	$(CC) -c user_interface.c $(CFLAGS)

check_if_hit.o: check_if_hit.c check_if_hit.h print_ship.h constant.h
	$(CC) -c check_if_hit.c $(CFLAGS)

clean:
	rm -f $(OBJ) $(NORMALOBJ) $(DEBUGOBJ) $(EXEC) $(DEBUGEXEC)
