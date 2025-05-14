#include"Jogo.h"

Jogo::Jogo(string titulo, int ano, string genero):Midia(titulo, ano), genero(genero){
};

int Jogo::getTipo(){
    return 3;
}

//imprime os dados basicos da midia e o genero do jogo
void Jogo::imprimeDados(){
    imprimeFicha();
    cout<<"Gênero: "<<genero<<endl;
}