#ifndef JOGO
#define JOGO

#include <iostream>
#include <vector>
#include"Midia.h"

using namespace std;

class Jogo : public catalogo::Midia
{
    private:
    string genero;
        
    public: 
        Jogo(string, int, string);
        int getTipo();
        void imprimeDados();
};

#endif