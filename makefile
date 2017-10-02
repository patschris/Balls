CC		= g++
CFLAGS	= -g3 -Wall
EXEC 	= balls
OBJS 	= ball.o ballholder.o basketball.o main.o pingpong.o tennis.o validateArgs.o 
SRCS 	= ball.cpp ballholder.cpp basketball.cpp main.cpp pingpong.cpp tennis.cpp validateArgs.cpp 


.PHONY : all

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

ball.o: ball.cpp
	$(CC) $(CFLAGS) -c ball.cpp

ballholder.o: ballholder.cpp
	$(CC) $(CFLAGS) -c ballholder.cpp

basketball.o: basketball.cpp
	$(CC) $(CFLAGS) -c basketball.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


pingpong.o: pingpong.cpp
	$(CC) $(CFLAGS) -c pingpong.cpp

tennis.o: tennis.cpp
	$(CC) $(CFLAGS) -c tennis.cpp

validateArgs.o: validateArgs.cpp
	$(CC) $(CFLAGS) -c validateArgs.cpp



.PHONY: clean

clean:
	rm -f $(OBJS) $(EXEC)
