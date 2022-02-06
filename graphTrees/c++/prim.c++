#include <iostream>
#define n 7 //maximo numero de vertices del grafo
#define max 9999 //valor muy superior al que puede tomar el grafo ponderado

using namespace std;

struct aresta{ //estructura con la que definimos las aristas resultantes del arbol generador de coste minimo
    int ver1;
    int ver2;
};

struct aresta T[n];

void prim (int L[n][n]) {//la funcion requiere como parametro la matriz de adyacencia 
    //Te devolvera la tabla T[n] compuesta por aristas.
    int masproximo[n], distmin[n];
    int min;
    int i,j;
    int c,k;
    int x;

    c=0;
    
    for(i=0;i<n;i++) {
        T[i].ver1=0;
        T[i].ver2=0;
    }

    for(i=0;i<n;i++) {
        masproximo[i]=1;
        distmin[i]=L[i][0];
    }

    cout<< endl;

    for (i=1;i<n;i++) {
        min=max;

        for (j=1;j<n;j++) {
            if(0 <= distmin[j] < min) {
                min = distmin[j];
                k = j;
            }

            T[c].ver1 = masproximo[k];
            T[c].ver2 = k;

            c++;

            distmin[k]=-1;
        }

        for (j=1;j<n;j++) {
            x = L[j][k];
            
            if(x < distmin[j]) {
                distmin[k] = L[j][k];
                masproximo[j] = k;
            }
        }
    }
}

int main() {
    int L[7][7] = {
        {0, 2, 3, 0, 0, 10, 0}, 
        {1, 0, 1, 7, 5, 0, 2}, 
        {3, 1, 0, 9, 3, 0, 0}, 
        {0, 7, 9, 0, 2, 1, 12}, 
        {0, 5, 3, 2, 0, 2, 0}, 
        {10, 0, 0, 1, 2, 0, 0}, 
        {0, 2, 1, 7, 0, 2, 0} 
    };

    prim(L);

    for(int i = 0; i < 7; i++) {
        cout<< T[i].ver1<< " --> "<< T[i].ver2<< endl;
    }
    
    return 0;
}