CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

test: obj obj/main.o obj/graph.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/graph.o

obj/main.o: src/main.cpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/graph.o: inc/graph.hh src/graph.cpp
	g++ -c ${CXXFLAGS} -o obj/graph.o src/graph.cpp

clean:
	rm obj/*.o test

