all : main 

main : main.o Vector.o
	g++ main.o Vector.o -o main.exe

main.o :
	g++ -c main.cpp

Vector.o :
	g++ -c Vector.cpp

run :
	./main.exe

clean :
	rm -f *.o *.exe
