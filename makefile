CC = g++
CFLAGS = -Wall -g
 
example: example.o getNextRungeKuta.o
	$(CC) $(CFLAGS) -o example example.o getNextRungeKuta.o
 
example.o: example.cpp getNextRungeKuta.h
	$(CC)  $(CFLAGS) -c example.cpp
 
getNextRungeKuta.o: getNextRungeKuta.h

clean:
	rm *.o
	rm ./example
 