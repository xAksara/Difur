image: image.o aks_graph.o
	g++ image.o aks_graph.o -o image
	rm *.o

image.o: image.cpp
	gcc -c image.cpp

aks_graph.o: aks_graph.cpp aks_graph.h
	gcc -c aks_graph.cpp

