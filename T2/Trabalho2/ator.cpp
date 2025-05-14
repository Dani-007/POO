#include"ator.h"

ator::ator(string nome, string papel): nome(nome), papel(papel){
};

string ator::getNome(){
    return nome;
}

void ator::setNome(string nome){
    this -> nome = nome;
}

string ator::getPapel(){
    return papel;
}

void ator::setPapel(string papel){
    this -> papel = papel;
}