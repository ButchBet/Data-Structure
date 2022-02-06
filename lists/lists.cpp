/* Work 3.2: Linked lists Manipulation
    Materia: Data Structure
    Autor: Kevin Alejandro Salazar
    Fecha: 12-10-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/


#include <iostream>

using namespace std;

struct Node {
    int Value;

    Node *Next;
};

// To control the flow of the list inputs
bool Flag = true; // True: working with upward sorting
                  // False: working with decendently sorting

// Control functions
void Menu();
void Redirect(int Option, Node *&List);

// List manipulations functions
void Push(Node *&List, int n);
void Pop(Node *&List, int Num);
void Show(Node *List);
int Repetitions(Node *List, int Num);
void Revert(Node *&List);
int Average(Node *List);
int Biggest(Node *List);
bool Sorted(Node *List);


int main() {
    int Option;

    Node *List = NULL;

    do {
        Menu();
        cin>> Option;

        if(Option >1 && Option < 9 && List == NULL) {
            cout<< "First fill the list";
        } else {
            Redirect(Option, List);
        }

        cout<< endl;
        system("pause");
        system("cls");
    }while(Option>0 && Option<9);

    return 0;
}

void Menu() {
    cout<< "::Menu::"<< endl;
    cout<< "1. Push"<< endl;
    cout<< "2. Pop"<< endl;
    cout<< "3. Show"<< endl;
    cout<< "4. #Repetitions"<< endl;
    cout<< "5. Revert"<< endl;
    cout<< "6. Average"<< endl;
    cout<< "7. Biggest"<< endl;
    cout<< "8. Sorted"<< endl;
    cout<< "--> ";
}

void Redirect(int Option, Node *&List) {
    int Num = 0, 
        Rep = 0;

    switch(Option) {
        case 1:
        cout<< "Enter number to save: "; cin>> Num;

        Push(List, Num);
        break;

        case 2:
        cout<< "Enter number to be poped: "; cin>> Num;

        Pop(List, Num);
        break;

        case 3:
        Show(List);
        break;

        case 4:
        cout<< "Enter number to search: "; cin>> Num;

        Rep = Repetitions(List, Num);

        cout<< "The number "<< Num<< " is repited "<< Rep << " times.";
        break;

        case 5:
        Revert(List);
        break;

        case 6:
        Num = Average(List);

        cout<< "The average is: "<< Num;
        break;

        case 7:
        Num = Biggest(List);

        cout<< "The biggest number is: "<< Num;
        break;

        case 8:
        if(Flag) {
            cout<< "The list is sorted upwardly";
        } else {
            cout<< "The list is sorted decendently";
        }
        break;

        default:
        break;
    }
}

void Push(Node *&List, int n) {
    Node *NewNode = new Node();

    NewNode->Value = n;

    Node *Aux1 = List;

    Node *Aux2;

    if(Flag) {
        while((Aux1 != NULL) && (Aux1->Value < n)) {
            Aux2 = Aux1;

            Aux1 = Aux1->Next;
        }
    } else {
        while((Aux1 != NULL) && (Aux1->Value >= n)) {
            Aux2 = Aux1;

            Aux1 = Aux1->Next;
        }
    }

    if(List == Aux1) {
        List = NewNode;
    } else {
        Aux2->Next = NewNode;
    }

    NewNode->Next = Aux1;
}

void Pop(Node *&List, int Num) {
    Node *AuxDelete = List;

    Node *Before = NULL;

    while((AuxDelete != NULL) && (AuxDelete->Value != Num)) {
        Before = AuxDelete;

        AuxDelete = AuxDelete->Next;
    }

    if(AuxDelete == NULL) {
        cout<< "The number isn't inside the list";
    } else if(Before == NULL) {
        List = List->Next;

        delete AuxDelete;
    } else {
        Before->Next = AuxDelete->Next;

        delete AuxDelete;
    }
}

void Show(Node *List) {
    Node *Current = List;

    int Index = 0;

    while(Current != NULL) {
        cout<< "Value: "<< Current->Value<< endl;

        cout<< "Position: "<< Index<< endl<< endl;

        Index++;

        Current = Current->Next;
    }
}

int Repetitions(Node *List, int Num) {
    Node *NewNode = List;

    int Rep = 0;

    while(NewNode != NULL) {
        if(NewNode->Value == Num) {
            Rep++;
        }

        NewNode = NewNode->Next;
    }

    return Rep;
}

void Revert(Node *&List) {
    int Counter = 0,

        Size = 0;

    Node *NewNode = List,
         *GetValuesNode = List, 
         *CounterNode = List;

    while(NewNode != NULL) {
        Size++;

        NewNode = NewNode->Next;
    }

    int SaveValuesNode[Size];

    do{ // Save the values inside the dinamyc array
        SaveValuesNode[Counter] = GetValuesNode->Value;

        Counter++;

        GetValuesNode = GetValuesNode->Next;
    }while(GetValuesNode != NULL);

    // Change the Flag method, make list NULL and Fill i again
    if(Flag) {
        Flag = false;
    } else {
        Flag = true;
    }

    List = NULL;

    Counter = 0;

    while(CounterNode != NULL) {
        Push(List, SaveValuesNode[Counter]);

        Counter++;

        CounterNode = CounterNode->Next;
    }
}

int Average(Node *List) {
    Node *NewNode = List;

    int Counter = 0,
        Addition = 0;

    while(NewNode != NULL) {
        Addition += NewNode->Value;

        Counter++;

        NewNode = NewNode->Next;
    }

    Addition /= Counter;

    return Addition;
}

int Biggest(Node *List) {
    Node *NewNode = List;

    int Bigger = NewNode->Value;

    NewNode = NewNode->Next;;

    while(NewNode != NULL) {
        if(Bigger < NewNode->Value) {
            Bigger = NewNode->Value;
        }

        NewNode = NewNode->Next;
    }

    return Bigger;
}