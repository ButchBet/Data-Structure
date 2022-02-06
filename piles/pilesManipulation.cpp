/* Work 3.2: Piles Manipulation
    Materia: Data Structure
    Autor: Kevin Alejandro Salazar
    Fecha: 17-09-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Node
struct Node{
    int Value, 

    Position;

    struct Node *Next;
};

// Properties
typedef Node *MainNode;

int Status = 0, // To know which pile is manipulated
                /* 0 = Main pile
                   1 = Secondary pile
                   2 = First of the 11 problems piles
                   3 = Second of the 11 problems piles*/

    MainPosition = 0, // For the main pile

    SecPosition = 0, // For the Pile of the problem 4

    SubMainPosition = 0, // For the Greater pile

    SubSecPosition = 0; // For the lower and equal pile

// Main methods
void Push(MainNode &Pile, int Num); 

int Pop(MainNode &Pile);

void ShowPile(MainNode &Pile);

void DeletePile(MainNode &Pile);

void Menu(int Reference);

// Secondary methods
void Revert(MainNode &Pile);

bool Existence(MainNode &Pile, int Num, int Op);

bool Order(MainNode &Pile);

bool Compare(MainNode &Pile, MainNode &NewPile);

void PushAtPPosition(MainNode &Pile, int P, int Num);

void PullApartElements(MainNode &Pile, int Num);

void PullApartElementsMain(MainNode &GreaterNode, MainNode &LowerEqualNode);

void Redirect(MainNode &Pile, int Option);

// int PileSize(MainNode &Pile);

// Building
int main() {
    MainNode Pile = NULL;

    MainNode NewPile = NULL; // Second pile to compare

    int Num, Op, X, Size, Pos;

    system("color 0b");

    do {

        Status = 0;

        cout<< endl;

        Menu(0); cin>> Op;

        if(Op != 1 && Pile == NULL) {
            cout<< "The pile is empty..";
        } else {
            Redirect(Pile, Op);

            switch(Op){
                case 6:
                    cout<< "\nNumber to find: "; cin>> Num;

                    cout<< endl;

                    if(Existence(Pile, Num, 0)) {
                        cout<< "The pile has this number";
                    } else {
                        cout<< "The pile doesn't have this number";
                    }
                    break;
                case 7:
                    if(Order(Pile)) {
                        cout<< "\nThe pile is sorted in ascending order.";
                    } else {
                        cout<< "\nThe pile is't sorted in ascending order.";
                    }
                    break;
                case 8:
                    int NewOp;

                    Status = 1;

                    system("cls");

                    do {
                        cout<< "This menu is used for the second pile, if you enter another number it just comeback to the main menu"<< endl;
                        Menu(1); cin>> NewOp;

                        cout<< endl;

                        if(NewOp != 1 && NewPile == NULL) {
                            cout<< "The new pile is empty..";
                        } else {
                            Redirect(NewPile, NewOp);

                            switch (NewOp) {
                            case 6: 
                                if(Compare(Pile, NewPile)) {
                                    cout<< "The pileas match";
                                } else {
                                    cout<< "The piles doesn't match";
                                }
                            break;

                            default: 
                                Status = 0;
                            }
                        }

                        cout<< endl<< endl; system("pause"); system("cls");
                    }while(NewOp > 0 && NewOp < 7);
                break;

                case 9:
                    cout<< "\nNumber to take out: "; cin>> Num;

                    Existence(Pile, Num, 1);

                    cout<< "\nElement "<< Num<< " has been taken out.";
                break;

                case 10:
                    cout<< "\nEnter the number and the position, remeber that goes down-top: "; cin>> Num>> Pos;

                    PushAtPPosition(Pile, Pos, Num);

                    cout<< "\nElement "<< Num<< " has been added at "<< Pos<< " position";
                break;

                case 11:
                    cout<< "\nEnter the partition number: "; cin>> Num;

                    PullApartElements(Pile, Num);

                    Status = 0;
                break;
            }
        }

        cout<< endl<< endl; 
        
        system("pause"); 
        
        system("cls");
    }while(Op > 0 && Op < 12);

    return 0;
}

