/* 
    Work name: B,AVL and RB tree implementation
    Subject: Data Structure
    Author: Alejandro Salazar - Stiven Salazar
    Date: 5/11/2021
    Compiler: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream>
#include <vector>
#include "abb.h"
#include "avl.h"
#include "rb.h"

#define PAUSE cin.get();

using namespace std;

ABB BT =  NULL;
AVL AVLT = NULL;
RBT RBTT = NULL;

/* Menu functions */
void MainMenu();
void ABBMenu();
void TreeMenu();

/* sorting and swaping function */
void Swap(int *LeftValue, int *RightValue);
void QuickSort(int *Vector, int First, int Last);

/* Redirection functions */
void ABBMain();
void ABBSecond(ABB &MainRoot , bool OP);
void AVLMain();
void RBMain();
void Redirection();

/* Manipulation */
bool SimilarityBTs();


//------------------------------------------------------------- Menu
void MainMenu() {
    cout<< "1. ABB"<< endl;
    cout<< "2. AVL tree"<< endl;
    cout<< "3. RB tree"<< endl;
    cout<< "4. Exit"<< endl;
    cout<< "--> ";
}

void ABBMenu() {
    cout<< "1. Push"<< endl;
    cout<< "2. Delete tree"<< endl;
    cout<< "3. Search"<< endl;
    cout<< "4. Check"<< endl;
    cout<< "5. Traverse the tree In-order"<< endl;
    cout<< "6. Traverse the tree in Pre-order"<< endl;
    cout<< "7. Traverse the tree in Post-order"<< endl;
    cout<< "8. Tree weight"<< endl;
    cout<< "9. Tree height"<< endl;
    cout<< "10. # of leaves"<< endl;
    cout<< "11. Father of"<< endl;
    cout<< "12. Equality"<< endl;
    cout<< "13. Same form"<< endl;
    cout<< "14. Same items"<< endl;
    cout<< "15. Tree full"<< endl;
    cout<< "16. Level of items"<< endl;
    cout<< "17. # of items at a given level"<< endl;
    cout<< "18. Check if 2 items are cousins"<< endl;
    cout<< "19. Check stability"<< endl;
    cout<< "20. Greater item"<< endl;
    cout<< "21. Items of given level"<< endl;
    cout<< "22. Remove item"<< endl;
    cout<< "23. Back"<< endl;
    cout<< "--> ";
}

void TreeMenu(bool Op) {
    cout<< "1. Push"<< endl;
    
    if(Op) {
        cout<< "2. Delete tree"<< endl;
    } else {
        cout<< "2. Remove item"<< endl;
    }

    cout<< "3. Search"<< endl;
    cout<< "4. Check"<< endl;

    if(Op) {
        cout<< "5. Compare"<< endl;
        cout<< "6. Back"<< endl;
    } else {
        cout<< "5. Back"<< endl;
    }

    cout<< "--> ";
}


// ------------------------------ Sorting 
void Swap(int *LeftValue, int *RightValue) {
    int Excahge = *LeftValue;

    *LeftValue = *RightValue;

    *RightValue = Excahge; 
}


