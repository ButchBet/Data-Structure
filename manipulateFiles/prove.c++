#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h> // maloc, realloc

void CargarArchivo(); // Cargar datos del archivo a la estructura
void EscribirArchivo(int Size); // Sobre escribir o escribir archivo

#define Pause cin.get(); // To wait a user action (Pause the window)

using namespace std;

struct Agenda {
    char Apellido[20],

    Nombre[20],

    Direccion[20],

    Ciudad[20],

    TelPart[20],

    TelTrab[20],

    TelMovil[20],

    Email[20];
};



int CantidadElementos = 1;

Agenda *agenda = new Agenda[CantidadElementos]; // Guardar datos de agenda

// t = (Type*)realloc(t, sizeof(Type) * n2); // To rezie the pointer

char Cadena[20];

char *File;

void CargarArchivo() {
    ifstream leer; // Para trabajar el archivo en modo de lectura

    leer.open(File);

    if(leer.good()) { // Check si se ha leido adecuadamente
        cout<< "El archivo se abrió correctamente."<< endl;
    } else {
        cout<< "El archivo no se abrió correctamente"<< endl;

        return;
    }

    Pause;

    int i = 0;

    while(!leer.eof()) { // Mientras no sea el final del archivo
        // Sección para llenar la agenda
        leer>>Cadena;
        strcpy(agenda[i].Apellido, Cadena);

        leer>>Cadena;
        strcpy(agenda[i].Nombre, Cadena);

        leer>>Cadena;
        strcpy(agenda[i].Direccion, Cadena);

        leer>>Cadena;
        strcpy(agenda[i].Ciudad, Cadena);

        leer>>Cadena;
        strcpy(agenda[i].TelPart, Cadena);

        leer>>Cadena;
        strcpy(agenda[i].TelTrab, Cadena);

        leer>>Cadena;
        strcpy(agenda[i].TelMovil, Cadena);

        leer>>Cadena;
        strcpy(agenda[i].Email, Cadena);

        i++;
    }

    leer.close();
}

