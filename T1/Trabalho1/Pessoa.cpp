#include "Pessoa.h"

Pessoa::Pessoa(string CPF, string nome):CPF(CPF), nome(nome) {
};

string Pessoa::getCPF(){
    return CPF;
}

string Pessoa::getNome(){
    return nome;
}

void Pessoa::setCPF(string CPF){
    this -> CPF = CPF;
}

void Pessoa::setNome(string nome){
    this -> nome = nome;
}

void Pessoa::imprime(){
    cout<<"CPF: "<<CPF<<endl; 
    cout<<"Nome: "<<nome<<endl;
}