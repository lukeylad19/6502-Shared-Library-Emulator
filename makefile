SRC_DIR = src

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = ./*.o

.PHONY: clean

all:
	g++ -c -Wall -Werror -fpic $(SRC) 
	g++ -shared -o lib6502.so $(OBJ)
	g++ ./test/test.cpp -I./src -L./ -l6502 -o 6502_test

clean:
	rm *.so *.o 6502_test