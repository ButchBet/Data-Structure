/* Work 3: Structure Date TDA
    Materia: Data Structure
    Autor: Kevin Alejandro Salazar
    Fecha: 23-09-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/


#include <iostream>
#include <windows.h>

using namespace std;

//-----------------------------------------
typedef struct {
    int dd;

    int mm;

    int yyyy;

    bool Leap = false;
} Date;

// TODO: Create a enum structure to save the monts nanes begining with 0 as January and 11 as December


//------------------------------------------
Date *date = new Date;

//------------------------------------------
void CatchDate(Date *date, int aa, int mm, int yyyy); // Initialize every object property

bool DateValidation(int dd, int mm, int yyyy); // Check the date

void Clear(char); // Clear the window with assembly language


//------------------------------------------
void CatchDate(Date *date, int dd, int mm, int yyyy) { 
    date->dd = dd;

    date->mm = mm;

    date->yyyy = yyyy;

    if(yyyy % 4 == 0) { // Means a leap year
        date->Leap = true;
    }

    cout<< "The date has been catched...";

    cin.get();
    
    Clear(' ');
}

bool DateValidation(int dd, int mm, int yyyy) {
    if(dd <= 0) { // Don't have to use dd > 0 at other posible comparisons
        return false;
    }

    int LastAs31[7] = {1,3,5,7,8,10,12}; // Months that has 31 as last day

    int LastAs30[4] = {4,6,9,11}; // Months that has 30 as last day

    if(mm > 0 && mm <= 12) { // First check the monts
        if(mm = 2) {
            if(yyyy % 4 == 0) { // Check for a leap day
                if(dd <= 28) {
                    return true;
                }
            } else if(dd <= 29) {
                return true;
            }
        }

        for(int i = 0; i < 7; i++) { // For the LastAs31 array 
            if(mm == LastAs31[i]) {
                if(dd <= 31) {
                    return true;
                }
            }
        }

        for(int i = 0; i < 4; i++) { // For the LastAs30 array 
            if(mm == LastAs30[i]) {
                if(dd <= 30) {
                    return true;
                }
            }
        }
    }

    return false;
}

void Clear(char fill = ' ') {
    COORD tl = {0,0}; // x=0, y=0, the fill position

    CONSOLE_SCREEN_BUFFER_INFO s; // To get the with and height with x adn y axse

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // Retrieves a handle to the specified standard device (standard input, standard output, or standard error

    GetConsoleScreenBufferInfo(console, &s);

    DWORD written, cells = s.dwSize.X * s.dwSize.Y;

    FillConsoleOutputCharacter(console, fill, cells, tl, &written);

    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);

    SetConsoleCursorPosition(console, tl);
}



int main() {
    int day, month, year;

    cout<< "Please enter the day, month and year like this (dd mm yyyy) or (day month year): ";

    cin>> day>> month>> year;

    // Now check the avaliavility12
    if(DateValidation(day, month, year)) {
        cout<< "Validation correct...";

        cin.get();
        cin.get();

        CatchDate(date, day, month, year);
    } else {
        cout<< "The date has incorrect format or is wrong, please try again...";

        cin.get();
        cin.get();

        Clear(' ');

        main();
    }

    // Check the saved date
    // cout<< 
    // "The saved date is "<< 
    // date->dd<< 
    // " "<<
    // date->mm<< 
    // " "<< 
    // date->yyyy<<
    // endl<<
    // "Leap year?: "<<
    // date->Leap;

    return 0;
}