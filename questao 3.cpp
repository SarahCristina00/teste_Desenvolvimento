#include <iostream>
#include <iomanip>
#include <fstream>  
#include <string> 

using namespace std;

int main() {
    ifstream file("dados.xml");
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo XML!" << endl;
        return 1;
    }

    double valor, menor_faturamento = -1, maior_faturamento = -1, soma_faturamento = 0;
    int dias_com_faturamento = 0, dias_acima_media = 0;
    string linha;

    while (getline(file, linha)) {
        
        bool achado = false;
        for (int i = 0; i < linha.length(); i++) {
    
            if (linha[i] == '<' && linha.substr(i, 7) == "<valor>") {
                achado = true;
                i += 7; 
                valor = 0; 
                double decimal = 1; 
                
                while (i < linha.length() && linha[i] != '<') {
                    if (linha[i] == '.') {
                        decimal= 0.1; 
                    } else {
                        if (decimal == 1) {
                            valor = valor * 10 + (linha[i] - '0'); 
                        } else {
                            valor += (linha[i] - '0') * decimal; 
                            decimal *= 0.1; 
                        }
                    }
                    i++;
                }
                if (valor > 0) {
                    
                    if (menor_faturamento == -1 || valor < menor_faturamento) {
                        menor_faturamento = valor;
                    }
                    
                    if (maior_faturamento == -1 || valor > maior_faturamento) {
                        maior_faturamento = valor;
                    }
                    
                    soma_faturamento += valor;
                    dias_com_faturamento++;
                }
                break; 
            }
        }
    }

    file.close();

    if (dias_com_faturamento == 0) {
        cout << "Nenhum valor de faturamento disponível!" << endl;
        return 1;
    }

    double media_faturamento = soma_faturamento / dias_com_faturamento;

    file.open("dados.xml");
    if (!file.is_open()) {
       cout << "Erro ao abrir o arquivo XML!" << endl;
        return 1;
    }

    while (getline(file, linha)) {
        bool achado = false;
        for (int i = 0; i < linha.length(); i++) {
            if (linha[i] == '<' && linha.substr(i, 7) == "<valor>") {
                achado = true;
                i += 7; 
                valor = 0; 
                double decimal = 1;
                
                while (i < linha.length() && linha[i] != '<') {
                    if (linha[i] == '.') {
                        decimal = 0.1; 
                    } else {
                        if (decimal == 1) {
                            valor = valor * 10 + (linha[i] - '0');
                        } else {
                            valor += (linha[i] - '0') * decimal; 
                            decimal *= 0.1; 
                        }
                    }
                    i++;
                }
                if (valor > 0 && valor > media_faturamento) {
                    dias_acima_media++;
                }
                break;
            }
        }
    }

    file.close();

    cout << "Menor faturamento: " << fixed << setprecision(2) << menor_faturamento << endl;
    cout << "Maior faturamento: " << fixed << setprecision(2) << maior_faturamento << endl;
    cout << "Média de faturamento: " << fixed << setprecision(2) << media_faturamento << endl;
    cout << "Dias com faturamento acima da média: " << dias_acima_media << endl;

    return 0;
}

