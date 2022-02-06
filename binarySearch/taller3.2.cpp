/* Work 3.2: Data search (sorted and unsorted vector)
    Materia: Data Structure
    Autor: Kevin Alejandro Salazar
    Fecha: 17-09-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

int BSCounter = 0, 
    SSCounter = 0;

auto MainTime = std::chrono::high_resolution_clock::now(), 
          LastTime = std::chrono::high_resolution_clock::now(); // Measure the ejecutation time
//------------------------------------------------
void FillVector(int *Vector, long Size);

int BinarySearch(int *Vector, long N, long Key);

int SequentialSearch(int *Vector, long Size, long Key);

void Swap(int *LeftValue, int *RightValue);

void QuickSort(int *Vector, long First, long Last);

void VectorCopy(int *Vec1, int* Vec2, long Size);
//-------------------------------------------------


//--------------------------------------------------
void FillVector(int *Vector, long Size) {
    srand((unsigned)time(0)); // The seed to cand generate dinamyc random numbers

    for(int i = 0; i < Size; i++) {
        Vector[i] = (rand() % Size) + 1; // 1 - 99999
    }
}

int BinarySearch(int *Vector, long N, long Key) {
    MainTime = std::chrono::high_resolution_clock::now();
    int Central, Down, Up;

    int CentralValue;

    Down = 0;

    Up = N - 1;

    while (Down <= Up) {
        BSCounter++; // increment the counter to get the quantity of iterations done to find the number

        Central = (Down + Up)/2; /* Indicate the central element */

        CentralValue = Vector[Central]; /* Central index's value */
        
        if (Key == CentralValue) {
            return Central; /* Return the found position */ 
        } else if (Key < CentralValue) {
            Up = Central - 1; /* change to the lower list */
        } else {
            Down = Central + 1; /* change to the upperr list */   
        }
    }

    LastTime = std::chrono::high_resolution_clock::now();

    return -1; /* Not found element */
}

int SequentialSearch(int *Vector, long Size, long Key) {
    MainTime = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < Size; i++) {
        SSCounter++;

        if(Key == Vector[i]) {
            return i;
        }
    }

    LastTime = std::chrono::high_resolution_clock::now();

    return -1;
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

void VectorCopy(int *Vec1, int* Vec2, long Size) {
    for(int i = 0; i < Size; i++) {
        Vec1[i] = Vec2[i];
    }
}
//--------------------------------------------------


int main() {
    const long VectorSize = 100000; // Size of the vector

    const int ToFind = 50; // Number to find

    int *MyVector = new int[VectorSize], // Random vector

    *SortedVector = new int[VectorSize]; // Vector to be sorted

    FillVector(MyVector, VectorSize); // Fill the vector randomlly

    VectorCopy(SortedVector, MyVector, VectorSize); // Copy My vector values in SortedVector

    QuickSort(SortedVector, 0, VectorSize - 1); // Sort Sorted vector

    // Here begin the search

    // For the sorted vector
    int Index = BinarySearch(SortedVector, VectorSize, ToFind);

    if(Index != - 1) {
        cout<< "At the sorted vector "<< ToFind<< " is at the index "<< Index<< "."<< endl<<
        "Time: "<< -1 * ((LastTime - MainTime) / std::chrono::milliseconds(1))<< " milliseconds."<< endl<< 
        "Numbe of iterations: "<< BSCounter<< endl;
    } else {
        cout<< "At the sorted vector "<< ToFind<< " is not found"<< endl<< 
        "Numbe of iterations: "<< BSCounter<< endl;
    }

    cout<< endl<< endl;

    // For the unsorted vector
    Index = SequentialSearch(MyVector, VectorSize, ToFind);

    if(Index != - 1) {
        cout<< "At the uh-sorted vector "<< ToFind<< " is at the index "<< Index<< "."<< endl<< 
        "Time: "<< -1 * ((LastTime - MainTime) / std::chrono::milliseconds(1))<< " milliseconds."<< endl<< 
        "Numbe of iterations: "<< SSCounter<< endl;
    } else {
        cout<< "At the un-sorted vector "<< ToFind<< " is not found"<< endl<< 
        "Numbe of iterations: "<< SSCounter<< endl;
    }
}