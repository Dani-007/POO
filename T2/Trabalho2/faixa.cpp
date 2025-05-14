#include"faixa.h"

faixa::faixa(string musica, int tempo): musica(musica), tempo(tempo){
};

string faixa::getMusica(){
    return musica;
}

void faixa::setMusica(string musica){
    this -> musica = musica;
}

int faixa::getTempo(){
    return tempo;
}

void faixa::setTempo(int tempo){
    this -> tempo = tempo;
}