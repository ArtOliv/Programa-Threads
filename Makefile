PC = gcc
EXECUTAVEL = tRace
OBJ = main.o thread_functions.o
CFLAGS = -Wall -pthread

all: $(OBJ)
	$(PC) $(OBJ) -o $(EXECUTAVEL)

main.o: thread_race/main.c thread_race/thread.h
	$(PC) $(CFLAGS) -c thread_race/main.c

thread_functions.o: thread_race/thread_functions.c thread_race/thread.h
	$(PC) $(CFLAGS) -c thread_race/thread_functions.c

clean:
	rm *.o
	rm $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)