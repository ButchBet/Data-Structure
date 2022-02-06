/*
     Encrypt string, by now just 
*/

#include <iostream>

using namespace std;

enum LowerLetters { // 
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
    j,
    k,
    l,
    m,
    n,
    o,
    p,
    q,
    r,
    s,
    t,
    u,
    v,
    w,
    x,
    y,
    z
};

//---------------------------------
void Swap(char *LeftValue, char *RightValue);


void QuickSort(char *Vector, long First, long Last);

//-------------------------------
void Swap(char *LeftValue, char *RightValue) {
    char Exchange = *LeftValue;

    *LeftValue = *RightValue;

    *RightValue = Exchange; 
}

void QuickSort(char *Vector, long First, long Last) {
    long PivotIndex = (First + Last) / 2, // Find the middel value, to cand slice the vector at the center

    Left = First, // Left index

    Right = Last; // Right index

    char Pivot = *Vector; // Center value

    do {
        while((int)*(Vector + Left) < (int)Pivot) { Left++; } 

        while((int)*(Vector + Right) > (int)Pivot) {Right--; }

        if(Left <= Right) {
            Swap(Vector + Left, Vector + Right); // Change the values

            Left++;

            Right--;
        }
    }while(Left <= Right);

    if(First < Right) {
        QuickSort(Vector, First, Right);
    }

    if(Left < Last) {
        QuickSort(Vector, Left, Last);
    }

    cout<< "Hello"<< endl;
}

int main() {   
    string *Input = new string; // To save the text

    cout<< "Enter one string, please not numbers.. ";

    cin>> Input;

    coin<< *Input;

    // char *PointedToInput = &Input[0];
    
    // QuickSort(PointedToInput, 0, 5);

    // cout<< Input;
    
    return 0;
}