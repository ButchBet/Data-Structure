#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
/*
Taller de repaso estructura de datos
Autor: Stiven Cardona Salazar
Fecha: 30/08/2021
Lenguaje: C++
Compilador: MinGW y Compile run
*/

//1. Calcular la suma de todos los elementos de un vector
/*Nombre del vector: SumaDeElementosVec
Objetivo: Sumar los elementos del vector 
Parametros: Crear las variables y el vector 
            Ingresar la cantidad de elementos del vector 
            Recorrer el vector con apuntadores
            Sumar cada uno de los elementos del vector 
            Mostrar la suma de los elementos del vector 
*/

void SumaDeElementosVec()
{
    int n,num,suma = 0; 
    cout<<"Ingrese la cantidad de elementos del vector: ";
    cin>>n; 
    int *vector[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Digite un elemento: ";
        cin>>num; 
        vector[i]= &num;
        suma = suma + *vector[i];
    }
    cout<<"Suma de elementos del vector es: "<<suma; 
}

//2.  Indicar si un valor num se encuentra en un vector
/*Nombre del vector: ValorDentroDeUnVector
Objetivo: Indicar si un valor n en se encuentra dentro del vector
Parametros: Crear las variables y el vector 
            Ingresar la cantidad de elementos del vector 
            Recorrer el vector con apuntadores
            Igualar cada uno de los elementos del vector con la variable n
            indicar si el valor se encuentra en el vector
*/
void ValorDentroDeUnVector()
{
    int n,j,VoF = 0;
    int *puntero;
    cout<<"Ingrese el numero que quiere encontrar: ";
    cin>>n;
    puntero = &n;
    int vector[] = {1,5,41,21,2,3,65,63,4,7,33};
    for (int i = 0; i < 11; i++)
    {
        if (vector[i] == *puntero) 
        {
            VoF = 1; 
            j = i; 
        }
    } 
    if (VoF == 1)
    {
        cout<<"El numero buscado  se encuentra en la posicion "<<j<<" del vector ";  
    }
    else
    {
        cout<<"El numero buscado no se encuentra en el vector ";  
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}

// 3. Invertir una cadena apuntada
/*Nombre del vector: InvertirCadena
Objetivo: Invertir una cadena de caracteres
Parametros: Crear un vector que almacene caracteres
            Ingresar la cantidad de elementos del vector 
            Usamos funciones de cadena para invertir la cadena (strrev)
            Mostramos la cadena invertida
*/

void InvertirCadena()
{
    char Nombre1 [200]; //Nombramos variables
    cout<<"Ingrese una palabra para invertir: ";
    gets(Nombre1); //Pedimos ingresar un string gts tambien lee los espacios
    strrev(Nombre1); //strrev es una funcion para invertir cadaenas de caracteres
 
    cout<<"La cadena invertida es: "<<Nombre1;
}

//4. Invertir los elementos de un vector vec de N posiciones, intercambiando el primero con el último, el segundo con el penúltimo y así sucesivamente.
/*Nombre del vector: InvertirElementosVector
Objetivo: Invertir los elementos de un vector
Parametros: Crear un vector que almacene los elementos
            Ingresar la cantidad de elementos del vector 
            Recorremos el vector por apuntadores 
            Tenemos en cuenta la posicion de cada uno de los elementos
            Mostramos el vector original desde posicion 0 a n-1
            Mostramos el vector invertido desde n-1 hasta 0 
*/
void InvertirElementosVector()
{
    int n,num; ///Nombre de variables
    cout<<"Ingrese la cantidad de elementos del vector: ";
    cin>>n; // Recibe la cantidad de elementos del vector                           
    int vector[n],*Puntero;
    Puntero = vector; //
    for (int i = 0; i < n; i++) //ciclo for para digitar los elementos del vector
    {
        
        cout<<"Digite un numero: ";
        cin>>num;
        vector[i] = num; // Almacenamos los elementos del vector
    }
    cout<<"El vector original es: ";
    for (int k = 0; k < n; k++) // ciclo for para mostrar los elementos del vector 
    {
        cout<<"|"<<*Puntero++<<"|";
    }
    Puntero--;
    cout<<"\nEl vector invertido es: ";
    for (int j = n-1; j >= 0; j--) // ciclo for para mostrar los elementos del vector invertido
    {
        cout<<"|"<<*Puntero--<<"|"; 
    }
}

//5. Informar la posición donde aparece por última vez un valor val en un vector (use apuntadores)
/*Nombre del vector: PosicionPuntero
Objetivo: Mostrar la ultima posicion en la que se encuentra un valor
Parametros: Crear un vector que almacene elementos
            Ingresar la cantidad de elementos del vector 
            Recorremos el vector por apuntadores 
            Tenemos en cuenta la posicion de cada uno de los elementos
            Buscamos el valor n en el puntero
            Mostramos la posiion y direccion de memoria donde se encuentra
*/
void PosicionPuntero()
{
    int vector[]={3,3,5,4,7,66,98,3,5,1}; // Vector
    int num, posicion, *puntero; //Nombre de variables
    cout<<"Ingrese un numero: ";
    cin>>num; // Recibe un numero 
    puntero = &num; //Le asignamos la direccion de num a puntero
    for (int i = 0; i < 10; i++) //ciclo for para recorrer el vector 
    {
        if (vector[i] == *puntero) //condiciones para saber la posicion del numero
        {
            posicion = i; // Guardamos la posicion en la variable
        }   
    }
    cout<<"El numero "<<*puntero<<" esta en la posicion "<<posicion<<" Equivalente a "<<&vector[posicion]<<" En memoria ";
}

/*6. Determinar si dos vectores vec1 y vec2 de N posiciones son iguales
/*Nombre del vector: VectoresIguales
Objetivo: Verificar si dos vectores son iguales
Parametros: Crear 2 vectores que almacene n elementos
            Ingresar la cantidad de elementos de los vectores
            Recorremos los dos vectores por apuntadores
            Tenemos en cuenta la posicion de cada uno de los elementos
            Verifiamos si en cada posicion de los vetores coinciden 
            Mostramos si los dos vectores son iguales
*/

void VetoresIguales()
{
    int n,num;
    bool comprobador = true;
    cout<<"Ingrese la cantidad de elementos para los vectores: ";
    cin>>n;
    int *puntero1,*puntero2,vector1[n],vector2[n];
    puntero1 = vector1;
    puntero2 = vector2;
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese un numero para el vector 1: ";
        cin>>num;
        vector1[i] = num;   
    }
    cout<<endl;
    for (int j = 0; j < n; j++)
    {
        cout<<"Ingrese un numero para el vector 2: ";
        cin>>num;
        vector2[j] = num; 
    }
    for (int k = 0; k < n; k++)
    {
        if (*(puntero1 + k) != *(puntero2 + k))
        {
            comprobador = false;
        }
        
    }
    comprobador ? cout<<"Los vectores son iguales " : cout<<"Los vectores no son iguales ";
} 

