main: main.o Game.o; \
g++ -o main -L C:\\SFML-2.5.1\\lib main.o Game.o -lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system

Game.o: Game.cpp Game.h; \
g++ -c -I C:\\SFML-2.5.1\\include Game.cpp

main.o: main.cpp Game.h; \
g++ -c -I C:\\SFML-2.5.1\\include main.cpp