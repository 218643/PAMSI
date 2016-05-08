CPPFLAGS= -c -g -std=c++11 -Iinc

__start__: prog
	./prog

prog: obj/main.o obj/main.o obj/graph.o obj/lista.o obj/graphsearch.o obj/stoper.o
	g++ -o prog obj/main.o obj/graph.o obj/lista.o obj/graphsearch.o obj/stoper.o

obj/main.o: src/main.cpp inc/lista.hh inc/graphsearch.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/stoper.o: src/stoper.cpp inc/stoper.hh
	g++ ${CPPFLAGS} -o obj/stoper.o src/stoper.cpp

obj/graphsearch.o: src/graphsearch.cpp inc/graphsearch.hh inc/graph.hh inc/lista.hh
	g++ ${CPPFLAGS} -o obj/graphsearch.o src/graphsearch.cpp

obj/graph.o: src/graph.cpp inc/graph.hh inc/igraph.hh inc/lista.hh
	g++ ${CPPFLAGS} -o obj/graph.o src/graph.cpp

obj/lista.o: src/lista.cpp inc/lista.hh inc/node.hh
	g++ ${CPPFLAGS} -o obj/lista.o src/lista.cpp

clean:
	rm -f obj/*.o prog

