/* 
    Work name: Binary searching tree (parcial)
    Subject: Data Structure
    Author: Alejandro Salazar - Stiven Salazar
    Date: 21/11/2021
    Compiler: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream>
#include <vector>
#include "abb.h"
#include "avl.h"
#include "rb.h"

#define PAUSE cin.get();

using namespace std;

int BSCounter = 0;

/* Trees */
ABB BT1 =  NULL;
ABB BT2 =  NULL;
ABB BT3 =  NULL;
ABB BT4 =  NULL;
ABB BT5 =  NULL;
ABB BT6 =  NULL;
ABB BT7 =  NULL;
ABB BT8 =  NULL;
ABB BT9 =  NULL;
AVL AVLT1 =  NULL;
AVL AVLT2 =  NULL;
AVL AVLT3 =  NULL;
AVL AVLT4 =  NULL;
AVL AVLT5 =  NULL;
AVL AVLT6 =  NULL;
RBT RBT1 = NULL;
RBT RBT2 = NULL;
RBT RBT3 = NULL;

/* Items */
int firstPointItems[21] = {8, 9, 11, 15, 19, 20, 21, 7, 3, 2, 1,5, 6, 4, 13, 14, 10, 12, 17, 16, 18};
int secondPointItems[9] = {4, 10, 19, 7, 49, 100, 20, 22, 12 };
int ThirdPointItems[11] = {50,25,75,10,40,60,90,35,45,70,42};
int FourthPointItems[13] = {10,75,34,22,64,53,41,5,25,74,20,15,90};
int FiftPointItems[10] = {3, 2, 18, 5, 20, 90, 77, 40, 34, 12};
int SixthPointItems[7] = {4, 5, 7, 2, 1, 3, 6};
int SeventhPointItems[21] = {8, 9, 11,15, 19, 20, 21, 7, 3, 2, 1, 5, 6, 4, 13, 14, 10, 12, 17, 16, 18};
int EightPointItems[16] = {20, 10, 30, 40, 27, 35, 40, 50, 60, 67, 80, 62, 70, 83,  84, 85};
int NinethPointItems[14] = {50, 55, 40, 60, 62, 51, 20, 10, 8, 9, 15, 5, 2, 3};
int TenthPointItems[17] = {10, 8, 15, 18, 14, 20, 3, 4, 2, 9, 20, 25, 7, 16, 29, 28, 26};
/* Diffenrent point of the task */
void Point1(ABB &root);
void Point2(ABB &root);
void Point3(ABB &root);
void Point4(ABB &root);
void Point5(ABB &root1, AVL &root2);
void Point6(AVL &root);
void Point7(ABB &root1, AVL &root2);
void Point8(ABB &root1, AVL &root2, RBT &root3);
void Point9(ABB &root1, AVL &root2, RBT &root3);

// Services 
void Swap(int *LeftValue, int *RightValue);
void QuickSort(int *Vector, long First, long Last);
int BinarySearch(int *Vector, long N, long Key);


//________________________________________________ Diffenrent point of the task
void Point1(ABB & root) {
    for(int i = 0;  i < 21; i++) {
        insertarBT(root, firstPointItems[i]);
    }

    cout<< "Pre-order"<< endl;
    preOrden(root);

    cout<< endl<< endl<< "In-order"<< endl;
    enOrden(root);

    cout<< endl<< endl<< "Post-order"<< endl;
    postOrden(root);
}

void Point2(ABB &root) {
    int lvl = 1,
        weight = 0,
        leaves = 0,
        maxValue = 0;

    for(int i = 0;  i < 9; i++) {
        insertarBT(root, secondPointItems[i]);
    }

    // height
    alturaBT(root, lvl);
    cout<< "Height: "<< Level<< endl;

    // weight
    weight += pesoBT(root);
    cout<< "Weight: "<< weight<< endl;;

    // Number of leaves
    leaves += countLeaves(root);
    cout<< "Leaves: "<< leaves<< endl;

    // Max value
    maxValue += MaxValue(root);
    cout<< "Max value: "<< maxValue;
}

void Point3(ABB &root) {
    int lvl = 1,
        weight = 0,
        leaves = 0,
        maxValue = 0;

    for(int i = 0;  i < 11; i++) {
        insertarBT(root, ThirdPointItems[i]);
    }

    // height
    alturaBT(root, lvl);
    cout<< "Height: "<< Level<< endl;

    // weight
    weight += pesoBT(root);
    cout<< "Weight: "<< weight<< endl;;

    // Number of leaves
    leaves += countLeaves(root);
    cout<< "Leaves: "<< leaves<< endl;

    // Max value
    maxValue += MaxValue(root);
    cout<< "Max value: "<< maxValue;
}

void Point4(ABB &root) {
    int lvl = 1,
        weight = 0,
        leaves = 0,
        maxValue = 0;

    for(int i = 0;  i < 13; i++) {
        insertarBT(root, FourthPointItems[i]);
    }

    // height
    alturaBT(root, lvl);
    cout<< "Height: "<< Level<< endl;

    // weight
    weight += pesoBT(root);
    cout<< "Weight: "<< weight<< endl;;

    // Number of leaves
    leaves += countLeaves(root);
    cout<< "Leaves: "<< leaves<< endl;

    // Max value
    maxValue += MaxValue(root);
    cout<< "Max value: "<< maxValue;
}

