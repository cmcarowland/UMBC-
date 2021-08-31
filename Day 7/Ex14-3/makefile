all: Ex14-3 

Ex14-3: Ex14-3.cpp Circle.o
	@echo "Building Ex 14-3"
	@g++ -o Ex14-3 Ex14-3.cpp Circle.o 

Circle.o: Circle.cpp Circle.h
	@echo "Building Circle"
	@g++ -c -o Circle.o Circle.cpp

clean:
	@echo "Cleaning ..."
	rm *.o
	rm Ex14-3
