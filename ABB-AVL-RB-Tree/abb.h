#include <iostream>

using namespace std;

struct nodo{
     int nro;
     nodo *izq;
	nodo *der;
};

int Level = 0;

typedef nodo *ABB;

/* Save the {Level of the children, Father, level of the grandpha */
int FirstCousin[3] = {0, 0, 0};
int SecondtCousin[3] = {0, 0, 0};

/* Tree data saved into arrays */
int FirstTreeCounter = 0,
    SecondTreeCounte = 0,
    
    *FTCP = &FirstTreeCounter,
    *STCP = &SecondTreeCounte,

    *ArrayFirstTree = new int[*FTCP],
    *ArraySecondTree  = new int[*STCP];

ABB crearNodo(int x) {
     ABB nuevoNodo = new(struct nodo);

     nuevoNodo->nro = x;

     nuevoNodo->izq = NULL;

     nuevoNodo->der = NULL;

     return nuevoNodo;
}


void insertarBT(ABB &root, int x) {
     if(root==NULL) {
           root = crearNodo(x);
     } else {
          int valorRaiz = root->nro;

          if(x < valorRaiz) {
               insertarBT(root->izq, x);
          } else {
               insertarBT(root->der, x);
          }
     }
}


void preOrden(ABB root) {
     if(root!=NULL)
     {
          cout << root->nro <<" ";
          preOrden(root->izq);
          preOrden(root->der);
     }
}


void enOrden(ABB root) {
     if(root!=NULL)
     {
          enOrden(root->izq);
          cout << root->nro << " ";
          enOrden(root->der);
     }
}


void postOrden(ABB root) {
     if(root!=NULL)
     {
          postOrden(root->izq);
          postOrden(root->der);
          cout << root->nro << " ";
     }
}


void verArbolB(ABB root, int n) {
     if(root==NULL) {
          return;
     } else {
          verArbolB(root->der, n+1);

          for(int i=0; i<n; i++) {
          cout<<"    ";
          }

          cout<< root->nro <<endl;

          verArbolB(root->izq, n+1);
     }
}


bool buscarABB(ABB root, int dato) {
     bool r=false;   // 0 indica que lo encontre

     if(root==NULL) {
        return r;
     }

     if(dato < root->nro) {
         r = buscarABB(root->izq, dato);
     } else if(dato > root->nro) {
         r = buscarABB(root->der, dato);
     } else {
        r = true;   // son iguales, lo encontre
     }

     return r;
}


void eliminar(ABB &root,int x) {
    ABB aux1,aux2;
    if(root==NULL) return;
    if(x>root->nro)
         eliminar(root->der,x);
    if(x<root->nro)
        eliminar(root->izq,x);
    if(x==root->nro)
    {
        if(root->der==NULL && root->izq==NULL) //Si el nodo es hoja
        {
            root=NULL;
            return;
        }
        if(root->der!=NULL && root->izq==NULL)
        {
            root=root->der;
            return;
        }
            aux1=root;
            aux2=root->izq;
            while(aux2->der!=NULL)
            {
                aux1=aux2;
                aux2=aux2->der;
            }
            root->nro=aux2->nro;
            if(aux1==root)
                root->izq=aux2->izq;
            else
            aux1->der=aux2->izq;
    }
}


void eliminarArbolEntero(ABB &root){
     if(root == NULL) { 
          return;
     } else {
          if(root->izq != NULL) {
               eliminarArbolEntero(root->izq);
          }

          if(root->der != NULL) {
               eliminarArbolEntero(root->der);
          }

          delete root;
     }
}


void alturaBT(ABB &root, int lvl) {
     if(root == NULL) {
          return;
     }

     if(root->izq != NULL) {
          alturaBT(root->izq, lvl+1);
     }

     if(root->der != NULL) {
          alturaBT(root->der, lvl+1);
     }

     if(root->der == NULL && root->izq == NULL && lvl > Level) {
          Level = lvl;
     }
}

bool hoja(ABB &root) {
     if(root->der == NULL && root->izq==NULL) {
          return true;
     } else {
          return false;
     }
}

int pesoBT(ABB &root) {
     int pes = 0;
     if(hoja(root)) {
          return 1;
     } else {
          if(root->izq != NULL) {
               pes += pesoBT(root->izq);
          }

          if(root->der != NULL) {
               pes += pesoBT(root->der);
          }

          return pes;
     }
}

void encontrarPadre(ABB root, int val, int parent) {
    if (root == NULL) {
        return;
    }
 
    // If current root is the required root
    if (root->nro == val) {
         if(parent == -1) {
              cout<< "The item is the same root";
         } else {
          cout << "The parent is: "<< parent;
         }
    } else {
        encontrarPadre(root->izq, val, root->nro);


        encontrarPadre(root->der, val, root->nro);
    }
}


