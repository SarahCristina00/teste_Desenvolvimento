
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double total = 0;
    double sp = 0, rj = 0, mg = 0, es = 0, out = 0;
    double fat[5] = {67836.43, 36678.66, 29229.88, 27165.48, 19849.53};
    
    for (int i= 0; i <5; i++){
        total = total + fat[i];
    }
    cout<<"O faturamento total é: "<<fixed<<setprecision(2)<<total;
    sp = (fat[0]/total)*100;
    rj = (fat[1]/total)*100;
    mg = (fat[2]/total)*100;
    es = (fat[3]/total)*100;
    out = (fat[4]/total)*100;
    
    cout<<" O percentual de São Paulo dentro do valor total é: "<<fixed<<setprecision(2)<<sp<<"%"<<endl;
    cout<<" O percentual do Rio de Janeiro dentro do valor total é: "<<fixed<<setprecision(2)<<rj<<"%"<<endl;
    cout<<" O percentual de Minas Gerais dentro do valor total é: "<<fixed<<setprecision(2)<<mg<<"%"<<endl;
    cout<<" O percentual do Espirito Santo do valor total é: "<<fixed<<setprecision(2)<<es<<"%"<<endl;
    cout<<" O percentual dos outros estados do valor total é: "<<fixed<<setprecision(2)<<out<<"%"<<endl;
    
    return 0;
}
