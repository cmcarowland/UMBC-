all: Ex14-1 

Ex14-1: Die.o Dice.o Ex14-1.cpp
	@echo "Building Ex 14-1"
	@g++ -o Ex14-1 "Ex14-1.cpp" Die.o Dice.o

Die.o: Die.cpp Die.h
	@echo "Building Die"
	@g++ -c -o Die.o Die.cpp

Dice.o: Dice.cpp Dice.h
	@echo "Building Dice"
	@g++ -c -o Dice.o Dice.cpp

clean:
	@echo "Cleaning ..."
	rm *.o
	rm Ex14-1