void Point5(ABB &root1, AVL &root2) {
    for(int i = 0;  i < 10; i++) {
        insertarAVL(root2, FiftPointItems[i]);
        insertarBT(root1, FiftPointItems[i]);
    }

    // Final disposition AVL
    verArbol(root2, 0);

    // Rotations
    cout<< endl<< "Rotatios: "<< Rotations<< endl<< endl;

    // Final disposition AVL
    verArbolB(root1, 0);
}

void Point6(AVL &root) {
    for(int i = 0;  i < 7; i++) {
        insertarAVL(root, SixthPointItems[i]);
    }
}

void Point7(ABB &root1, AVL &root2) {
    for(int i = 0; i < 21; i++) {
        insertarBT(root1, SeventhPointItems[i]);
    }

    // Check bt 
    verArbolB(root1, 0);
    cout<< endl<< endl;

    // Insert and check AVL tree
    for(int i = 0;  i < 7; i++) {
        insertarAVL(root2, SeventhPointItems[i]);
    }
}

void Point8(ABB &root1, AVL &root2, RBT &root3) {
    // Fill the binary, RB and AVL tree 
    for(int i = 0; i< 16; i++) {
        insertarBT(root1, EightPointItems[i]);
        insertarAVL(root2, EightPointItems[i]);
        insertarRB(root3, EightPointItems[i]);
    }

    // Saved in a list, sorting and binary searching
    QuickSort(EightPointItems, 0, 15);
    BinarySearch(EightPointItems, 16, 85);

    // search ABB, RB and AVL item
    buscarABB(root1, 85);
    buscarRB(root3, 85);
    buscar(root2, 85);

    // Jumps of list, ABB, RB and AVL tree 
    cout<< "Jumps"<< endl;
    cout<< "List: "<< BSCounter<< endl;
    cout<< "ABB tree: "<< JumpsABB<< endl;
    cout<< "RB tree: "<< JumpsRB<< endl;
    cout<< "AVL tree: "<< JumpsAVL<< endl;

    // Re-initialize counters
    BSCounter = 0;
    JumpsABB = 0;
    JumpsRB = 0;
    JumpsAVL = 0;
}

void Point9(ABB &root1, AVL &root2, RBT &root3) {
    // Fill the binary, RB and AVL tree 
    for(int i = 0; i< 14; i++) {
        insertarBT(root1, NinethPointItems[i]);
        insertarAVL(root2, NinethPointItems[i]);
        insertarRB(root3, NinethPointItems[i]);
    }

    // Saved in a list, sorting and binary searching
    QuickSort(NinethPointItems, 0, 15);
    BinarySearch(NinethPointItems, 16, 3);

    // search ABB, RB and AVL item
    buscarABB(root1, 3);
    buscarRB(root3, 3);
    buscar(root2, 3);

    // Jumps of list, ABB, RB and AVL tree 
    cout<< "Jumps"<< endl;
    cout<< "List: "<< BSCounter<< endl;
    cout<< "ABB tree: "<< JumpsABB<< endl;
    cout<< "RB tree: "<< JumpsRB<< endl;
    cout<< "AVL tree: "<< JumpsAVL<< endl;

    // Re-initialize counters
    BSCounter = 0;
    JumpsABB = 0;
    JumpsRB = 0;
    JumpsAVL = 0;
}

void Point10(ABB &root1, AVL &root2, RBT &root3) {
    // Fill the binary, RB and AVL tree 
    for(int i = 0; i< 17; i++) {
        insertarBT(root1, TenthPointItems[i]);
        insertarAVL(root2, TenthPointItems[i]);
        insertarRB(root3, TenthPointItems[i]);
    }

    // Saved in a list, sorting and binary searching
    QuickSort(TenthPointItems, 0, 15);
    BinarySearch(TenthPointItems, 16, 28);

    // search ABB, RB and AVL item
    buscarABB(root1, 26);
    buscarRB(root3, 26);
    buscar(root2, 26);

    // Jumps of list, ABB, RB and AVL tree 
    cout<< "Jumps"<< endl;
    cout<< "List: "<< BSCounter<< endl;
    cout<< "ABB tree: "<< JumpsABB<< endl;
    cout<< "RB tree: "<< JumpsRB<< endl;
    cout<< "AVL tree: "<< JumpsAVL<< endl;

    // Re-initialize counters
    BSCounter = 0;
    JumpsABB = 0;
    JumpsRB = 0;
    JumpsAVL = 0;
}

//________________________________________________  Services 
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

int BinarySearch(int *Vector, long N, long Key) {
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

    return -1; /* Not found element */
}


int main() {
    // Point1(BT1);

    // Point2(BT2);

    // Point3(BT3);

    // Point4(BT4);

    // Point5(BT5, AVLT1);

    // to can check the revalance process you need to change Rebalance bool variable to tree in avl.h
    // Point6(AVLT2);

    // to can check the revalance process you need to change Rebalance bool variable to tree in avl.h    
    // Point7(BT6, AVLT3);

    // To can show if the item was fount then change the Jumping bool variable to tree
    // Point8(BT7, AVLT4, RBT1);

    // Point9(BT8, AVLT5, RBT2);

    // Point10(BT9, AVLT6, RBT3);
    return 0;
}