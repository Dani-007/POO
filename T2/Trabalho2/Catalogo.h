#ifndef CATALOGO
#define CATALOGO

#include <iostream>
#include <vector>
#include "Midia.h"

using namespace std;

namespace catalogo{

    class Catalogo 
    {
        private:
            vector<Midia *> Midias;

        public:
            Catalogo(); 
            bool adicionaMidia(Midia&); 
            bool removeMidia(string); 
            Midia* obtemMidia(string);  
            int quantidadeDeMidias(); 
            int quantidadeDeCDs(); 
            int quantidadeDeDVDs(); 
            int quantidadeDeJogos(); 
            void imprimeColecao(); 
            void imprimeColecaoPorTipo(int tipo); 
    };

}
#endif