#include <iostream>
#include <windows.h>
using namespace std;

void validateUserInput(int & firstNum, int & secondNum);
void oddNumbers(int & numB1, int & secondNum);
void sumEvenNumbers(int & sumEven, int & numB1, int & secondNum);
void displaySquareNumbers(int & baseNum, int & squareNum);
void sumSqureOddNumbers(int & sumSquareOdd, int & numD1, int & secondNum);
void displayUppercaseLetters(char & letter);
void restartInput(char & ans, bool & restart);

int main ()
{
    // restart beginning
    bool restart = true;
    while (restart == true)
    {
        system ("cls");

        // variables
        bool validator = true;
        int firstNum = 0;
        int secondNum = 0;
        int numB1 = 0;
        int sumEven = 0;
        int sumSquareOdd = 0;
        int numD1 = 0;
        char ans;
        int baseNum = 1;
        int squareNum = 0;
        char letter = 65;

        //a
        while (validator == true)
        {
            cout << "Enter two positive numbers." << endl;
            cout << "The first number must be less than the second number:" << endl;
            cout << "Enter numbers: ";
            cin >> firstNum >> secondNum;
            validateUserInput(firstNum, secondNum);
            validator = false;
        }
        cout << endl;

        // b
        numB1 = firstNum;
        cout << "Odd integers between " << firstNum << " and " << secondNum << " are:" << endl;
        oddNumbers(numB1,secondNum);
        cout << endl << endl;

        // c
        numB1 = firstNum;
        sumEvenNumbers(sumEven, numB1, secondNum);
        cout << "Sum of even integers between " << firstNum << " and " << secondNum << " = " << sumEven << endl;
        cout << endl;

        // d
        displaySquareNumbers(baseNum, squareNum);

        // e
        numD1 = firstNum;
        sumSqureOddNumbers(sumSquareOdd, numD1, secondNum);
        cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum << " = " << sumSquareOdd << endl;
        cout << endl;

        // f
        displayUppercaseLetters(letter);

        // restart program
        restartInput(ans, restart);
    }
    return 0;
}

// a function
void validateUserInput(int & firstNum, int & secondNum)
{
    bool valid = true;
    while (valid == true)
    {
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl;
            cout << "Incorrect Input." << endl;
            cout << "Please try again." << endl;
            cout << endl;
            cout << "Enter two positive numbers." << endl;
            cout << "The first number must be less than the second number:" << endl;
            cout << "Enter numbers: ";
            cin >> firstNum >> secondNum;
        }
        while (firstNum >= secondNum)
        {
            cout << endl;
            cout << "The first number must be LESS than the second number!" << endl;
            cout << "Please try again. " << endl;
            cout << endl;
            cout << "Enter two positive numbers." << endl;
            cout << "The first number must be less than the second number:" << endl;
            cout << "Enter numbers: ";
            cin >> firstNum >> secondNum;
        }
        while (firstNum < 0 || secondNum < 0)
        {
            cout << endl;
            cout << "No NEGATIVE numbers!" << endl;
            cout << "Please try again. " << endl;
            cout << endl;
            cout << "Enter two positive numbers." << endl;
            cout << "The first number must be less than the second number:" << endl;
            cout << "Enter numbers: ";
            cin >> firstNum >> secondNum;
        }
        valid = false;
    }
}

// b function
void oddNumbers(int & numB1, int & secondNum)
{
    while (numB1 <= secondNum)
    {
        if (numB1 % 2 == 1)
        {
            cout << numB1 << " ";
        }
        numB1++;
    }
}

// c function
void sumEvenNumbers(int & sumEven, int & numB1, int & secondNum)
{
    while (numB1 <= secondNum)
    {
        if (numB1 % 2 == 0)
        {
            sumEven = sumEven + numB1;
        }
        numB1++;
    }
}

// d function
void displaySquareNumbers(int & baseNum, int & squareNum)
{
    cout << "Square number of numbers: " << endl;
    while (baseNum <= 10)
    {
        cout << baseNum << "\t";
        squareNum =  baseNum * baseNum;
        cout << squareNum << endl;
        baseNum++;
    }
    cout << endl;
}

// e function
void sumSqureOddNumbers(int & sumSquareOdd, int & numD1, int & secondNum){
    int numD2 = 0;
    while (numD1 <= secondNum)
    {
        numD2 = numD1;
        if (numD2 % 2 == 1)
        {
            numD2 = numD2 * numD2;
            sumSquareOdd = sumSquareOdd + numD2;
        }
        numD1++;
    }
}

// f function
void displayUppercaseLetters(char & letter)
{
    cout << "Upper case letters are: ";
    while (letter < 91)
    {
        cout << letter << " ";
        letter++;
    }
    cout << endl;
}

// restart function
void restartInput(char & ans, bool & restart)
{
    // body
    cout << "Do you want to repeat this program?" << endl;
    cout << "Y/N" << endl;
    cout << "> ";
    cin >> ans;
    ans = static_cast<char>(toupper(ans));
    while (ans != 'Y' && ans != 'N')
    {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << 1;
        cout << "Do you want to repeat this program?" << endl;
        cout << "Y/N" << endl;
        cout << "> ";
        cin >> ans;
        ans = static_cast<char>(toupper(ans));
    }
    if (ans == 'Y')
    {
        restart = true;
    }
    else
    {
        restart = false;
    }
}
