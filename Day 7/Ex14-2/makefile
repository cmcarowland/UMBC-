all: Ex14-1 

Ex14-1: Temp.o Ex14-2.cpp
	@echo "Building Ex 14-2"
	@g++ -o Ex14-2 "Ex14-2.cpp" Temp.o

Temp.o: Temp.cpp Temp.h
	@echo "Building Temp"
	@g++ -c -o Temp.o Temp.cpp

clean:
	@echo "Cleaning ..."
	rm *.o
	rm Ex14-2
