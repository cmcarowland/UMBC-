all: Ex_7-6 Taxes Console

Ex_7-6: Taxes Console
	@echo "Building Project 7-6.cpp"
	@g++ -o Project7-6 "Project7-6.cpp" Taxes.o console.o

Taxes: Console
	@echo "Building Taxes"
	@g++ -c -o Taxes.o "Taxes.cpp"

Console:
	@echo "Building Console"
	@g++ -c -o console.o console.cpp
