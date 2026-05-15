all : main

main : main.o PhanSo.o
	g++ main.o PhanSo.o -o main.exe

main.o : 
	g++ -c main.cpp 

PhanSo.o :
	g++ -c PhanSo.cpp

run :
	./main.exe

clean :
	rm -f *.o *.exe