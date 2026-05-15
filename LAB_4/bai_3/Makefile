all : main 

main : main.o Time.o
	g++ main.o Time.o -o main.exe

main.o :
	g++ -c main.cpp

Time.o :
	g++ -c Time.cpp

run :
	./main.exe

clean :
	rm -f *.o *.exe