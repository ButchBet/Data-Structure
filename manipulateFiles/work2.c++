/* Work 2: Agenda
    Materia: Estructura de datos
    Autor: Kevin Alejandro Salazar
    Fecha: 05-09-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream> //
#include <fstream> //
#include <cstring> //
#include <windows.h> //
#include <stdlib.h> // maloc, realloc

#define Pause cin.get() // To wait a user action (Pause the window)

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

//----------------------------------
void Clear(char fill); // Lismpiar pantalla por medio de lenguaje ensamblador

void CargarArchivo(); // Cargar datos del archivo a la estructura
 
void Menu(); // Menu principal que redirecciona las peticiones igualmente

void Addicionar(); // Agregar un registro nuevo

void ListarDatos(); // Mostrar todos los datos guardados en la estructura 

void BuscarModificarDatos(bool Option); // Buscar datos especificos con el nombre y a apellido
 
void EscribirArchivo(int Size, bool Option); // Sobre escribir o escribir archivo
//---------------------------------------

int CantidadElementos = 1;

Agenda *agenda = new Agenda[CantidadElementos]; // Guardar datos de agenda

// t = (Type*)realloc(t, sizeof(Type) * n2); // To rezie the pointer

char Cadena[20];

char *File;

void Clear(char fill = ' ') { // Limpiar la pantalla utilizando lenguaje ensamblador
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void CargarArchivo() {
    ifstream leer; // Para trabajar el archivo en modo de lectura

    leer.open(File);

    if(leer.good()) { // Check si se ha leido adecuadamente
        cout<< "El archivo se abrió correctamente."<< endl;
    } else {
        cout<< "El archivo no se abrió correctamente"<< endl;

        exit(EOF);
    }

    Pause;

    int i = 0;

    while(!leer.eof()) { // Mientras no sea el final del archivo
        // Sección para llenar la agenda
        leer>>Cadena;

        if(i == 0 && !strcmp(Cadena, " ")) { // En caso de verdadero se redirige a función para realizar escritura
            cout<< "El archivo está vación, procederemos a llenarlo...";

            Pause;

            leer.close();

            EscribirArchivo(0, false);

            CargarArchivo(); // Auto llamado para realizar la relectura del archivo ya modificado

            return;
        } else {
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
    }

    Clear();

    leer.close();
}


void Menu() {
    int Option;

    cout<< "Agenda de registro multifuncional"<< endl;

    cout<< "1. Adicionar registro."<< endl;

    cout<< "2. Listar los datos registrados."<< endl;

    cout<< "3. Buscar datos de registro."<< endl;

    cout<< "4. Modificar datos."<< endl;

    cout<< "5. Sobreescribir todo el archivo (todos los datos guardados se borrarán)."<< endl;

    cout<< "6. Salir"<< endl;

    cout<< "--> "; cin>> Option;
    
    Clear();

    // Redireccionador
    switch(Option) {
        case 1:
            Addicionar();

            break;
        case 2: 
            ListarDatos();

            break;
        case 3: 
            BuscarModificarDatos(false);

            break;
        case 4: 
            BuscarModificarDatos(false);

            break;
        case 5:
            EscribirArchivo(0, false);

            break;
        case 6:
            delete[] agenda;

            fflush(stdin);

            fflush(stdout);

            cout<< "Saliendo...";

            exit(EOF);
        default:
            cout<< "Opcion sin asociación, por favor ingresa un valor valido.";

            break;
    }

    Pause;

    Clear();

    Menu();
}

void Addicionar() {
    int NuevaCantidad, CantidadActual = CantidadElementos;
    cout<< "Ahora vamos a agregar más descripciones al vector"<< endl<< endl;

    Pause;

    cout<< "¿Cuántos registros quiere adicionar?.. "; cin>> NuevaCantidad; 

    CantidadElementos += NuevaCantidad; // Reinicializar la catidad de elementos

    Agenda *NuevaAgenda = new Agenda[CantidadActual]; // Crear el vector para guardar los datos actuales

    for(int i = 0; i < CantidadActual; i++) { // Guardar los datos actuales de la agenda en un arreglo con el mismo tamaño
        strcpy(NuevaAgenda[i].Apellido, agenda[i].Apellido);

        strcpy(NuevaAgenda[i].Nombre, agenda[i].Nombre);

        strcpy(NuevaAgenda[i].Direccion, agenda[i].Direccion);

        strcpy(NuevaAgenda[i].TelMovil, agenda[i].TelMovil);

        strcpy(NuevaAgenda[i].TelTrab, agenda[i].TelTrab);

        strcpy(NuevaAgenda[i].Ciudad, agenda[i].Ciudad);

        strcpy(NuevaAgenda[i].Email, agenda[i].Email);

        strcpy(NuevaAgenda[i].TelPart, agenda[i].TelPart);
    }

    delete[] agenda; // Liberar el espacio de agenda

    agenda = new Agenda[CantidadElementos]; // Re-definir agendad 

    for(int i = 0; i < CantidadActual; i++) { // Retornar los datos a la agenda, ahora tiene una estructura extra que será rellenada posteriormente
        strcpy(agenda[i].Apellido, NuevaAgenda[i].Apellido);

        strcpy(agenda[i].Nombre, NuevaAgenda[i].Nombre);

        strcpy(agenda[i].Direccion, NuevaAgenda[i].Direccion);

        strcpy(agenda[i].TelMovil, NuevaAgenda[i].TelMovil);

        strcpy(agenda[i].TelTrab, NuevaAgenda[i].TelTrab);

        strcpy(agenda[i].Ciudad, NuevaAgenda[i].Ciudad);

        strcpy(agenda[i].Email, NuevaAgenda[i].Email);

        strcpy(agenda[i].TelPart, NuevaAgenda[i].TelPart);
    }

    delete[] NuevaAgenda; // Librearar NuevaAgenda

    EscribirArchivo(CantidadActual, false); 
}

void ListarDatos() {
    for(int i = 0; i < CantidadElementos; i++) {
        cout<< "Registro #"<< i+1<< endl;

        cout<< (agenda + i)->Apellido;

        cout<< " "<< (agenda + i)->Nombre;

        cout<< " "<< (agenda + i)->Direccion;

        cout<< " "<< (agenda + i)->Ciudad;

        cout<< " "<< (agenda + i)->TelPart;

        cout<< " "<< (agenda + i)->TelTrab;

        cout<< " "<< (agenda + i)->TelMovil;

        cout<< " "<< (agenda + i)->Email<< endl<< endl;
    }

    Pause;
}

void BuscarModificarDatos(bool Option) {
    char Nombre[20],

    Apellido[20];

    cout<< "Ingrese el nombre y apellido separado: ";

    cin>> Nombre>> Apellido; // Obtener el nombre y Apellido

    cout<< endl;

    for(int i = 0; i < CantidadElementos; i++) {
        if(!strcmp(Nombre, agenda[i].Nombre) && !strcmp(Apellido, agenda[i].Apellido)){
            if(Option) { // Solo para el caso de que se elija la opción de modificar
                cout<< "Datos actuales del registro"<< endl;
            }

            cout<< "#"<< i+1<< " "<< endl;

            cout<< (agenda + i)->Apellido;

            cout<< " "<< (agenda + i)->Nombre;

            cout<< " "<< (agenda + i)->Direccion;

            cout<< " "<< (agenda + i)->Ciudad;

            cout<< " "<< (agenda + i)->TelPart;

            cout<< " "<< (agenda + i)->TelTrab;

            cout<< " "<< (agenda + i)->TelMovil;

            cout<< " "<< (agenda + i)->Email<< endl<< endl;

            if(Option) { // Solo para el caso de que se elija la opción de modificar
                cout<< "Escribar los datos datos para este registro, por favor itilice el mismo orden que observa arriba."<< endl;

                cin>> (agenda + i)->Apellido>> (agenda + i)->Nombre>> (agenda + i)->Direccion>> (agenda + i)->Ciudad >>
                (agenda + i)->TelPart >>(agenda + i)->TelTrab>> (agenda + i)->TelMovil>> (agenda + i)->Email;
                
                EscribirArchivo(0, true); // Para acutalizar los datos del archivo

                return;
            }
        } 
    }

    Pause;
}

void EscribirArchivo(int Size, bool Option) {
    ofstream escribir; // Para trabajar el archivo en modo de escritura

    if(!Option) {
        for(int i = Size; i < CantidadElementos; i++) { // Lectura tanto de datos para reescritura, escritura de primeros registros o agragado de datos 
            Clear();

            cout<< "Ingrese registro #"<< i+1<< endl;

            cout<< endl<< "Apellido: "; cin>>(agenda + i)->Apellido;

            cout<< endl<< "Nombre: "; cin>>(agenda + i)->Nombre;

            cout<< endl<< "Direccion: "; cin>>(agenda + i)->Direccion;

            cout<< endl<< "Ciudad: "; cin>>(agenda + i)->Ciudad;

            cout<< endl<< "Telefono particular: "; cin>>(agenda + i)->TelPart;

            cout<< endl<< "Telefono del trabajo: "; cin>>(agenda + i)->TelTrab;

            cout<< endl<< "Telefono movil: "; cin>>(agenda + i)->TelMovil;

            cout<< endl<< "Email: "; cin>>(agenda + i)->Email;
        }
    }
     

    escribir.open(File);

    for(int i = 0; i < CantidadElementos; i ++) { // Escritura de datos en el archivo
        escribir<<(agenda + i)->Apellido;
        escribir<<(char)32;

        escribir<<(agenda + i)->Nombre;
        escribir<<(char)32;

        escribir<<(agenda + i)->Direccion;
        escribir<<(char)32;

        escribir<<(agenda + i)->Ciudad;
        escribir<<(char)32;

        escribir<<(agenda + i)->TelPart;
        escribir<<(char)32;

        escribir<<(agenda + i)->TelTrab;
        escribir<<(char)32;

        escribir<<(agenda + i)->TelMovil;
        escribir<<(char)32;

        escribir<<(agenda + i)->Email;
        escribir<<(char)32;

        if(i != CantidadElementos-1) {
            escribir<<endl; // Salto de linea
        }
    }

    escribir.close();
};

// argc -> contador, argv -> puntero a puntero que 
// guarde las posiciones de a) el ejecutable, b) el archivo a leer
int main(int argc, char **argv) { 
    if(argc != 2) { // Check si se han ingresado 2 elementos, el ejecutable y el archivo a leer
        cout<< "Ingresa un archivo."<< endl;
        exit(EOF);
    }

    File = argv[1];

    CargarArchivo(); // Enviar el archivo ingresado para cargarlo

    Menu(); // Mostrar menu

    return 0;
}
