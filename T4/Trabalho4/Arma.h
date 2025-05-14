#ifndef ARMA
#define ARMA

#include <iostream>
#include <vector>
#include"Iten.h"
#include"Arma.h"
#include"Armadura.h"

using namespace std;

class Arma : public inventario::Iten
{
    private:
        float dano;
        int elemento;
        string tipoArma;
        float critico = dano * 1.5;
        
    public: 
        Arma(string, float, int, int, float, int, string);
        float getDano();
        int getElemento();
        string getTipoArma();
        int getTipo();
        float getCritico();
        void imprimeDados();
};
#endif