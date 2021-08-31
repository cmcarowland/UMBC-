all: Ex15-1 Product.o Movie.h Book.h Album.h 

Ex15-1: Ex15-1.cpp Product.o Movie.h Book.h Album.h
	@echo "Building Ex 15-1"
	@g++ -o Ex15-1 Ex15-1.cpp Movie.h Book.h Product.o

Product.o: Product.cpp Product.h
	@echo "Building Product"
	@g++ -c -o Product.o Product.cpp 

clean:
	@echo "Cleaning ..."
	rm *.o
	rm Ex15-1
