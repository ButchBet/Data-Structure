/* Work 3.2: circular linked simple lists 
    Materia: Data Structure
    Autor: Alejandro Salazar - Stiven Salazar 
    Fecha: 15-10-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream>

using namespace std;


/* structure for a Node */
struct Node {
    int Data;
    Node* Next;
    Node(int x)
    {
        Data = x;
        Next = NULL;
    }
};
 
void PrintList(Node* Head);

void DeleteK(Node** HeadRef, int k);

void InsertNode(Node** HeadRef, int x);

/*Utility function to print the circular linked list*/
void PrintList(Node* Head)
{
    if (Head == NULL)
        return;

    Node* Temp = Head;

    do {
        cout << Temp->Data << "->";

        Temp = Temp->Next;
    } while (Temp != Head);

    cout << "END" << endl;
}
 
/*Function to delete every kth Node*/
void DeleteK(Node** HeadRef, int k)
{
    Node* Head = *HeadRef;
 
    // If list is empty, simply return.
    if (Head == NULL)
        return;
 
    // take two pointers - current, previous and the last
    Node *Curr = Head, *Prev, *Last = Head;

    while(Last->Next != Head) {
        Last = Last->Next;
    }

    while (true) {
 
        // Check if Node is the only two nodes
        // If yes, we reached the goal, therefore
        // return.
        if (Head->Next == Last) {
            break;
        }
 
        // Print intermediate list.
        PrintList(Head);
 
        // If more than one Node present in the list,
        // Make previous pointer point to current
        // Iterate current pointer k times,
        // i.e. current Node is to be deleted.
        for (int i = 0; i < k; i++) {
            Prev = Curr;

            Curr = Curr->Next;
        }
 
        // If Node to be deleted is head
        if (Curr == Head) {
            Prev = Head;

            while (Prev->Next != Head)
                Prev = Prev->Next;
            Head = Curr->Next;

            Prev->Next = Head;

            *HeadRef = Head;
        }
 
        // If Node to be deleted is last Node.
        else if (Curr->Next == Head) {
            Last = Prev;
            
            Prev->Next = Head;
        }
        else {
            Prev->Next = Curr->Next;
        }

        delete Curr;

        Curr = Prev;
    }
}
 
/* Function to insert a Node at the end of a Circular linked list */
void InsertNode(Node** HeadRef, int x)
{
    // Create a new Node
    Node* Head = *HeadRef;

    Node* Temp = new Node(x);
 
    // if the list is empty, make the new Node head
    // Also, it will point to itself.
    if (Head == NULL) {
        Temp->Next = Temp;

        *HeadRef = Temp;
    }
 
    // traverse the list to reach the last Node
    // and insert the Node
    else {
        Node* Temp1 = Head;

        while (Temp1->Next != Head)

            Temp1 = Temp1->Next;

        Temp1->Next = Temp;
        Temp->Next = Head;
    }
}
 

int main()
{
   struct Node *Head = NULL;

   int Pattern;
  
   for(int i = 0; i < 40; i++) { // Fill the list 
       InsertNode(&Head, i+1);
   }

   cout<< "Enter the deletion pattern: "; cin>> Pattern;

   DeleteK(&Head, Pattern);

   PrintList(Head); // Show the last two nodes
}