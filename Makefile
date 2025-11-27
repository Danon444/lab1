FLAGS = -Wall -Wextra
TARGET = main
OBJ = main.o func.o
.PHONY: clean run
$(TARGET): $(OBJ)
    gcc -o $(TARGET) $(OBJ)
main.o: main.c func.h
    gcc $(FLAGS) -c main.c
calc.o: func.c func.h
    gcc $(FLAGS) -c func.c

clean: rm -f $(OBJ) $(TARGET)

run: $(TARGET)
    ./$(TARGET) 41 + 33 111 - 8 22 \* 5 221 % 111 100 + 13 -k 2
