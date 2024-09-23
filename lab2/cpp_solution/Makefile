CC=g++

all: main clean

main: main.o Day.o Hour.o Minute.o Second.o Month.o Year.o Date.o Time.o DateTime.o 
	$(CC) main.o Day.o Hour.o Minute.o Second.o Month.o Year.o Time.o Date.o DateTime.o -o test

main.o: main.cpp
	$(CC) -c main.cpp

Hour.o: Hour.cpp
	$(CC) -c Hour.cpp

Minute.o: Minute.cpp
	$(CC) -c Minute.cpp

Second.o: Second.cpp
	$(CC) -c Second.cpp

Time.o: Time.cpp
	$(CC) -c Time.cpp

Day.o: Day.cpp
	$(CC) -c Day.cpp

Month.o: Month.cpp
	$(CC) -c Month.cpp

Year.o: Year.cpp
	$(CC) -c Year.cpp


Date.o: Date.cpp
	$(CC) -c Date.cpp


DateTime.o: DateTime.cpp
	$(CC) -c DateTime.cpp

clean:
	del -rf *.o