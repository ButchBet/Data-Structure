#include <iostream>
#include "./header/TadParcial.h"

using namespace std;

typedef NodoPila *PilaPrincipal;

typedef NodoCola *ColaPrincipal;

// Secondary Methods
void Menu(void);

void Invertir();

int ContarElementos(PilaPrincipal &Pile);

bool Existencia(int Num);

void IngresarInvertido(int Num);

void MostrarParticion(PilaPrincipal &Pile);

void IngresarParticion(PilaPrincipal &Pile, int Num);

void PariticionElementos(int Num);

void MenuParticionelementos(PilaPrincipal &PilaAlta, PilaPrincipal &PilaBaja);

bool ColaAscendente(void);

void Direccion(int Op);


// Coding functions
void Menu() {
    cout<< "Ingresa una opción"<< endl;
    cout<< "1. Ingresar elemento a pila"<< endl;
    cout<< "2. Eliminar elemento de pila"<< endl;
    cout<< "3. Mostrar pila"<< endl;
    cout<< "4. Invertir pila"<< endl;
    cout<< "5. Informar existencia de elemento en pila"<< endl;
    cout<< "6. Generar partición basado en un elemento"<< endl;
    cout<< "7. Ingresar elemento a cola"<< endl;
    cout<< "8. Eliminar elemento de cola"<< endl;
    cout<< "9. Mostrar cola"<< endl;
    cout<< "10. Ordenamiento de cola"<< endl;
    cout<< "11. Insertar elemento en posición especifica dentro de la cola"<< endl;
    cout<< "Otro. Salir"<< endl;
    cout<< "--> ";
}

int main() {
    int Op1;

    do {
        Menu();

        cin>> Op1;
        if(!(Pila) && Op1 != 1) { 
            cout<< "La pila está vacia";
        }else if(!(cola) && Op1 != 1) {
            cout<< "La cola está vacia";
        } else {
            Direccion(Op1);
        }

        cout<< endl;

        system("pause");
        
        system("cls");
    }while(Op1 > 0 && Op1 < 12);

    return 0;
};

void Invertir() {
    PilaPrincipal PilaVieja = Pila;
    
    int Counter = ContarElementos(Pila);

    int *Values = new int[Counter],

        i = 0;

    while(PilaVieja) {
        Values[i] = PilaVieja->Cima;

        PilaVieja = PilaVieja->Sig;

        i++;
    }

    for(i = 0; i < Counter; i++) {
        sacar();
    }

    for(i = Counter - 1; 1 > 0; i--) {
        IngresarInvertido(Values[i]);
    }
}

void IngresarInvertido(int Num) {
    if(!Pila)
    {
        Pila = new(NodoPila);

        Pila->Cima = Num;

        Pila->Sig = NULL;

        return;
    }

    Aux= new(NodoPila);

    Aux->Cima = Num;

    Aux->Sig = Pila;

    Pila = Aux;
}

int ContarElementos(PilaPrincipal &Pile) {
    PilaPrincipal PilaNueva = Pile;

    int i = 0;

    while(PilaNueva) {
        i++;
    }

    return i;
    
}

bool Existencia(int Num) {
    PilaPrincipal PilaNueva = Pila;

    while(PilaNueva) {
        if(PilaNueva->Cima == Num) {
            return true;
        }

        PilaNueva = PilaNueva->Sig;
    }

    return false;
}

void MostrarParticion(PilaPrincipal &Pile) {
    PilaPrincipal PilaNueva = Pile;

    while(PilaNueva) {
        cout<< PilaNueva->Cima;

        PilaNueva = PilaNueva->Sig;
    }
}

void IngresarParticion(PilaPrincipal &Pile, int Num) {
    if(!Pile){
        Pile = new(struct NodoPila);

        Pila->Cima = Num;

        Pila->Sig=NULL;

        return;
    }

    Aux= new(struct NodoPila);

    Aux->Cima = Num;

    Aux->Sig = Pile;

    Pile = Aux;
}

void PariticionElementos(int Num) {
    PilaPrincipal PilaBaja = NULL; // Save the greater elements

    PilaPrincipal PilaAlta = NULL; // Save the lower and equal elemetns

    PilaPrincipal PilaNueva = Pila;

    while(PilaNueva) {
        if(PilaNueva->Cima > Num) {

            IngresarParticion(PilaAlta, PilaNueva->Cima);
        } else {

            IngresarParticion(PilaBaja, PilaNueva->Cima);
        }

        PilaNueva = PilaNueva->Sig;
    }

    MenuParticionelementos(PilaAlta, PilaBaja);
}

void MenuParticionelementos(PilaPrincipal &PilaAlta, PilaPrincipal &PilaBaja) {
    system("cls");

    int Op1;

    do{
        cout<< "Elige pila a observar";
        
        cout<< "\n1. Mostrar pila alta";

        cout<< "\n2. Mostrar pila baja";

        cout<< "\nOtro. Salir";

        cout<< "\nElige una opción...";
        
        cin>> Op1;

        if(Op1 == 1) {
            MostrarParticion(PilaAlta);
        } else if(Op1 == 2) {
            MostrarParticion(PilaBaja);
        }

        system("pause");

        system("cls");
    }while (Op1 > 0 && Op1 < 3);
}

bool ColaAscendente(void) {
    ColaPrincipal NuevaCola = u,
                  ColaContar = u;

    int Num = NuevaCola->dato,
        Contador  = 0,
        Indicador = 0;

        NuevaCola->sig;

    while(ColaContar){
        Contador++;

        ColaContar = ColaContar->sig;
    }

    while(NuevaCola){
        if(Num <= NuevaCola->dato) {
            Indicador++;
        }

        NuevaCola = NuevaCola->sig;
    }

    if(Indicador == Contador - 1) { 
        return true;
    }

    return false;
}

void Direccion(int Op) {
    int Num,
        Check;

    cout<< endl;

    switch(Op) {
        case 1:
            ingresar();        
        break;
        
        case 2:
            sacar();
        break;

        case 3:
            mostrarpila();
        break;

        case 4: 
            Invertir();
        break;

        case 5:
            cout<< "Ingresa elemento a buscar: "; cin>> Num;
            if(Existencia(Num)) {
                cout<< "El elemento está dentro de la pila.";
            } else {
                cout<< "El elemento no está dentro de la pila.";
            }
        break;
        
        case 6:
            cout<< "Ingresa elemento partición: "; cin>> Num;

            PariticionElementos(Num);
        break;

        case 7:
            insertar();
        break;

        case 8:
            borrar();
        break;

        case 9:
            mostrarcola();
        break;

        case 10:
            if(ColaAscendente()) {
                cout<< "La cola se encuentra ordenada ascendentemente.";
            } else {
                cout<< "La cola se encuentra desordenada.";
            }
        break;

        default:
        break;
    }
}