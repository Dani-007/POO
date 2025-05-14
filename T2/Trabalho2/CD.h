#ifndef CD_H
#define CD_H

#include <iostream>
#include <vector>
#include"Midia.h"
#include"faixa.h"

using namespace std;

class CD  : public catalogo::Midia
{
    private:
    string artista;
    vector<faixa> Faixas;
        
    public: 
        CD(string, int, string);
        int getTipo();
        void imprimeDados();
        void adicionaFaixa(string, int);
};

#endif