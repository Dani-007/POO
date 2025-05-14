#include"Arma.h"

Arma::Arma(string nome, float peso, int raridade, int valor, float dano, int elemento, string tipoArma): inventario::Iten::Iten(nome, peso, raridade, valor), dano(dano), elemento(elemento), tipoArma(tipoArma){
};

float Arma::getDano(){
    return dano;
}

int Arma::getElemento(){
    return elemento;
}

string Arma::getTipoArma(){
    return tipoArma;
}

int Arma::getTipo(){
    return 0;
}

float Arma::getCritico(){
    return critico;
}

//imprime os dados da arma e diz qual seu tipo de dano com base no parametro recebido
void Arma::imprimeDados(){
    string elem;
    if(getElemento() == 1)
        elem = "sagrado";
    else if(getElemento() == 2)
        elem = "magico";
    else if(getElemento() == 3)
        elem = "fogo";
    else if(getElemento() == 4)
        elem = "raio";
    else
        elem = "fisico";

    inventario::Iten::imprimeFicha();
    cout<<"Dano: "<<dano<<" "<<elem<< " critico("<<critico<<")"<<endl;
    cout<<tipoArma<<endl;
}