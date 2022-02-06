/* Work 3: Structure and TAD rational
    Materia: Data Structure
    Autor: Kevin Alejandro Salazar
    Fecha: 20-09-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/


#include <iostream> // cout, cin

using namespace std;

typedef struct {
    // Values for TAD rational
    float Num, Den;
} Rational;

// Pseudo functions ---------------------------
Rational Addition(Rational a, Rational b);

Rational Substraction(Rational a, Rational b);

Rational Product(Rational a, Rational b);

Rational Division(Rational a, Rational b);

Rational Power(Rational a, Rational b);

int NumberOfTimes(int a, int b);
//----------------------------------------------

Rational Addition(Rational a, Rational b) { // To calculate the addition and generate the structure
    Rational New;

    New.Num = a.Num * b.Den + b.Num * a.Den;

    New.Den =  a.Den * b.Den;

    return New;
}

Rational Substraction(Rational a, Rational b) { // To calculate the substraction and generate the structure
    Rational New;

    New.Num = a.Num * b.Den - b.Num * a.Den;

    New.Den =  a.Den * b.Den;

    return New;
}

Rational Product(Rational a, Rational b) { // To calculate the product and generate the structure
    Rational New;

    New.Num = (a.Num * b.Den) * (b.Num * a.Den);

    New.Den =  a.Den * b.Den;

    return New;
}

Rational Division(Rational a, Rational b) { // To calculate the division and generate the structure 
    Rational New;

    New.Num = (a.Num * b.Den) / (b.Num * a.Den);

    New.Den =  a.Den * b.Den;

    return New;
}

Rational Power(Rational a, Rational b) { // To generate the structure of a powered number
    Rational New;

    New.Num = NumberOfTimes((a.Num * b.Den), (b.Num * a.Den));

    New.Den =  a.Den * b.Den;

    return New;
}

int NumberOfTimes(int a, int b) { // Calculate the power of a number
    int Current = a;

    for(int i = 0;  i < b; i++) {
        a *= Current;
    }

    return a;
}


int main() {
    Rational New1 = {1, 3};

    Rational New2 = {3, 1};

    // New.Num = 1;

    // New.Den =  3;

    Rational New3 = Power(New1, New2);

    cout<< New3.Num<< " and "<< New3.Den<< endl;
}