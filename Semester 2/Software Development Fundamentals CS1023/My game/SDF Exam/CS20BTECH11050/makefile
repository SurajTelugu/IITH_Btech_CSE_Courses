CC = g++
CFLAGS = -c
OBJS = main.o auction.o

auction: $(OBJS); \
$(CC) -o auction 

main.o: main.cpp; \
$(CC) $(CFLAGS)  main.cpp

auction.o: auction.cpp; \
$(CC) -$(CFLAGS) auction.cpp