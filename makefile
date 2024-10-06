p01_chainCC=g++ -std=c++20
CFLAGS=-O0 -g -Wall
DEPS = matriz_distancia.h
OBJ = main.o

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o p01_busqueda


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: chain

busqueda: main.o
	g++ -o p01_busqueda main.cc matriz_distancia.cc

clean:
	rm -f *.o