void QuickSort(int *Vector, int First, int Last) {
    int PivotIndex = (First + Last) / 2, // Find the middel value, to cand slice the vector at the center

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

//------------------------------ ABB
void ABBMain() {
    int Option = 0,
        Item = 0,
        lvl = 1,
        weight = 0,
        *Aux = new int[*FTCP],
        i = 0,
        Level = 0;
    
    bool Result = false;

    ABB NewNode = NULL;

    do {
        ABBMenu();

        cin>> Option;

        switch(Option) {
            case 1:
            cout<< "Enter item: "; cin>> Item;

            for(i = 0; i < *FTCP; i++) { // check if the item has been entered already
                if(Item == ArrayFirstTree[i]) {
                    Result = true;
                } 
            }

            if(!Result) {
                for(i = 0; i < *FTCP; i++) {
                    Aux[i] = ArrayFirstTree[i]; // copy array inside aux
                }

                ArrayFirstTree = new int[(*FTCP)++]; // increase the array space

                for(i = 0; i < *FTCP; i++) { // copy aux and the enteres item
                    if(i == (*FTCP)-1) {
                        ArrayFirstTree[i] = Item;
                    } else {
                        ArrayFirstTree[i] = Aux[i];
                    }
                }

                Aux = new int[*FTCP]; // increase the aux space
            }

            insertarBT(BT, Item);

            PAUSE;
            PAUSE;
            break;

            case 2:
            eliminarArbolEntero(BT);

            BT = NULL;

            

            PAUSE;
            PAUSE;
            break;

            case 3:
            cout<< "Enter item to search: "; cin>> Item;
            Result = buscarABB(BT, Item);

            if(Result) {
                cout<< "The item is in the tree";
            } else {
                cout<< "The item isn't in the tree";
            }

            PAUSE;
            PAUSE;
            break;

            case 4:
            verArbolB(BT, 0);

            PAUSE;
            PAUSE;
            break;

            case 5:
            enOrden(BT);

            PAUSE;
            PAUSE;
            break; 
            
            case 6: 
            preOrden(BT);

            PAUSE;
            PAUSE;
            break;

            case 7:
            postOrden(BT);

            PAUSE;
            PAUSE;
            break;

            case 8:
            if(BT != NULL) {
                weight += pesoBT(BT);
            }

            cout<< "The weight of the tree is: "<< weight;

            PAUSE;
            PAUSE;
            break;

            case 9:
            alturaBT(BT, lvl);

            cout<< "The height of the tree is: "<< Level<< endl;

            PAUSE;
            PAUSE;
            break;

            case 10:
            if(BT != NULL) {
                weight += pesoBT(BT);
            }

            cout<< "The h# of leaves: "<< weight<< endl;

            PAUSE;
            PAUSE;
            break;

            case 11:
            cout<< "Enter item: "; cin>> Item;

            if(BT == NULL) {
                cout<< "Actually the tree is empty";
            } else {
                encontrarPadre(BT, Item, -1);
            }

            PAUSE;
            PAUSE;
            break;

            case 12:
            ABBSecond(BT, false);

            PAUSE;
            PAUSE;
            break;

            case 13:
            ABBSecond(BT, false);

            PAUSE;
            PAUSE;
            break;

            case 14:
            ABBSecond(BT, true);

            PAUSE;
            PAUSE;
            break;

            case 15:
            if(arbolLLeno(BT)) {
                cout<< "The tree is full";
            } else {
                cout<< "The tree is not full";
            }

            PAUSE;
            PAUSE;
            break;

            case 16:
            cout<< "Enter item: "; cin>> Item;
            
            Level = getLevel(BT, Item);
            
            if (Level) {
                cout << "Level of "<< Item << " is "<< Level;
            } else {
                cout << Item << " is not present in tree";
            }

            PAUSE;
            PAUSE;
            break;

            case 17:
            cout<< "Enter the level: "; cin>> Level;

            Item = numberItems(BT, Level);

            if(Item == 0) {
                cout<< "There is not any item at that level";
            } else {
                cout<< "The number of item at that level is: "<< Item;
            }


            PAUSE;
            PAUSE;
            break;

            case 18:
            cout<< "Enter item 1 and 2: "; cin>> Item>> Level;

            isCousin(BT, Item, Level);


            PAUSE;
            PAUSE;
            break;

            case 19:
            if(stableTree(BT, BT->nro+1)) {
                if(BT->der == NULL && BT->izq == NULL) {
                    cout<< "The tree just have one element";
                } else {
                    cout<< "This is an stable tree";
                }
            } else {
                cout<< "This isn't an stable tree";
            }

            PAUSE;
            PAUSE;
            break;

            case 20:
            /* Sort and show the last one */
            QuickSort(ArrayFirstTree, 0, (*FTCP)-1);

            cout<< *FTCP<< endl;

            for(i = 0; i < *FTCP; i++) {
                cout<< ArrayFirstTree[i]<< "--> ";
            }
            

            cout<< "The greatest item inside the tree is "<< ArrayFirstTree[(*FTCP)-1];
  
            PAUSE;
            PAUSE;
            break;
            
            
            case 21:
            cout<< "Enter limit level: "; cin>> Level;

            SaveUntilNLevels(BT, 0, Level);
            
            cout<< "{";
            for(i = 0; i < *FTCP; i++) {
                if(i == (*FTCP)-1) {
                    cout<< "}";
                }
                cout<<ArrayFirstTree[i]<< ", ";
            }

            PAUSE;
            PAUSE;
            break;

            case 22:
            cout<< "Enter item: "; cin>> Item;
            eliminar(BT, Item);

            PAUSE;
            PAUSE;
            break;

            case 23:
            eliminarArbolEntero(BT);

            delete BT;

            break;

            default:
            cout<< "Option not avaliable";
            PAUSE;
            PAUSE;

        }

        system("cls");
    }while(Option != 23);
}

void ABBSecond(ABB &MainRoot, bool OP) {
    system("cls");

    int Option = 0,
        Item = 0,
        *Aux = new int[*STCP],
        i = 0;

    ABB NewNode = NULL;

    bool Result = false;

    do {
        TreeMenu(true);

        cin>> Option;

        switch(Option) {
            case 1:
            cout<< "Enter item: "; cin>> Item;

            for(i = 0; i < *STCP; i++) { // check if the item has been entered already
                if(Item == ArraySecondTree[i]) {
                    Result = true;
                } 
            }

            if(!Result) {
                for(i = 0; i < *STCP; i++) {
                    Aux[i] = ArraySecondTree[i]; // copy array inside aux
                }

                ArraySecondTree = new int[(*STCP)++]; // increase the array space

                for(i = 0; i < *STCP; i++) { // copy aux and the enteres item
                    if(i == (*STCP)-1) {
                        ArraySecondTree[i] = Item;
                    } else {
                        ArraySecondTree[i] = Aux[i];
                    }
                }

                Aux = new int[*STCP]; // increase the aux space
            }

            insertarBT(NewNode, Item);

            PAUSE;
            PAUSE;
            break;

            case 2:
            eliminarArbolEntero(NewNode);

            NewNode = NULL;

            PAUSE;
            PAUSE;
            break;

            case 3:
            cout<< "Enter item to search: "; cin>> Item;
            Result = buscarABB(NewNode, Item);

            if(Result) {
                cout<< "The item is in the tree";
            } else {
                cout<< "The item isn't in the tree";
            }

            PAUSE;
            PAUSE;
            break;

            case 4:
            verArbolB(NewNode, 0);

            PAUSE;
            PAUSE;
            break;

            case 5:
                if(OP) {
                    if(*FTCP != *STCP) {
                        cout<< "The size of bots trees are not same";
                    } else {
                        if(SimilarityBTs()) {
                            cout<< "The trees have the same values";
                        } else {
                            cout<< "The trees haven't the same values";
                        }
                    }
                } else {
                    Result = esIgual(MainRoot, NewNode);

                if(Result) {
                    cout<< "Both trees are equal";
                } else {
                    cout<< "Trees are not equal";
                }
                }

            PAUSE;
            PAUSE;
            break;

            case 6:
            eliminarArbolEntero(NewNode);

            *STCP = 0;
            
            ArraySecondTree = new int[*STCP];

            break;

            default:
            cout<< "Option not avaliable";
            PAUSE;
            PAUSE;
        }
        
        system("cls");
    }while(Option != 6);
}

bool SimilarityBTs() {
    int i = 0;

   QuickSort(ArrayFirstTree, 0, (*FTCP)-1); // Sorting first tree

   QuickSort(ArraySecondTree, 0, (*STCP)-1); // Sorting second tree

   for(i = 0; i < *FTCP; i++) { // compare both arrays
       if(ArrayFirstTree[i] != ArraySecondTree[i]) {
           return false;
       }
   }

   return true;
}


//------------------------------ AVL
void AVLMain() { 
    int Option = 0,
        Item = 0;

    AVL NewNode = NULL;

    do {
        TreeMenu(false);

        cin>> Option;

        switch(Option) {
            case 1:
            cout<< "Enter item: "; cin>> Item;

            insertarAVL(AVLT, Item);

            PAUSE;
            PAUSE;
            break;

            case 2:
            cout<< "Enter item: "; cin>> Item;

            eliminarNodo(AVLT, Item);

            PAUSE;
            PAUSE;
            break;

            case 3:
            cout<< "Enter item: "; cin>> Item;

            NewNode = buscar(AVLT, Item);

            PAUSE;
            PAUSE;
            break;

            case 4:
            verArbol(AVLT, 0);

            PAUSE;
            PAUSE;
            break;

            case 5:
            //
            break;

            default:
            cout<< "Option not avaliable";
            PAUSE;
            PAUSE;
        }
        
        system("cls");
    }while(Option != 5);
}

//------------------------------ RB
void RBMain() {
    int Option = 0,
        Item = 0;

    RBT NewNode = NULL;

    do {
        TreeMenu(false);

        cin>> Option;
        
        switch(Option) {
            case 1:
            cout<< "Enter item: "; cin>> Item;

            insertarRB(RBTT, Item);

            PAUSE;
            PAUSE;
            break;

            case 2:
            cout<< "Enter item: "; cin>> Item;

            eliminarRB(RBTT, Item);

            PAUSE;
            PAUSE;
            break;

            case 3:
            cout<< "Enter item: "; cin>> Item;

            NewNode = buscarRB(RBTT, Item);

            PAUSE;
            PAUSE;
            break;

            case 4:
            verArbolRB(RBTT, 0);

            PAUSE;
            PAUSE;
            break;

            case 5:
            //
            break;

            default:
            cout<< "Option not avaliable";
            PAUSE;
            PAUSE;
        }
        
        system("cls");
    }while(Option != 5);
}

int main() {
    int Option = 0;

    do {
        MainMenu();
        cin>> Option;

        system("cls");

        switch(Option) {
            case 1:
            ABBMain();
            break;

            case 2:
            AVLMain();
            break;

            case 3:
            RBMain();
            break;

            case 4:
            //
            break;

            default:
            cout<< "Option not avaliable";
        }

        PAUSE;
        PAUSE;
        system("cls");
    }while(Option != 4);
    
    return 0;
}