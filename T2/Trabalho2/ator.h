#ifndef ATOR
#define ATOR

#include <iostream>

using namespace std;

class ator
{
    private:
        string nome;
        string papel;
        
    public: 
        ator(string, string);
        string getNome();
        void setNome(string);
        string getPapel();
        void setPapel(string);
};

#endif