void Push(MainNode &Pile, int Num) {
    MainNode NewNode = new (struct Node); 

    NewNode->Value = Num;

    if(Status == 0) {
        MainPosition++;

        NewNode->Position = MainPosition;
    } else if(Status == 1) {
        SecPosition++;

        NewNode->Position = SecPosition;
    } else if(Status == 2) { 
        SubMainPosition++;

        NewNode->Position = SubMainPosition;
    } else {
        SubSecPosition++;

        NewNode->Position = SubSecPosition;
    }

    NewNode->Next = Pile;

    Pile = NewNode;
}

int Pop(MainNode &Pile) {
    int Num; // Save the number deleted

    MainNode NewNode = Pile; 

    Num = NewNode->Value; 

    Pile = NewNode->Next;

    delete(NewNode); 

    if(Status == 0) {
        MainPosition--;
    } else if(Status == 1) {
        SecPosition--;
    } else if(Status == 2) { 
        SubMainPosition--;
    } else {
        SubSecPosition--;
    }

    return Num;
}

void ShowPile(MainNode &Pile) {
    MainNode NewNode = Pile; 

    while(NewNode != NULL) {
        cout<< endl<< NewNode->Value;

        NewNode = NewNode->Next;
    }
}

void DeletePile(MainNode &Pile) {
    MainNode NewNode;

    while(Pile != NULL) {
        NewNode = Pile;

        Pile = Pile->Next;

        delete(NewNode);
    }

    if(Status == 0) {
        MainPosition = 0;
    } else if(Status == 1) {
        SecPosition = 0;
    } else if(Status == 2) { 
        SubMainPosition = 0;
    } else {
        SubSecPosition = 0;
    }
}

void Menu(int Reference) {
    cout<< "\n\t Piles implementation in C++\n\n";
    cout<< "1. Push"<< endl;

    cout<< "2. Pop"<< endl;

    cout<< "3. Show"<< endl;

    cout<< "4. Revert"<< endl;

    cout<< "5. Delete"<< endl;
    
    if(Reference == 0) {
        cout<< "6. Find existence"<< endl;

        cout<< "7. Check ascending organization"<< endl;

        cout<< "8. Check equality bettween two piles"<< endl;

        cout<< "9. Take out element"<< endl;

        cout<< "10. Push element at specific position"<< endl;

        cout<< "11. Clasificate elements"<< endl;
    } else if(Reference == 1){
        cout<< "6. Compare\n";
    }
    
    cout<< "other. Leave"<< endl;

    cout<< "Enter option: ";
}


void Revert(MainNode &Pile) {
    MainNode OldNode = Pile;
    
    int *Values = new int[MainPosition],

        Counter = 0,

        i = 0;

    if(Status == 0) {
        Counter = MainPosition;
    } else if(Status == 1) {
        Values = new int[SecPosition];

        Counter = SecPosition;
    } else if(Status == 2) {
        Values = new int[SubMainPosition];

        Counter = SubMainPosition;
    } else {
        Values = new int[SubSecPosition];

        Counter = SubSecPosition;
    }

    while(OldNode != NULL) { // Save values and positions
        Values[i] = OldNode->Value;

        OldNode = OldNode->Next;

        i++;
    }

    DeletePile(Pile);

    for(i = 0; i < Counter; i++) { // Form the last to the first values
        Push(Pile, Values[i]);
    }
}

bool Existence(MainNode &Pile, int Num, int Op) {
    MainNode NewNode = Pile;

    int Size = 0,

    i = 0,
    
    *Array = (int*)malloc(Size*sizeof(int));

    while(NewNode != NULL) {
        if(Op > 0) { // Happens when whe whant to find and delete an element
            if(NewNode->Value != Num) {
                Size++;

                Array = (int*)realloc(Array, Size*sizeof(int));

                Array[i] = NewNode->Value;

                i++;
            }
        } else if(NewNode->Value == Num) { // Just for the case where we whant to know about existence
            return true;
        }

        NewNode = NewNode->Next;
    }

    if(Op > 0) {
        DeletePile(Pile);

        for(int i = 0; i < Size; i++) {
            Push(Pile, Array[i]);
        }

        Revert(Pile);
    }

    return false;
}

