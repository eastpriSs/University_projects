CC=gcc

all: game clean

game: main.o Plate.o PlateMatrix.o PlayGround.o Player.o Scene.o Game.o EventHandler.o 
	$(CC) main.o Plate.o PlateMatrix.o PlayGround.o Player.o Scene.o Game.o EventHandler.o -o game

main.o: main.c
	$(CC) -c main.c

Plate.o: Plate.c
	$(CC) -c Plate.c

PlateMatrix.o: PlateMatrix.c
	$(CC) -c PlateMatrix.c

PlayGround.o: PlayGround.c
	$(CC) -c PlayGround.c

Player.o: Player.c
	$(CC) -c Player.c

Scene.o: Scene.c
	$(CC) -c Scene.c

Game.o: Game.c
	$(CC) -c Game.c

EventHandler.o: EventHandler.c
	$(CC) -c EventHandler.c

clean:
	del -rf *.o