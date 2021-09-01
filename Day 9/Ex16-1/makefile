all: Ex16-1 Console.o Finance.o

Ex16-1: Ex16-1.cpp Console.o Finance.o
	@echo "Building Ex 16-1"
	@g++ -o Ex16-1 Ex16-1.cpp Console.o Finance.o

Console.o: console.cpp
	@echo "Building Console"
	@g++ -c -o Console.o  console.cpp

Finance.o: Finance.cpp Finance.h
	@echo "Building Finance"
	@g++ -c -o Finance.o  Finance.cpp


clean:
	@echo "Cleaning ..."
	rm *.o
	rm Ex15-2
