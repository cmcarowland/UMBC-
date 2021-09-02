# Change Log

## NEW
-  Added linear_search function that returns the index of the first found, returns -1 if not found.
-  Implemented template method for bubble sort.
-  Added function to get the weight at the beginning of each month.
-  Added a function to get the total of all months entered.
-  Added overloading for adding, subtraction, insertion and prefix increment.
-  Completed Ex 16-1
-  Created new class console to handle user input.
-  Created new class Finance to handle calculations of interest over time.
-  Added used book class.
-  Created Media class
-  Created Album class.
-  Added Circle class and header.
-  Created Temp class and replaced all inline sequential code in main with OOP code
-  Completed Ex 14-1
-  Added Ex 14-2 files.

## FIXES
-  Ex16-1 Added exercise description
-  Ex16-2 Added exercise description
-  Refactored code in Book so that author is private and used the getter to get the description and cat used to the end.  Thus preserving the encapsulation of the data.
-  Forgot to put header on the main file for the exercise.  Added the proper header
-  Added proper overriding tags to Movie and book.
-  Upgraded main to use new functionality and implement Album in the menu system.
-  Ex 13-2 Last catch throw to catch anything.
-  Ex 13-2 catch block
-  Ex 13-2 return locations for load_words

## Refactors
- Added Copy constructor and copy assignment to heap array, this complies with the rule of three for RAII.
- Refactored total to use accumulate algorithm.
- Main in Ex16-2.cpp to use the new features.
- Main() to use the new console and finance classes
- Changed main code to use new types and test overriding.
- Updated Book and movie to inherit from media, giving access to the format member.
- updated main() to user the circle object to calculate circle measurements.

## Chores
- Added comments to the Ex 18-1
- Added files for Ex 16-2
