#ifndef DVD_H
#define DVD_H

#include <iostream>
#include <vector>
#include"Midia.h"
#include"ator.h"

using namespace std;

class DVD  : public catalogo::Midia
{
    private:
    string diretor;
    vector<ator> Elenco;
        
    public: 
        DVD(string, int, string);
        int getTipo();
        void imprimeDados();
        void adicionaArtista(string, string);
};

#endif