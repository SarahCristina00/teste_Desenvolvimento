#include <iostream>
#include <cstring> // Para trabalhar com strings

using namespace std;

int main() {
    
    char str[100];
    cout << "Informe uma frase: "<<endl;
    cin.getline(str, 100); 

    int tamanho = strlen(str); // Tamanho da string

    // Invertendo a string manualmente
    for (int i = 0; i < (tamanho / 2); i++) {
        char aux = str[i];
        str[i] = str[tamanho - i - 1];
        str[tamanho - i - 1] = aux;
    }

    cout << "Frase invertida: " << str << endl;

    return 0;
}