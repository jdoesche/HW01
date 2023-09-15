CC = g++
CFLAGS = -g -Wall -Wextra

default: vectored

vectored:		Vectored.o main.o
	$(CC) $(CFLAGS) -o vectored Vectored.o main.o

Vectored.o:	Vectored.cpp Vectored.h
	$(CC) $(CFLAGS) -c Vectored.cpp

main.o:	main.cpp Vectored.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) vectored *.o *~
