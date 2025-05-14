#include "Midia.h"

catalogo::Midia::Midia(string titulo, int ano): titulo(titulo), ano(ano) {
};

string catalogo::Midia::getTitulo() const{
    return titulo;
}

void catalogo::Midia::setTitulo(string titulo){
    this -> titulo = titulo;
}

int catalogo::Midia::getAno() const{
    return ano;
}

void catalogo::Midia::setAno(){
    this -> ano = ano;
}

//método usado pelo sort para comparar as midias 
bool catalogo::Midia::comparaMidia(const Midia *a, const Midia *b) 
{
    if(a->ano == b->ano)
        return a->titulo < b->titulo;

    return a->ano > b->ano;
}

// Imprime as informações basicas da midia, Titulo, Ano de criação, e tipo
void catalogo::Midia::imprimeFicha(){ 
    cout<<"Título: "<<titulo<<endl; 
    cout<<"Ano: "<<ano<<endl;
    //verifica o tipo de midia que é usando o método "getTipo" e imprime o tipo de midia
    if(getTipo() == 1) 
        cout<<"Tipo: CD de música"<<endl;
    if(getTipo() == 2)
        cout<<"Tipo: Filme em DVD"<<endl;
    if (getTipo() == 3)
        cout<<"Tipo: Jogo Eletrônico"<<endl;
}