bool Order(MainNode &Pile) {
    MainNode NewNode = Pile;

    int Value = NewNode->Value;

    int i = 0;

    NewNode = NewNode->Next;

    while(NewNode != NULL) { 
        if(Value <= NewNode->Value) { 
            Value = NewNode->Value;-

            i++;
        }

        NewNode = NewNode->Next;
    }

    if(i == MainPosition - 1) { // The max iterations is MainPosition - 1, that means that is in ascending order
        return true; 
    } else {
        return false;
    }
}

bool Compare(MainNode &Pile, MainNode &NewNode) {
    if(MainPosition == SecPosition) { // The two counters has to be equall; to have the same quantity of elements

        MainNode FirstPile = Pile;

        MainNode SecondPile = NewNode;

        int Counter = 0;

        while(FirstPile != NULL) {
            if(FirstPile->Value == SecondPile->Value) {
                Counter++;
            }

            FirstPile = FirstPile->Next;

            SecondPile = SecondPile->Next;
        }

        if(Counter == MainPosition) { // 
            return true;
        }
    }

    return false;
}

void 
PushAtPPosition(MainNode &Pile, int P, int Num) {
    MainNode NewNode = Pile;

    int Array[MainPosition + 1], 
        i = 0, 
        Counter = MainPosition + 1;


    while(NewNode != NULL) { // The normal values
        if(P == NewNode->Position) {
            Array[i] = NewNode->Value;

            i++;

            Array[i] = Num;
        } else {
            Array[i] = NewNode->Value;
        }

        i++;

        NewNode = NewNode->Next;
    }   

    DeletePile(Pile);

    for(int i = 0; i < Counter; i++) {
        Push(Pile, Array[i]);
    }

    Revert(Pile);
}

void PullApartElements(MainNode &Pile, int Num) {
    MainNode GreaterNode = NULL; // Save the greater elements

    MainNode LowerEqualNode = NULL; // Save the lower and equal elemetns

    MainNode NewNode = Pile;

    while(NewNode != NULL) {
        if(NewNode->Value > Num) {
            Status = 2;

            Push(GreaterNode, NewNode->Value);
        } else {
            Status = 3;

            Push(LowerEqualNode, NewNode->Value);
        }

        NewNode = NewNode->Next;
    }

    PullApartElementsMain(GreaterNode, LowerEqualNode);
}

void PullApartElementsMain(MainNode &GreaterNode, MainNode &LowerEqualNode) {
    system("cls");

    int Op1, Op2;

    do{
        cout<< "Choose the pile methods";
        
        cout<< "\n1. Greater pile";

        cout<< "\n2. Lower pile";

        cout<< "\nOther. Leave";

        cout<< "\nChoose an option...";
        
        cin>> Op1;

        if(Op1 == 1) {
            Menu(2);

            cin>> Op2;

            Redirect(GreaterNode, Op2);
        } else if(Op1 == 2) {
            Menu(2);

            cin>> Op2;

            Redirect(LowerEqualNode, Op2);
        } else {
            break;
        }

        system("pause");

        system("cls");
    }while (Op1 > 0 && Op1 < 3);
}

void Redirect(MainNode &Pile, int Option) {
    int Num;

    switch(Option) {
        case 1:
            cout<< "Number to stack: "; cin>> Num;

            Push(Pile, Num);

            cout<< "\nThe number has been added successfully";
        break;

        case 2:
            Pop(Pile);

            cout<< "\nThe pile has been un-stacked successfully";
        break;

        case 3:
            ShowPile(Pile);
        break;
        
        case 4:
            Revert(Pile);

            cout<< "\nThe pile has been reverted successfully";
        break;

        case 5:
            DeletePile(Pile);

            cout<< "\nThe pile has been deleted successfully";
        break;
    }
}