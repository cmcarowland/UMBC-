all: Ex15-2 Product.o Movie.h Book.h 

Ex15-2: Ex15-2.cpp Product.o Movie.h Book.h UsedBook.h
	@echo "Building Ex 15-2"
	@g++ -o Ex15-2 Ex15-2.cpp Movie.h Book.h Product.o

Product.o: Product.cpp Product.h
	@echo "Building Product"
	@g++ -c -o Product.o Product.cpp 

clean:
	@echo "Cleaning ..."
	rm *.o
	rm Ex15-2
