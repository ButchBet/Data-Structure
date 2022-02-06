#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <stdlib.h>


using namespace std;

void Shell(int* elemento, int nElementos);

void QuickSort(int *Vector, long First, long Last);

void Swap(int *LeftValue, int *RightValue);

void Shell(int* elemento, int nElementos)
{
	int intervalo, i,j,k;
	intervalo=nElementos/2;
	while(intervalo>0)
	{
		for(i=intervalo;i<nElementos;i++)
		{
			j=i-intervalo;
			while(j>=0)
			{
				k=j+intervalo;
				if(*(elemento+j)<=*(elemento+k+1))
				{
					j=-1;
				}
				else
				{
					int temp;
					temp=*(elemento+j);
					*(elemento+j) = *(elemento+k);
					*(elemento+k) = temp;
					j-=intervalo;
				}
			}
		}
		intervalo=intervalo/2;
	}

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

int main() {
    int size = 100;
    int *vector = new int[size];

    // Fill the vector
    srand(time(NULL));

    for(int i = 0; i < size; i++) {
        vector[i] = (rand() % 99) + 1;
    } 

    cout<< "The original vetor is {";
    for(int i = 0; i < size; i++) {
        if(i == size -1) {
            cout<< vector[i]<< "}\n\n";
        } else {
            cout<< vector[i]<< ", ";
        }
    } 

    // QuickSort(vector, 0, size - 1);
    Shell(vector, size);

    cout<< "The sorted vetor is {";
    for(int i = 0; i < size; i++) {
        if(i == size -1) {
            cout<< vector[i]<< "}\n\n";
        } else {
            cout<< vector[i]<< ", ";
        }
    } 

    return 0;
}