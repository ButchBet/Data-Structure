/* Work 3: Sorting
    Materia: Data Structure
    Autor: Kevin Alejandro Salazar
    Fecha: 08-09-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream> // cout cin
#include <fstream> // ifsteam / oftream
#include <cstring> // strcpy 
#include <windows.h> // use assembly languaje
#include <vector> //
#include <chrono>

#define Pause cin.get()

using namespace std;

//------------------------------
void UploadData(long *Vector, long Size);

void Swap(int *LeftValue, int *RightValue);

void QuickSort(int *Vector, long First, long Last);

void BubbleSort(int *Vector, long Size);

void InsertionSort(int *Vector, long Size);

void ShellSort(int *Vector, long Size);

void Clear(char Fill);
//---------------------------------

void UploadData(int *Vector, long Size) {
    ifstream Read; // To open, read and close

    Read.open("data.txt");

    if(Read.good()) { // check good opening 1 means successfully 0 not
        // cout<< "The file has been opened successfully"<< endl;

        // Pause;
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


void QuickSort(int *Vector, long First, long Last) {
    long PivotIndex = (First + Last) / 2, // Find the middel value, to cand slice the vector at the center

    Left = First, // Left index

    Right = Last, // Right index

    Pivot = Vector[PivotIndex]; // Center value

    do {
        while(Vector[Left] < Pivot) { Left++; } 

        while(Vector[Right] > Pivot) {Right--; }

        if(Left <= Right) {
            Swap(&Vector[Left], &Vector[Right]); // Change the values

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
}

void BubbleSort(int *Vector, long Size) {
    // for(int i = 0, j = i + 1; i < Size, j < Size; j++) {
    //     if(j size - 1) {

    //     }
    // }

    // for(int i = 0; i < Size; i++) { TODO: Try to create the same structure of down using conditioals instead the nested loop
    //     for(int j = 0; j < Size; j++) {
    //         if(Vector[i] > Vector[j]) {
    //             Swap(&Vector[i], &Vector[j]);
    //         }
    //     }
    // }

    for(int i = 0; i < Size; i++) {
        for(int j = 0; j < Size; j++) {
            if(Vector[j] > Vector[j + 1]) {
                Swap(&Vector[j], &Vector[j + 1]);
            }
        }
    }
}

void InsertionSort(int *Vector, long Size) {
    long i, Position;

    for(i = 0; i < Size; i++) {
        Position = i;

        while(Position > 0 && Vector[Position - 1] > Vector[Position]) {
            
            Swap(&Vector[Position], &Vector[Position - 1]);

            Position--;
        }
    }
}

void ShellSort(int *Vector, long Size) {
    int Gap = Size / 2; // Measure to can control the itereations begin and end

    while(Gap > 0) {
        for(int Route = Gap; Route < Size; Route++) {
            int Index = Route; // To make the elements changes 

            int Buffer = Vector[Route]; // To save the current element (Also can use Index as index)

            while(Index >= Gap && Vector[Index - Gap] > Buffer) {
                Vector[Index] = Vector[Index - Gap];

                Index -= Gap;
            }

            Vector[Index] = Buffer;
        }

        Gap /= 2;
    }
}

void Clear(char Fill = ' ') {
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, Fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

int main() {
    cout<< "*";

    for(int i = 0; i < 79; i++) {
        cout<< "_";
    }

    cout<< "*";

    cout<< "\n|#   Data   |\t\t\t   Time in milliseconds   \t\t\t|"<< endl;

    cout<< "*";

    for(int i = 0; i < 79; i++) {
        cout<< "_";
    }

    cout<< "*";

    cout<< "\n|           |\tQuick\t|\tBubble\t|\tInsertion\t|\tShell\t|";

    for(int i = 0; i < 5; i++) { // To can show from 100 to 1000000
        long long Size = 100, CurrentSize = 10;

        for(int j = 0;  j < i; j++) { // Yo increase the Size value
            Size *= CurrentSize;
        }

        int *Vector = new int[Size]; // Use Size elements space

        UploadData(Vector, Size); // Read the file, open, white inside the array and close

        // Data timing 
        //---------------------------------------------------------------
        auto MainTime = std::chrono::high_resolution_clock::now(); // QS

        QuickSort(Vector, 0, Size - 1); 

        auto LastTime = std::chrono::high_resolution_clock::now();

        cout<< "\n*";

        for(int i = 0; i < 79; i++) {
        cout<< "_";
        }

        cout<< "*";

        if(Size == 100) {
            cout<< "\n| "<< Size <<"       |\t";
        } else if(Size == 1000) {
            cout<< "\n| "<< Size <<"      |\t";
        } else if(Size == 10000) {
            cout<< "\n| "<< Size <<"     |\t";
        } else if(Size == 100000) {
            cout<< "\n| "<< Size <<"    |\t";
        } else {
            cout<< "\n| "<< Size <<"   |\t";
        }
        
        cout<< (LastTime - MainTime) / std::chrono::milliseconds(1) <<"\t|\t";
        //--------------------------------------------------------------------

        //--------------------------------------------------------------------
        MainTime = std::chrono::high_resolution_clock::now(); // BBS

        BubbleSort(Vector, Size);

        LastTime = std::chrono::high_resolution_clock::now();

        cout<< (LastTime - MainTime) / std::chrono::milliseconds(1)  <<"\t|\t     ";

        //----------------------------------------------------------------------

        //----------------------------------------------------------------------
        MainTime = std::chrono::high_resolution_clock::now(); // IS

        InsertionSort(Vector, Size);

        LastTime = std::chrono::high_resolution_clock::now();

        cout<< (LastTime - MainTime) / std::chrono::milliseconds(1)  <<"\t\t|\t";

        //------------------------------------------------------------------------

        //------------------------------------------------------------------------
        MainTime = std::chrono::high_resolution_clock::now(); // SHS

        ShellSort(Vector, Size);

        LastTime = std::chrono::high_resolution_clock::now();

        cout<< (LastTime - MainTime) / std::chrono::milliseconds(1) << "\t|\t";
        //-------------------------------------------------------------------------
    }

    return 0;
}