//7. Eliminar de un vector (usando apuntadores) todas las apariciones de un elemento dado
/*Nombre del vector: EliminarNum
Objetivo: Eliminar un numero dado en las posiciones del vector
Parametros: Crear 1 vector que almacene n elementos
            Ingresar la cantidad de elementos de los vectores
            Recorremos el vectorpor apuntadores
            Buscamos el valor n en el vector  
            Eliminamos el valor n 
*/
void EliminarNum()
{
    int n,num,n1;
    cout<<"Ingrese la cantidad de elementos para los vectores: ";
    cin>>n;
    int *puntero1,vector1[n];
    puntero1 = vector1;

    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese un numero para el vector 1: ";
        cin>>num;
        vector1[i] = num;   
    }
    cout<<"Digite que numero quiere Eliminar: ";
    cin>>n1;
    cout<<endl;
   for (int j = 0; j < n; j++)
   {
       if (*(puntero1 + j) == n1)
       {
           *(puntero1 + j) = 0;
       }
    }
    cout<<endl;
    for (int j = 0; j < n; j++)
   {
      cout<<*(puntero1 + j)<<"|";
      
    }
} 

//8. Elabore una rutina recursiva que imprima los elementos de un vector (use punteros)
/*Nombre del vector: RecursivoPuntero
Objetivo: Hacer una funcion recursiva con punteros para mostrar un vectoe
Parametros: Crear 1 vector que almacene n elementos
            Recorremos el vectores por apuntadores
            Mostramos el vector mediante una funcion recursiva
            
*/

void RecursivoPuntero(int *puntero, int k,int size)
{
    
    cout<<*(puntero + k)<<"|";
    if (k < size - 1)
    {
        RecursivoPuntero(puntero, k+1 ,size);
    }
    
}


//9. Elaborar una rutina recursiva que permita ordenar un vector de forma ascendente
/*Nombre del vector: RecursivoPuntero2
Objetivo: Hacer una funcion recursiva con punteros para mostrar un vectoe
Parametros: Crear 1 vector que almacene n elementos
            Recorremos el vectores por apuntadores
            Mostramos el vector ascendetemente mediante una funcion recursiva
*/



//Funcion de menu;
void menu()
{
    int op, vector1[] = {3,2,1,4,5,7}, size = 6;
    cout<<"BIENVENIDO AL MENU";
    cout<<"\n1. Calcular la suma de todos los elementos de un vector";
    cout<<"\n2. Indicar si un valor num se encuentra en un vector";
    cout<<"\n3. Invertir una cadena apuntada";
    cout<<"\n4. Invertir los elementos de un vector vec de N posiciones, intercambiando el primero con el último, el segundo con el penúltimo y así sucesivamente.";
    cout<<"\n5. Informar la posición donde aparece por última vez un valor val en un vector (use apuntadores)";
    cout<<"\n6. Determinar si dos vectores vec1 y vec2 de N posiciones son iguales";
    cout<<"\n7. Eliminar de un vector (usando apuntadores) todas las apariciones de un elemento dado";
    cout<<"\n8. Elabore una rutina recursiva que imprima los elementos de un vector (use punteros)";
    cout<<"\n9. Elaborar una rutina recursiva que permita ordenar un vector de forma ascendente";
    cout<<"\n10. Para cerrar el programa";
    cout<<"\nIngrese una opcion: ";
    cin>>op;
    cin.ignore ();
switch (op)
{
case 1:
    system("CLS");
    SumaDeElementosVec();
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 2:
    system("CLS");
    ValorDentroDeUnVector();
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 3: 
    system("CLS");
    InvertirCadena();
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 4:
    system("CLS");
    InvertirElementosVector();
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 5:
    system("CLS");
    PosicionPuntero();
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 6:
    system("CLS");
    VetoresIguales();
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 7:
    system("CLS");
    EliminarNum();
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 8:
    system("CLS");
    RecursivoPuntero(vector1,0,size);
    cout<<"\nCambia los valores del vector y su tamaño en el menu";
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
case 9:
    system("CLS");
    cout<<"No fui capaz de solucionarlo ";
    cout<<endl;
    system("pause");
    system("CLS");
    menu();
    break;
default:
    system("CLS");
    cout<<"Gracias por usar la aplicacion.";
    cout<<endl;
    system("pause");
    system("CLS");
    break;
}
	
}

//Funcion principal
int main()
{
    menu();
    getch();
}


