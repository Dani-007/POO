#ifndef FAIXA
#define FAIXA

#include <iostream>

using namespace std;

class faixa
{
    private:
        string musica;
        int tempo;
        
    public: 
        faixa(string, int);
        string getMusica();
        void setMusica(string);
        int getTempo();
        void setTempo(int);
};

#endif