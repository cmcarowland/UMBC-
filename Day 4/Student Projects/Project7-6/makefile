all: Project7-6

Project7-6: taxes.o console.o
	@echo "Building Project 7-6.cpp"
	@g++ -o Project7-6 "Project7-6.cpp" taxes.o console.o

taxes.o: console.o
	@echo "Building Taxes"
	@g++ -c -o taxes.o "Taxes.cpp"

console.o:
	@echo "Building Console"
	@g++ -c -o console.o console.cpp

clean:
	@echo "Cleaning ..."
	rm *.o
	rm Project7-6
