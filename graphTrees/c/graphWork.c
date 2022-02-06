#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADgrafo.h"
#include "dijkstra.h"


#define CLEAR printf("\e[1;1H\e[2J")
#define PAUSE getchar()

void menu();
void mainBDFS(Grafo g, int Op);
void mainDijkstraAndPrim(Grafo g, int Op);

int main2() {
    Grafo currentGraph;
    int op = 0, Node, Origin, Destiny, Cost;
    
    do {
        menu();
        scanf("%i", &op);

        if(op != 1 && !created) {
            printf("Create first a graph...");
        } else {
            switch(op) {
                case 1:
                    if(!created) {
                        currentGraph = crearGrafo();

                        updateCreated();
                    } else {
                        printf("The tree is already created ");
                    }

                    break;
                
                case 2:
                    printf("Enter the node: ");

                    scanf("%i", &Node);

                    currentGraph = insertarVertice(currentGraph, Node);

                    break;
                
                case 3:
                    // printf(" Data     Marked");
                    imprimirListaV(currentGraph);
                    break;

                case 4:
                    printf("Enter origin, destiny and cost,  Ex:(1, 2, 34): ");

                    scanf("%i %i %i", &Origin, &Destiny, &Cost);
                    
                    currentGraph = insertarArco(currentGraph, Origin, Destiny, Cost);
                    break;
                
                case 5:
                    imprimirListaA(currentGraph);
                    break;

                case 6:
                    mainBDFS(currentGraph, 1);

                    break;

                case 7:
                    mainBDFS(currentGraph, 0);

                    break;

                case 8:
                    mainDijkstraAndPrim(currentGraph, 1);

                    break;

                case 9:
                    mainDijkstraAndPrim(currentGraph, 0);

                    break;
                
                case 10:
                    printf("Exit...");
                    break;
                
                default:
                    printf("Please enter a valid option..");
                    break;
            }
        }

        PAUSE;
        PAUSE;
        CLEAR;
    }while(op != 10);

    return 0;
}

void menu() {
    puts("Grahp representation in C");
    puts("1. Create graph.");
    puts("2. Add node.");
    puts("3. Show nodes.");
    puts("4. Add edge.");
    puts("5. Show edges.");
    puts("6. BFS.");
    puts("7. DFS.");
    puts("8. Shortest path.");
    puts("9. Minimum Spanning Tree.");
    puts("10. Exit.");
    printf("--> ");
}


// BFS and DFS external methods
// Become data of struct TAD to BDfs
void mainBDFS(Grafo g, int Op) {
    struct Graph* graph = createGraph(EdgeCounter);

    int vertex = 0;

    ListaVertice new = (ListaVertice)malloc(sizeof (struct NodoV));

    new = g->v;

    while(new != NULL) {
        vertex = new->dato;

        ListaArco travel=(ListaArco) malloc(sizeof (struct NodoA));

        travel = g->a;

        while(travel != NULL) {
            if(travel->origen == new->dato) {
                addEdge(graph, travel->origen, travel->destino);
            }

        travel = travel->sig;
        }

        free(travel);
        new = new->sig;
    }

    free(new);

    printf("\n\n");

    if(Op) {
        bfs(graph, 1);
    } else {
        DFS(graph, 1);
    }

    free(graph);
}

// For a fast prove
int main() {
    Grafo currentGraph;
    int op = 0, Node, Origin, Destiny, Cost;

    currentGraph = crearGrafo();
    
    currentGraph = insertarVertice(currentGraph, 1);
    currentGraph = insertarVertice(currentGraph, 2);
    currentGraph = insertarVertice(currentGraph, 3);
    currentGraph = insertarVertice(currentGraph, 4);
    currentGraph = insertarVertice(currentGraph, 5);

    imprimirListaV(currentGraph);
    puts("");

    currentGraph = insertarArco(currentGraph, 1, 2, 30);
    currentGraph = insertarArco(currentGraph, 1, 3, 2);
    currentGraph = insertarArco(currentGraph, 2, 4, 8);
    currentGraph = insertarArco(currentGraph, 3, 2, 20);
    currentGraph = insertarArco(currentGraph, 3, 5, 10);
    currentGraph = insertarArco(currentGraph, 5, 4, 5);

    // If you wish to make it with out direction
    currentGraph = insertarArco(currentGraph, 2, 1, 30);
    currentGraph = insertarArco(currentGraph, 3, 1, 2);
    currentGraph = insertarArco(currentGraph, 4, 2, 8);
    currentGraph = insertarArco(currentGraph, 2, 3, 20);
    currentGraph = insertarArco(currentGraph, 5, 3, 10);
    currentGraph = insertarArco(currentGraph, 4, 5, 5);

    imprimirListaA(currentGraph);
    puts("");
    puts("");

    mainDijkstraAndPrim(currentGraph, 0);
}


void mainDijkstraAndPrim(Grafo g, int Op) {
    int matrix[V][V], i = 0, j = 0;

    ListaVertice Node = (ListaVertice)malloc(sizeof (struct NodoV));
    Node = g->v;

    ListaArco Edge = (ListaArco)malloc(sizeof (struct NodoA));


    int Nodes[V];
    int Aux[V];

    for(i = 0; i < V; i++) {
        Nodes[i] = Node->dato;

        Node = Node->sig;  
    }


    for(j = 0, i = V-1; i >= 0; j++, i--) {
        Aux[j] = Nodes[i];
    }

    // Fill whole the matrix with 0 (We don't want to search the cases where there are not conection)
    for(i = 0; i < V; i++) { // Rows
        for(j = 0; j < V; j++) { // Cols
            matrix[i][j] = 0;
        }
    }

    // Find caser where are conections
    for(i = 0; i < V; i++) { // Rows
        for(j = 0; j < V; j++) { // Cols
            if(i != j) { // When the origing and destiny are not equal
                Edge = g->a;

                while(Edge != NULL) {
                    if(Aux[i] == Edge->origen && Aux[j] == Edge->destino) {
                        matrix[i][j] = Edge->costo;
                    }

                    Edge = Edge->sig;
                }
            } 
        }
    }

    // Show the matrix
    for(i = 0; i < V; i++) { // Rows
        for(j = 0; j < V; j++) { // Cols
            printf("%i ", matrix[i][j]);
        }

        puts("");
    }
    
    puts("");

    if(Op) {
        dijkstra(matrix, 0);
    } else {
        primMST(matrix);
    }

}