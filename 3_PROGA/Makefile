gomoklin: gomoklin.o my_node.o
	g++ gomoklin.o -o gomoklin
	rm *.o

gomoklin.o: gomoklin.cpp my_node.cpp my_node.h
	gcc -c gomoklin.cpp

my_node.o: my_node.cpp my_node.h
	gcc -c my_node.cpp
