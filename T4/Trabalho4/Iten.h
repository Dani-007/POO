#ifndef ITEN
#define ITEN

#include <iostream>

using namespace std;

namespace inventario{

    class Iten
    {
        private:
            string nome;
            float peso;
            int raridade;
            int valor;

        public: 
            Iten(string, float, int, int);
            string getNome() const;
            float getPeso() const;
            int getRaridade() const;
            int getValor() const;
            static bool comparaIten (const Iten *a, const Iten *b);
            virtual int getTipo() = 0;//metodo abstrato 
            virtual void imprimeDados() = 0; //metodo abstrato
            void imprimeFicha();

    };
}

#endif