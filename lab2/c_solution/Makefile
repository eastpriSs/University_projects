CC=gcc

all: main clean

main: main.o Day.o Hour.o Minute.o Second.o Month.o Year.o Date.o Time.o DateTime.o 
	$(CC) main.o Day.o Hour.o Minute.o Second.o Month.o Year.o Time.o Date.o DateTime.o -o test

main.o: main.c
	$(CC) -c main.c

Hour.o: Hour.c
	$(CC) -c Hour.c

Minute.o: Minute.c
	$(CC) -c Minute.c

Second.o: Second.c
	$(CC) -c Second.c

Time.o: Time.c
	$(CC) -c Time.c

Day.o: Day.c
	$(CC) -c Day.c

Month.o: Month.c
	$(CC) -c Month.c

Year.o: Year.c
	$(CC) -c Year.c


Date.o: Date.c
	$(CC) -c Date.c


DateTime.o: DateTime.c
	$(CC) -c DateTime.c

clean:
	del -rf *.o