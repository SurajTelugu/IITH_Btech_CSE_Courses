main: main.o Player.o Button.o; \
g++ -o main -L C:\\SFML-2.5.1\\lib main.o Player.o Button.o -lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system

main.o: main.cpp; \
g++ -c -I C:\\SFML-2.5.1\\include main.cpp

Button.o: Button.cpp Button.h; \
g++ -c -I C:\\SFML-2.5.1\\include Button.cpp

Player.o: Player.cpp Player.h; \
g++ -c -I C:\\SFML-2.5.1\\include Player.cpp
