#include <iostream>

using namespace std;

int IndexOfMinimum(char *Input, int StartIndexm, int Size);


int IndexOfMinimum(char *Input, int StartIndex, int Size) {

    int MinValue =  (int)*Input;

    int MinIndex = StartIndex;

    for(int i = StartIndex + 1; i < Size; i++) {
        cout<< (int)*(Input + i)<< " "<< MinValue<< endl;

        if((int)(*(Input + i)) < MinValue) {
            MinIndex = i;

            MinValue = (int)(*(Input + i));
        }
    } 

    return MinIndex;
}; 


int main() {
    string Input;

    char *PointedToInput = &Input[0];

    cout<< "Enter one string, please not numbers.. ";

    cin>> Input;

    int Lower = IndexOfMinimum(&Input[0], 0, Input.length());

    cout<< "The lower index is: "<< Lower;
}