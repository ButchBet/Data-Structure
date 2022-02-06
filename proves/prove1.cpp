#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>


using namespace std;

void BusquedaBien(int* vector,int elementos, int clave);

void BusquedaBien(int* vector,int elementos, int clave)
{
	auto start = std::chrono::system_clock::now();

	int central,bajo,alto,contador = 0;

	bool estado = false;

	int valorcentral;

	bajo = 0;

	alto = elementos-1;

	while (bajo <= alto)
	{
		contador++;

		central = (bajo + alto)/2;

		valorcentral = vector[central];

		if (clave == valorcentral)
		{
			estado = true;

			alto = 0;

			bajo = 1;
		}
		else if (clave < valorcentral)
		{
			alto = central -1;
		}
		else
		{
			bajo = central +1;
		}
		
	}

	auto end = std::chrono::system_clock::now();

	std::chrono::duration<float, std::milli> duration = end - start;

	if (estado)
	{
		cout<<"El numero "<< clave<< " fue encontrado en el indice "<<central<<
        "\nIntentos: "<< contador<< endl<< 
        "Con un tiempo de ";std::cout << duration.count() << "ms "<<std::endl;
	}
	else
	{
		cout<<"El numero no fue encontrado ";
	}
	
}


int main() {
    int size = 100;
    int *vector = new int[size];

    // Fill the vector
    for(int i = 0; i < size; i++) {
        vector[i] = i+1;
    } 

    BusquedaBien(vector, size, 10);

    return 0;
}