all : main

main : main.o Date.o
	g++ main.o Date.o -o main.exe

main.o : 
	g++ -c main.cpp 

Date.o :
	g++ -c Date.cpp

run :
	./main.exe

clean :
	rm -f *.o *.exe