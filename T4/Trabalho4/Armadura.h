#ifndef ARMADURA
#define ARMADURA

#include <iostream>
#include <vector>
#include"Iten.h"

using namespace std;

class Armadura : public inventario::Iten
{
    private:
        float defesa;
        int peca;
    public: 
        Armadura(string, float, int, int, float, int);
        float getDefesa();
        int getPeca();
        int getTipo();
        void imprimeDados();
};
#endif