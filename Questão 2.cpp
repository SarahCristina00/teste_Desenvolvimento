#include <iostream>

using namespace std;

bool fibonacci(int num) {
    int num1= 0;
    int num2 = 1;

    if (num == num1 || num == num2){
        return true;
    }
    
    while (num2 < num) {
        int proximo_numero = num1 + num2;
        num1 = num2; 
        num2 = proximo_numero;

        if (num2 == num){
        return true;
        }
    }

    return false;
}

int main() {
    int numero;
    cout << "Informe um número: ";
    cin >> numero;

    if (fibonacci(numero)) {
        cout << "O número " << numero << " pertence a sequência de Fibonacci." <<endl;
    } else {
        cout << "O número " << numero << " não pertence a sequência de Fibonacci." <<endl;
    }

    return 0;
}
