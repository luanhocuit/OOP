all : main 

main : main.o DaThuc.o
	g++ main.o DaThuc.o -o main.exe

main.o :
	g++ -c main.cpp

DaThuc.o :
	g++ -c DaThuc.cpp

run :
	./main.exe

clean :
	rm -f *.o *.exe
