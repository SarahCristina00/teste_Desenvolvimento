/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;


int main()
{
   int INDICE = 13, SOMA = 0, K = 0;
    while(K < INDICE){ 
        K = K + 1; 
        SOMA = SOMA + K; 
        
    }
    cout<<"Soma: "<<SOMA<<endl;

    return 0;
}