/* Work 3.2: Queues data manipulation
    Materia: Data Structure
    Autor: Kevin Alejandro Salazar
    Fecha: 04-09-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

struct Node {
    int Value;

    struct Node *Next;

};

typedef Node *Queues;


// Main methods
void Push(Queues &First, Queues &Last, int Num);

void Pop(Queues &First, Queues &Last);

bool Empty(Queues &First);

void Show(Queues &Queue, Queues &Last);

void Menu();

void Redirect(int Op, Queues &First, Queues &Last);

// Secondary methods 
void Revert(Queues &First, Queues &Last);

bool Existence(Queues &First ,int Num);

bool UpWard(Queues &First);

bool Comparison(Queues &MainFirst, Queues &MainLast, Queues &NewFirst, Queues &NewLast);

int Counter(Queues &First, Queues &Last);




void Menu() {
    cout<< "Enter an option"<< endl;
    cout<< "1. Push"<< endl;
    cout<< "2. Pop"<< endl;
    cout<< "3. Show"<< endl;
    cout<< "4. Revert"<< endl;
    cout<< "5. Existence"<< endl;
    cout<< "6. Ascending"<< endl;
    cout<< "7. Comparison"<< endl;
    cout<< "Other. Leave"<< endl;
    cout<< "--> ";
}

int main() {
    Queues First = NULL;

    Queues Last = NULL;

    int Op1;

    do {
        Menu();

        cin>> Op1;

        if(First == NULL && Op1 != 1) { 
            cout<< "The queue is empty, please fill it first";
        } else {
            Redirect(Op1, First, Last);
        }

        cout<< endl;
        system("pause");
        system("cls");
    }while(Op1 > 0 && Op1 < 8);

    return 0;
};

// TODO: Make a Position counter value
// TODO: Fix seg men error when remove the last element an try to push again
void Push(Queues &First, Queues &Last, int Num) {
    Queues NewQueue = new (struct Node);

    NewQueue->Value = Num;

    NewQueue->Next = NULL;

    if(Empty(First)) {
        First = NewQueue;
    } else {
        Last->Next = NewQueue;
    }

    Last = NewQueue;
}

void Pop(Queues &First, Queues &Last) {
    Queues DeletedNode = First;

    if(First == Last) {
        First == NULL;
        
        Last = NULL;

        cout<< "The queue now is null"<< endl;
    } else {
        First = First->Next;

    }

    delete DeletedNode;
}

bool Empty(Queues &First) {
    return (First == NULL) ? true : false;
}

// TODO: fix infinity loop when remove the last elemet and try to show the queue
void Show(Queues &Queue) {
    Queues NewQueue = Queue;

    int Position = 1; 

    while(NewQueue != NULL) {
        cout<<endl <<"Value:"<< NewQueue->Value<< endl<<"Position: "<< Position<< endl; 

        Position++;

        NewQueue = NewQueue->Next;
    }
}

void Revert(Queues &First, Queues &Last) {
    int Size = 1,
        Index = 0,
        *ValueCopy = new int[Size];
    do{
        cout<< "Hello World"<< Index<< endl;
        ValueCopy[Index] = First->Value; 

        if(First != Last) {
            Index++;

            Size++;

            ValueCopy = new int[Size];
        }

        Pop(First, Last);
    }while(First  != NULL);


    // for(int i = 0, j = Size - 1; i <= j; i++, j--) {
    //     int Aux = ValueCopy[i];

    //     ValueCopy[i] = ValueCopy[j];

    //     ValueCopy[j] = Aux;
    // }

    for(int i = 0; i < Size; i++) {
        cout<< ValueCopy[i]<< endl;
    }


    // for(int k = 0; k < Size - 1; k++) {
    //     Push(First, Last, ValueCopy[k]);
    // }
}

bool Existence(Queues &First ,int Num) {
    Queues NewQueue = First;

    while(NewQueue != NULL) {
        if(NewQueue->Value == Num) {
            return true;
        }

        NewQueue = NewQueue->Next;
    }

    return false;
}

bool UpWard(Queues &First) {
    Queues NewQueue = First;

    int Value = 0;

    while(NewQueue != NULL) {
        Value = NewQueue->Value;

        NewQueue = NewQueue->Next;

        if(NewQueue == NULL) {
            break;
        }

        if(Value > NewQueue->Value) {
            return false;
        }
    }


    return true;
}

bool Comparison(Queues &MainFirst, Queues &MainLast, Queues &NewFirst, Queues &NewLast) {
    Queues MainQueue = MainFirst;

    Queues NewQueue = NewFirst;

    if(Counter(MainQueue, MainLast) != Counter(NewQueue, NewLast)) {
        return false;
    }

    while(!Empty(MainQueue)) {
        if(MainQueue->Value != NewQueue->Value) {
            return false;
        }

        MainQueue = MainQueue->Next;

        NewQueue = NewQueue->Next;
    }

    return true;
}

int Counter(Queues &First, Queues &Last) {
    Queues NewQueue = First;

    int Counter = 0;

    while(!Empty(NewQueue)) {
        Counter++;

        NewQueue = NewQueue->Next;
    }

    return Counter;
}
    
void Redirect(int Op, Queues &First, Queues &Last) {
    int Num,
        Check;

    cout<< endl;

    switch(Op) {
        case 1:
        cout<< "Enter the number to save: "; cin>> Num;
        
        Push(First, Last, Num);
        break;
        
        case 2:
        Check = Last->Value;
        
        Pop(First, Last);

        cout<< "The value "<< Check<< " has been deleted";
        break;

        case 3:
        Show(First);
        break;

        case 4: 
        Revert(First, Last);

        cout<< "The queue has been reverted";
        break;

        case 5:
        cout<< "Enter to find existence: "; cin>> Num;

        if(Existence(First, Num)) {
            cout<< "The value "<< Num<< " is at the queue";
        } else {
            cout<< "The value "<< Num<< " isn´t at the queue";
        }
        break;

        case 6:
        if(UpWard(First)) {
            cout<< "The queue is sorted at upward order";
        } else {
            cout<< "The queue isn´t sorted at upward order";
        }
        break;

        case 7:
        Queues NewQueueFirst = NULL,

               NewQueueLast = NULL;

        int Op1 = 0;

        do {
            cout<< "Enter an option"<< endl;
            cout<< "1. Push"<< endl;
            cout<< "2. Pop"<< endl;
            cout<< "3. Show"<< endl;
            cout<< "3. Compare"<< endl;
            cout<< "Other. Leave"<< endl;
            cin>> Op1;

            if(Op1 >= 5) {
                break;
            }else if(Empty(NewQueueFirst) && Op1 != 1) {
                cout<< "The queue is empty";
            } else if(Op1 == 4){
                if(Comparison(First, Last, NewQueueFirst, NewQueueLast)) {
                    cout<< "The queues are the same";
                } else {
                    cout<< "The queues aren't the same";
                }
            } else {
                Redirect(Op1, NewQueueFirst, NewQueueLast);
            }

            cout<< endl;
            system("pause");
            system("cls");
        }while(Op1 > 0 && Op1 < 5);
    }
}

