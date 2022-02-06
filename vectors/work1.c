// Work 1
/* Subject: Data structure
   Autor: Kevin Alejandro Salazar
   Fecha: 30-08-2021
   Compilador: gcc.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define clear() printf("\e[1;1H\e[2J")

void Menu(int *P); // Show the main menu 

void ExistenceOfNum(int *P); // Calculate the existence

void RandomNumberGenerator(int *P); // To fill the vector randomly

void Redirec(int *P, int Option); // Control the menu flow
 
void AddVecotorElements(int *P); // Calculate the addition of one vector

void ModificateElementPosition(int *P, int Option); // To reverse or change the positions inside the vector

void LastPositon(int *P); // To find the last position of one number inside a vector

void VectorMatch(int *P); // To comprate two vector and define if are equel or not

void DeleteVector(int *P); // Remove the elements from a vector point indexs

void RecursiveVectorShow(int *P, int RecursiveCounter); // Show a vector with recursion

void RecursiveSort(int *P, int Flow); // Sort a vector using recursion
 
void ShowVector(int *P); // To show the vector with the C sintax = {#, #, #}.....

int Size = 5; // The vector size

int main() {
    int Option = 0; // user menu option

    int *P = malloc(sizeof(int) * 6); // Save the first position of the generated array

    puts("");

    RandomNumberGenerator(P);

    Menu(P);

    printf("\n--> "); scanf("%i", &Option);

    Redirec(P, Option);

    return 0;
}

void Menu(int *P) {
    puts("\nMain menu\n");
    
    printf("What would you like to do with the vector {");

    ShowVector(P); // Show the generatred vector

    puts("\n\n1. Vector addition.");
    
    puts("\n2. Indicate number existence.");
    
    puts("\n3. Reverse.");
    
    puts("\n4. Change elements positions.");
    
    puts("\n5. Show last number position.");

    puts("\n6. Match two vectors.");

    puts("\n7. Remove elements from a vector.");

    puts("\n8. Show vector with recursion.");

    puts("\n9. Show vector ascendingly.");

    puts("\nOther. Exit.");
}

void ExistenceOfNum(int *P) { 
    int Num, // The number to find

    Counter = 0;

    printf("Enter Num: "); scanf("%i", &Num); // Require Num

    puts("");

    for(int i = 0; i < Size; i++) {
        if(*(P + i) == Num) { // Check if the Num is equal o any vectro elements
            printf("%i found at the position %d.\n", Num, i+1);

            Counter++;
        }
    }

    if(Counter == 0) { // check if Num has been found or not
        printf("%i is not inside the vector.", Num);
    }
}

void RandomNumberGenerator(int *P) {
	/*
    static int R[5]; // Vector at case of the first pointer static int G[5]; // Case 
    of he second pointer time_t t; srand((unsigned) time(&t)); // Initializes random 
    number generator if(Operator == 0) { for(int i = 0; i < 5; i++) { // Iterate Size 
    times G[i] = (rand() % 10) + 1; return G; else { for(int i = 0; i < 5; i++) { // 
    Iterate Size times R[i] = (rand() % 10) + 1; return R; */

    srand((unsigned) time(NULL)); // Initializes random number generator

    for(int i = 0; i < Size; i++) {
        *(P + i) = (rand() % 10) + 1;
    }
}

void AddVecotorElements(int *P) {
    int Value = 0; // To save the final addition
    for(int i = 0; i < 5; i++){ // Iterate Size times
        Value += *(P + i); // Add the current Vector[i] value to Value
    }

    printf("The additon is: %i.", Value); // Print the final value
}

void ModificateElementPosition(int *P, int Option) {
    int Vector[Size]; // To save the vector

    for(int i = (Size - 1), k = 0; i >= 0; i--, k++) { // Save the P vecor reversed inside vector
        Vector[k] = *(P + i);
    }

    if(Option == 1) { // Option 3 at the main menu
        printf("The reversed vector is: {");
    } else { // Option 4
        printf("The changed element vector is: {");
    }

    ShowVector(&Vector[0]);
}

