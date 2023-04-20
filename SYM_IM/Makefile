obraz: obraz.o aks_graph.o
	g++ obraz.o aks_graph.o -o obraz

obraz.o: obraz.cpp
	gcc -c obraz.cpp

aks_graph.o: aks_graph.cpp aks_graph.h
	gcc -c aks_graph.cpp

clean:
	rm -rf *.o
