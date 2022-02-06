struct NodoPila {
    int Cima;

    NodoPila *Sig;
};

NodoPila *Pila,*Aux;

void ingresar (void) {
    if(!Pila)
    {
        Pila = new(struct NodoPila);

        cout<<"Ingrese elemento: ";

        cin>>Pila->Cima;

        Pila->Sig=NULL;

        return;
    }

    Aux= new(struct NodoPila);

    cout<<"\nIngrese elemento: ";

    cin>>Aux->Cima;

    Aux->Sig = Pila;

    Pila = Aux;
}

 

//--------------------------------------------

void sacar(void) {
    if(!Pila)
    {
        cout<<"\n\nNo hay elementos!!";

        return;
    }

    Aux = Pila;

    cout<<"\n\nElemento eliminado: "    <<Aux->Cima;

    Pila = Aux->Sig;

    delete(Aux);
}

 

//------------------------------------------

void mostrarpila(void) {
    Aux = Pila;

    cout<<"\n Datos Apilados\n";

    while(Aux) {
        cout<<Aux->Cima<<endl;

        Aux = Aux->Sig;
    }

}
//*****************************************************************
struct NodoCola {
    int dato;
    
    NodoCola *sig;
}*cola,* aux, *u;
 
 
void insertar () {
    int dat;
    cout<<"ingrese dato:";

    cin>>dat;

    aux = new(struct NodoCola);

    aux->dato=dat;
    
    if(u) {
        u->sig=aux;

        aux->sig = NULL;

        u = aux;
    } else {
        cola = u = aux;
    }

}

//--------------------------------------------

void borrar() {
    if (cola) {
        aux = cola;

        cout<<"\n elimino a"<<cola->dato;

        cola = aux->sig;

        delete (aux);
    } else {
        cout<<"\n no hay datos";
    }
}
//--------------------------------------------
void mostrarcola () {
    if(!u) {
        cout<< "no hay datos en la cola ";
        return;
    }

    aux = cola;

    while(aux) {
        cout<<"\n "<<aux->dato;

        aux = aux->sig;
    }
}


