#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;


/************
*  Simple random password generator of numbers, lowercase, and uppercase letters
*  Set the size of what you want to generate in console
*  By Jonathan Lukasik 2/3/2016
*  Ive broken 2 things here for the assignment
*  Hints: Look at all the rand() functions
*         Adding numbers to a string
*
*************/
int main()
{
    srand(time(0)); //makes sure numbers you generate are random
    string password = "";
    int passwordSize; //obvious....
    char addChar; //character to add
    int addNum; //number to add
    int upperOrLowerOrNum; //what to add to password
    cout << "Welcome to password gen. " << endl;
    cout << "What size will the password be: ";
    cin >> passwordSize;
    while (passwordSize < 0)
    {
        cout << "Must be a positive int: ";
        cin >> passwordSize;
    }
    for(int i = 0; i < passwordSize; i++)
    {
        int x = rand() % 26; //all 26 letters from a - z
        upperOrLowerOrNum = rand() % 1; // determines what to generate, lowercase letter, uppercase letter, or number
        //generates lowercase numbers from ascii table
        if (upperOrLowerOrNum == 0)
        {
            addChar = (char) (x + 65);
            password += addChar;
        }
        //generates uppercase numbers from ascii table
        else if (upperOrLowerOrNum == 1)
        {
            addChar = (char)(x + 97);
            password += addChar;
        }
        //generates a number 0 - 9
        else if (upperOrLowerOrNum == 2)
        {
            addNum = rand () % 10;
            password += addNum;
        }
    }
    cout << password;
}
