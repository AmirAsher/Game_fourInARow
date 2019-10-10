TARGET=test
SOURCE=*.cpp

INC_DIR  =../inc
CPPFLAGS =-I$(INC_DIR) -std=c++11 -fmax-errors=5

all:
	g++ -ansi -pedantic -Wall -Werror -w -Wextra $(CPPFLAGS) $(SOURCE) -o $(TARGET) -g3

run: all
	./$(TARGET)

clean:
	rm -f $(TARGETTARGET)

gdb: all
	gdb -q ./$(TARGET)

valgrind:  all
	valgrind -v --leak-check=full ./$(TARGET)
