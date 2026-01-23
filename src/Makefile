CC = gcc
TARGET =  main
SRC    = main.c board/board.c event/event.c

all: $(TARGET)

$(TARGET): $(SRC) event/*.h board/*.h
	$(CC)  -o $(TARGET) $(SRC) -lm
