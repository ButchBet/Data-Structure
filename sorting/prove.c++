#include <iostream> // cout cin
#include <fstream> // ifsteam
#include <cstring> // strcpy 
#include <windows.h> // use assembly languaje
#include <vector> //


#define Pause cin.get()

using namespace std;

void UploadData(int *Vector, long Size) {
    ifstream Read; // To open, read and close

    Read.open("data.txt");

    if(Read.good()) { // check good opening 1 means successfully 0 not
        cout<< "The file has been opened successfully"<< endl;

        Pause;
    } else {
        cout<< "The file hasn't been opened successfully"<< endl;

        exit(EOF);
    }

    for(int i = 0; i < Size; i++) { // Rading
        Read>> Vector[i];
    }

    Read.close();
}

void Swap(int *LeftValue, int *RightValue) {
    int Excahge = *LeftValue;

    *LeftValue = *RightValue;

    *RightValue = Excahge; 
}


int main() {
    long Size = 100;
    int a = 1, b = 2;
    
    int *Vector = new int[Size];

    UploadData(Vector, Size);

    for(int i = 0; i < Size; i++) {
        cout<< &Vector[i]<< " | ";
    } 

    Pause;

    return 0;
}