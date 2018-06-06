CC=g++
#CFLAGS=-Wall -Wextra -Wvla -g -lm -std=c++11
CFLAGS=-Wvla -g -lm -std=c++11

App: main.o Nuoma.o ApartamentuNuoma.o Data.o AbsNuoma.o
	$(CC) $(CFLAGS) -o Prog main.o Nuoma.o ApartamentuNuoma.o Data.o AbsNuoma.o

main.o: main.cpp ApartamentuNuoma.cpp main.h
	$(CC) $(CFLAGS) -c main.cpp ApartamentuNuoma.cpp

ApartamentuNuoma.o: ApartamentuNuoma.cpp Nuoma.cpp
	$(CC) $(CFLAGS) -c ApartamentuNuoma.cpp Nuoma.cpp

AbsNuoma.o: AbsNuoma.cpp
	$(CC) $(CFLAGS) -c AbsNuoma.cpp

Nuoma.o: Nuoma.cpp Data.cpp AbsNuoma.cpp
	$(CC) $(CFLAGS) -c Nuoma.cpp Data.cpp AbsNuoma.cpp

Data.o: Data.cpp
	$(CC) $(CFLAGS) -c Data.cpp

clean:
	rm -rf Data.o Nuoma.o main.o AbsNuoma.o ApartamentuNuoma.o
