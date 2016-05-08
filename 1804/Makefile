CPPFLAGS= -c -g -std=c++11 -Iinc 


prog: obj/main.o obj/main.o obj/tree.o obj/element.o obj/stoper.o
	g++ -o prog obj/main.o obj/tree.o obj/element.o obj/stoper.o

obj/main.o: src/main.cpp 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tree.o: src/tree.cpp inc/tree.hh inc/element.hh inc/node.hh
	g++ ${CPPFLAGS} -o obj/tree.o src/tree.cpp

obj/element.o: src/element.cpp inc/element.hh
	g++ ${CPPFLAGS} -o obj/element.o src/element.cpp

obj/stoper.o: src/stoper.cpp inc/stoper.hh
	g++ ${CPPFLAGS} -o obj/stoper.o src/stoper.cpp

clean:
	rm -f obj/*.o prog

