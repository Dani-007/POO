#ifndef MIDIA
#define MIDIA

#include <iostream>
#include <vector>

using namespace std;

namespace catalogo{
    class Midia
    {
        private:
            string titulo;
            int ano;
        public: 
            Midia(string, int);
            string getTitulo() const;
            void setTitulo(string);
            int getAno() const;
            void setAno();
            static bool comparaMidia (const Midia *a, const Midia *b);
            virtual int getTipo() = 0; //metodo abstrato
            virtual void imprimeDados() = 0; //metodo abstrato
            void imprimeFicha();

    };
}


#endif