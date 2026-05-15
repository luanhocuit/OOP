all : main

main : main.o SoPhuc.o
	g++ main.o SoPhuc.o -o main.exe

main.o : 
	g++ -c main.cpp 

SoPhuc.o :
	g++ -c SoPhuc.cpp

run :
	./main.exe

clean :
	rm -f *.o *.exe