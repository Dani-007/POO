#include"Iten.h"

inventario::Iten::Iten(string nome, float peso, int raridade, int valor): nome(nome), peso(peso), raridade(raridade), valor(valor){
};

string inventario::Iten::getNome()const{
    return nome;
}

float inventario::Iten::getPeso()const{
    return peso;
}

int inventario::Iten::getRaridade()const{
    return raridade;
}

int inventario::Iten::getValor()const{
    return raridade;
}

// Essa função serve para comparar dois iten e ordenalos por ordem alafabetica e se tiverem o mesmo nome por peso(crescente)
bool inventario::Iten::comparaIten(const Iten *a, const Iten *b) 
{
    if(a->nome == b->nome)
        return a->peso > b->peso;

    return a->nome < b->nome;
}

//imprme os dados basicos da função
void inventario::Iten::imprimeFicha(){
    cout<<"Nome: "<<nome<<endl;
    cout<<"Peso: "<<peso<<endl;
    if(getTipo() == 0)
        cout<<"Tipo: Arma"<<endl;
    if(getTipo() == 1)
        cout<<"Tipo: Armadura"<<endl;

    if(raridade == 1)
        cout<<"Raridade: comum"<<endl;
    else if(raridade == 2)
        cout<<"Raridade: raro"<<endl;
    else if(raridade == 3)
        cout<<"Raridade: Epico"<<endl;
    else if(raridade == 4)
        cout<<"Raridade: Lendario"<<endl;
        
    cout<<"Valor: "<<valor<<" moedas"<<endl;
}