void LastPositon(int *P) {
    int Index = -1,

    Num = 0, // Number to find 

    *PNum = &Num; // Point to the number to find

    printf("Enter the number to find: "); scanf("%i", &Num); // Read the number

    for(int i = 0; i < Size; i++) { // Go throught the vector
        if(*PNum == *(P + i)){ // Verify that the input is inside the vector
            Index = i + 1; // Get the current position
        } 
    }

    if(Index == -1) {
        printf("The number %i is no inside the vector", *PNum);
    } else {
        printf("The number %i is at the position %i.", *PNum, Index);
    }
}

void VectorMatch(int *P) {
    int *NewVector = malloc(sizeof(int) * 6),

    Status = 0; // Save the status of the equality, if change means that is different
    
    RandomNumberGenerator(NewVector), // The second vector tocompare

    printf("The new vector is: {");

    ShowVector(NewVector); // Show the second vector

    puts(".");

    for(int i = 0; i < Size; i++) { // Loop to go throught the vectors
        if(*(P + i) != *(NewVector + i)) { // Compare the vector
            printf("The vector {");

            ShowVector(P);

            printf(" != {");

            ShowVector(NewVector);

            puts(".");

            Status++; // Change the status

            break; // Finish the iterations
        } 
    }

    if(Status == 0) { // The vectors match 
        printf("The vetor {");

            ShowVector(P);

            printf(" = {");

            ShowVector(NewVector);

            puts(".");
    }
}

void DeleteVector(int *P) {
    free(P);

    printf("The vector has been cleaned, look /O>O---> {");

    ShowVector(P);
}

void RecursiveVectorShow(int *P, int RecursiveCounter) {
    if(RecursiveCounter == (Size - 1)) { // Stop condition
        printf("%i}", *(P + RecursiveCounter));
    } else { // Recursive condition
        printf("%i,", *(P + RecursiveCounter));

        RecursiveCounter += 1;

        RecursiveVectorShow(P, RecursiveCounter); // Recursive call
    }
}

int ChangeElement = 0,

End = 0; 

void RecursiveSort(int *P, int Flow) {
    if(End == 4) {
        // Here the recursion ends
    } else {
        if(*(P + Flow) > *(P + Flow + 1)) { // Compare the main and adjacent value
            ChangeElement = *(P + Flow); // Save the main value

            *(P + Flow) = *(P + Flow + 1); // Change the main valuo for the adjacent value

            *(P + Flow + 1) = ChangeElement; // Change the adjacent value for the saved value
        } else {
            End += 1;
        }

        Flow += 1; // Increment the flow index

        if(Flow == 4 && End != 4) {
            End = 0; 

            Flow = 0;
        }

        RecursiveSort(P, Flow); // Recursive call
    }
}

void ShowVector(int *P) {
    for(int i = 0; i < Size; i++){ 
        if(i == (Size - 1)){
            printf("%i}", *(P + i));
        } else {
            printf("%i,", *(P + i));
        }
    }
}

void Redirec(int *P, int Option) {
    clear();
    puts("");
    
    switch(Option){
        case 1: 
            AddVecotorElements(P);
            
            main();
            break;
        case 2: 
            ExistenceOfNum(P);
            
            main();
            break;
        case 3:
            ModificateElementPosition(P, 1);
            
            main();
            break;
        case 4:
            ModificateElementPosition(P, 2);
            
            main();
            break;
        case 5:
            LastPositon(P);
            
            main();
            break;
        case 6: 
            VectorMatch(P);
            
            main();
            break;
        case 7: 
            DeleteVector(P);
            
            main();
            break;
        case 8:
            printf("--> {");

            RecursiveVectorShow(P, 0);
            
            main();
            break;
        case 9:
            RecursiveSort(P, 0);

            printf("The vector ascendingly --> {");

            RecursiveVectorShow(P, 0);

            puts(".");
            
            main();
            break;
        default:
            puts("Leaving...");
            break;
    }
}
