all: Ex16-2 circle.o

Ex16-2: Ex16-2.cpp circle.o
	@echo "Building Ex 16-2"
	@g++ -o Ex16-2 Ex16-2.cpp circle.o

circle.o: circle.cpp circle.h 
	@echo "Building circle.o"
	@g++ -c -o circle.o circle.cpp

clean:
	@echo "Cleaning ..."
	rm *.o
	rm Ex15-2
