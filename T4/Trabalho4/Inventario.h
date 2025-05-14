#ifndef INVENTARIO
#define INVENTARIO 

#include <iostream>
#include <vector>
#include <fstream>
#include "Iten.h"
#include "Arma.h"
#include "Armadura.h"

using namespace std;

namespace inventario{

    class Inventario 
    {
        private:
            vector<Iten *> Itens;
            void grava();
            void le();
        public:
            Inventario(); 
            bool adicionaIten(); 
            bool removeIten(string); 
            bool obtemIten(string);
            bool modificaIten(string);
            void imprimeInventario();
            void imprimeInventarioTipo(int);
            void ordena();
            int opcoes(); 
    };

}
#endif