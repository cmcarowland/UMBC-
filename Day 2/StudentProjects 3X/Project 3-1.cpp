/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that converts number grades to letter grades.
 */

#include <iostream>
#include <cmath>

using namespace std;

void PrintLetterGrade(double grade)
{
    char letter;
    cout << "Grade: " << grade << endl;
    if(grade < 0)
    {
        cout << "Numerical grade can't be negative.\n\nBye!" << endl;
        return;
    }
    else if(grade > 100)
    {
        cout << "Numerical grade is too large.\n\nBye!" << endl;
        return;
    }

    if(grade < 60)
    {
        letter = 'F';
    }
    else if(grade >= 60 && grade <= 66)
    {
        letter = 'D';
    }
    else if(grade >= 67 && grade <= 79)
    {
        letter = 'C';
    }
    else if(grade >= 80 && grade <= 87)
    {
        letter = 'B';
    }
    else
    {
        letter = 'A';
    }
    
    cout << "Letter Grade : " << letter << endl;
}

void TestAll()
{
    PrintLetterGrade(59);
    PrintLetterGrade(60);
    PrintLetterGrade(66);
    PrintLetterGrade(67);
    PrintLetterGrade(79);
    PrintLetterGrade(80);
    PrintLetterGrade(87);
    PrintLetterGrade(88);
    PrintLetterGrade(100);
}

int main()
{
    cout << "Letter Grade Converter\n\n";
    //TestAll();
    double grade = 0;
    //PrintLetterGrade();
    cout << "Enter Numerical Grade (0-100) : ";
    cin >> grade;
    
    PrintLetterGrade(grade);
}