void EscribirArchivo(int Size) {
    // ofstream escribir; // Para trabajar el archivo en modo de escritura

    for(int i = Size; i < CantidadElementos; i++) { // Lectura tanto de datos para reescritura, escritura de primeros registros o agragado de datos 

        cout<< "Ingrese registro #"<< i+1<< endl;

        cout<< endl<< "Apellido: "; cin>>(agenda + i)->Apellido;

        cout<< endl<< "Nombre: "; cin>>(agenda + i)->Nombre;

        cout<< endl<< "Direccion: "; cin>>(agenda + i)->Direccion;

        cout<< endl<< "Ciudad: "; cin>>(agenda + i)->Ciudad;

        cout<< endl<< "Telefono particular: "; cin>>(agenda + i)->TelPart;

        cout<< endl<< "Telefono del trabajo: "; cin>>(agenda + i)->TelTrab;

        cout<< endl<< "Telefono movil: "; cin>>(agenda + i)->TelMovil;

        cout<< endl<< "Email: "; cin>>(agenda + i)->Email; cout<< endl<< endl;
    } 

    for(int i = Size; i < CantidadElementos; i++) { // Lectura tanto de datos para reescritura, escritura de primeros registros o agragado de datos 

        cout<< "Ingrese registro #"<< i+1<< endl;

        cout<<(agenda + i)->Apellido;

        cout<< " " <<(agenda + i)->Nombre;

        cout<<" "<< (agenda + i)->Direccion;

        cout<<" "<< (agenda + i)->Ciudad;

        cout<<" "<< (agenda + i)->TelPart;

        cout<<" "<< (agenda + i)->TelTrab;

        cout<<" "<< (agenda + i)->TelMovil;

        cout<<" "<< (agenda + i)->Email<< endl<< endl;

    //     cout<<(*(agenda + i))->Apellido;

    //     cout<< " " <<(*(agenda + i))->Nombre;

    //     cout<<" "<< (*(agenda + i))->Direccion;

    //     cout<<" "<< (*(agenda + i))->Ciudad;

    //     cout<<" "<< (*(agenda + i))->TelPart;

    //     cout<<" "<< (*(agenda + i))->TelTrab;

    //     cout<<" "<< (*(agenda + i))->TelMovil;

    //     cout<<" "<< (*(agenda + i))->Email<< endl<< endl;
    // } 

    // escribir.open(File);

    // for(int i = 0; i < CantidadElementos; i ++) { // Escritura de datos en el archivo
    //     escribir<<*(agenda + i)->Apellido;
    //     escribir<<(char)32;

    //     escribir<<*(agenda + i)->Nombre;
    //     escribir<<(char)32;

    //     escribir<<*(agenda + i)->Direccion;
    //     escribir<<(char)32;

    //     escribir<<*(agenda + i)->Ciudad;
    //     escribir<<(char)32;

    //     escribir<<*(agenda + i)->TelPart;
    //     escribir<<(char)32;

    //     escribir<<*(agenda + i)->TelTrab;
    //     escribir<<(char)32;

    //     escribir<<*(agenda + i)->TelMovil;
    //     escribir<<(char)32;

    //     escribir<<*(agenda + i)->Email;
    //     escribir<<(char)32;

    //     escribir<<endl; // Salto de linea
    // }
    // escribir.close();
    }

    cout<< "Ahora vamos a agregar más descripciones al vector"<< endl<< endl;

    Pause;

    int NuevaCantidad = 1;

    int CantidadActual = CantidadElementos;

    CantidadElementos += NuevaCantidad;

    Agenda *NuevoPuntero = new Agenda[CantidadActual];

    for(int i = 0; i < CantidadActual; i++) { // Guardar los datos actuales de la agenda en un arreglo con el mismo tamaño
        strcpy(NuevoPuntero[i].Apellido, agenda[i].Apellido);

        strcpy(NuevoPuntero[i].Nombre, agenda[i].Nombre);

        strcpy(NuevoPuntero[i].Direccion, agenda[i].Direccion);

        strcpy(NuevoPuntero[i].TelMovil, agenda[i].TelMovil);

        strcpy(NuevoPuntero[i].TelTrab, agenda[i].TelTrab);

        strcpy(NuevoPuntero[i].Ciudad, agenda[i].Ciudad);

        strcpy(NuevoPuntero[i].Email, agenda[i].Email);

        strcpy(NuevoPuntero[i].TelPart, agenda[i].TelPart);
    }

    delete[] agenda;

    agenda = new Agenda[CantidadElementos]; // Aumentar el tamaño del arreglo

    for(int i = 0; i < CantidadActual; i++) { // Retornar los datos a la agenda, ahora tiene una estructura extra que será rellenada posteriormente
        strcpy(agenda[i].Apellido, NuevoPuntero[i].Apellido);

        strcpy(agenda[i].Nombre, NuevoPuntero[i].Nombre);

        strcpy(agenda[i].Direccion, NuevoPuntero[i].Direccion);

        strcpy(agenda[i].TelMovil, NuevoPuntero[i].TelMovil);

        strcpy(agenda[i].TelTrab, NuevoPuntero[i].TelTrab);

        strcpy(agenda[i].Ciudad, NuevoPuntero[i].Ciudad);

        strcpy(agenda[i].Email, NuevoPuntero[i].Email);

        strcpy(agenda[i].TelPart, NuevoPuntero[i].TelPart);
    }

    delete[] NuevoPuntero;

    for(int i = CantidadActual; i < CantidadElementos; i++) {
        cout<< "Ingrese registro #"<< i+1<< endl;

        cout<< endl<< "Apellido: "; cin>>(agenda + i)->Apellido;

        cout<< endl<< "Nombre: "; cin>>(agenda + i)->Nombre;

        cout<< endl<< "Direccion: "; cin>>(agenda + i)->Direccion;

        cout<< endl<< "Ciudad: "; cin>>(agenda + i)->Ciudad;

        cout<< endl<< "Telefono particular: "; cin>>(agenda + i)->TelPart;

        cout<< endl<< "Telefono del trabajo: "; cin>>(agenda + i)->TelTrab;

        cout<< endl<< "Telefono movil: "; cin>>(agenda + i)->TelMovil;

        cout<< endl<< "Email: "; cin>>(agenda + i)->Email; cout<< endl<< endl;
    }

    cout<< "El nuevo vector ahora tiene:"<< endl;

    for(int i = Size; i < CantidadElementos; i++) { // Lectura tanto de datos para reescritura, escritura de primeros registros o agragado de datos 

        cout<< "Ingrese registro #"<< i+1<< endl;

        cout<< (agenda + i)->Apellido;

        cout<< " " << (agenda + i)->Nombre;

        cout<<" "<< (agenda + i)->Direccion;

        cout<<" "<< (agenda + i)->Ciudad;

        cout<<" "<< (agenda + i)->TelPart;

        cout<<" "<< (agenda + i)->TelTrab;

        cout<<" "<< (agenda + i)->TelMovil;

        cout<<" "<< (agenda + i)->Email<< endl<< endl;
    }
};

// argc -> contador, argv -> puntero a puntero que 
// guarde las posiciones de a) el ejecutable, b) el archivo a leer
int main(int argc, char **argv) { 
    if(argc != 2) { // Check si se han ingresado 2 elementos, el ejecutable y el archivo a leer
        cout<< "Ingresa un archivo."<< endl;
        exit(EOF);
    }

    File = argv[1];

    // if(argc != 2) { // Check si se han ingresado 2 elementos, el ejecutable y el archivo a leer
    //     cout<< "Ingresa un archivo."<< endl;
    //     exit(EOF);
    // }

    // File = argv[1];

    // // CargarArchivo(); // Enviar el archivo ingresado para cargarlo

    // // Menu();

    // EscribirArchivo(0);

    CargarArchivo();

    for(int i = 0; i < CantidadElementos; i++) { // Lectura tanto de datos para reescritura, escritura de primeros registros o agragado de datos 

        cout<< "Registro #"<< i+1<< endl;

        cout<< (agenda + i)->Apellido;

        cout<< " " << (agenda + i)->Nombre;

        cout<<" "<< (agenda + i)->Direccion;

        cout<<" "<< (agenda + i)->Ciudad;

        cout<<" "<< (agenda + i)->TelPart;

        cout<<" "<< (agenda + i)->TelTrab;

        cout<<" "<< (agenda + i)->TelMovil;

        cout<<" "<< (agenda + i)->Email<< endl<< endl;
    }

    return 0;
}