bool esIgual(ABB &root1, ABB &root2)
{
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // If any one of the tree is non-empty
    // and other is empty, return false
    else if (root1 != NULL && root2 == NULL) {
        return false;
    } else if (root1 == NULL && root2 != NULL) {
        return false;
    } else { // Check if current nro of both trees equal
        // and recursively check for izq and der subtrees
        if (root1->nro == root2->nro && esIgual(root1->izq, root2->izq)
            && esIgual(root1->der, root2->der)) {
            return true;
          } else {
               return false;
          }
    }
}

bool arbolLLeno(ABB &root) {
    // If empty tree
    if (root == NULL) {
        return true;
    }
  
    // If leaf node
    if (root->izq == NULL && root->der == NULL) {
        return true;
    }
  
    // If both izq and der are not NULL, and izq & der subtrees
    // are full
    if ((root->izq) && (root->der)) {
        return (arbolLLeno(root->izq) && arbolLLeno(root->der));
    }
  
    // We reach here when none of the above if conditions work
    return false;
}

/* Helper function for getLevel(). It returns level of the data if data is
present in tree, otherwise returns 0.*/
int getLevelUtil(ABB &node, int data, int level) {
    if (node == NULL) {
        return 0;
    }
 
    if (node->nro == data) {
        return level;
    }
 
    int downlevel = getLevelUtil(node->izq, data, level + 1);

    if (downlevel != 0) {
        return downlevel;
    }
 
    downlevel = getLevelUtil(node->der, data, level + 1);

    if (downlevel != 0) {
        return downlevel;
    }

    return 0;
}
 
/* Returns level of given data value */
int getLevel(ABB &node, int data) {
    return getLevelUtil(node, data, 1);
}


/* # of item in a given level */
int getItemsUntil(ABB &root, int level, int actualLevel) {
     int numberItems = 0;

     if(root == NULL) { 
          return numberItems;
     }

     if(level == actualLevel) {
          return 1;
     }

     numberItems += getItemsUntil(root->izq, level, actualLevel+1);

     numberItems += getItemsUntil(root->der, level, actualLevel+1);

     return numberItems;
}

/* Returns item at given level */
int numberItems(ABB &root, int level) {
     return getItemsUntil(root, level, 1);
}


/* Return true in case of find the element as a children */
bool isChildren(ABB &root, int item) {
     if(root == NULL || root->nro != item) {
          return false;
     } 

     return true;
}

/* Check the tree elemets and save level of childer, grandpa and father */
void checkAndSaveCousinData(ABB &root, int item1, int item2, int grp, int level) {
     if(root == NULL) {
          return;
     }

     if(isChildren(root->izq, item1) || isChildren(root->der, item1)) {
          FirstCousin[0] = level+1;

          FirstCousin[1] = root->nro;

          FirstCousin[2] = grp;
     }

     if(isChildren(root->izq, item2) || isChildren(root->der, item2)) {
          SecondtCousin[0] = level+1;

          SecondtCousin[1] = root->nro;

          SecondtCousin[2] = grp;
     } 

     checkAndSaveCousinData(root->izq, item1, item2, root->nro, level+1);

     checkAndSaveCousinData(root->der, item1, item2, root->nro, level+1);
}

void isCousin(ABB &root, int item1, int item2) {
     checkAndSaveCousinData(root, item1, item2, 0, 0); // Modificate the data

     bool final = false;

     if(FirstCousin[0] == SecondtCousin[0]) { // Item 1 and 2 are at the same level
          final = true;
     }

     if(FirstCousin[1] != SecondtCousin[1]) { // The parent is different
          final = true;
     } else {
          final = false;
     }

     if(FirstCousin[2] == SecondtCousin[2]) { // The grandpa is equal
          final = true;
     } else {
          final = false;
     }

     if(final) {
          cout<< item1 << " and "<< item2<< " are cousin";
     } else {
          cout<< item1 << " and "<< item2<< " aren't cousin";
     }

     for(int i = 0; i < 3; i++) { // Remove the current data to future uses
          FirstCousin[i] = 0;

          SecondtCousin[i] = 0;
     }
}

bool stableTree(ABB &root, int father) {
     if(root == NULL) {
          return true;
     }

     if(root->der != NULL) {
          return false;
     }

     bool final = stableTree(root->izq, root->nro);

     if(root->nro <= father) {
          return true;
     }

     return false;
}

void SaveUntilNLevels(ABB root, int n, int level) {
     if(root==NULL || n > level) {
          return;
     } else {
          /*Increase the array size*/
          *FTCP += 1;

          ArrayFirstTree = new int[*FTCP];

          /* Save current nro */

          ArrayFirstTree[(*FTCP)-1] = root->nro; 

          SaveUntilNLevels(root->der, n+1, level);

          SaveUntilNLevels(root->izq, n+1, level);
     }
}