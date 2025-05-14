#ifndef PESSOA
#define PESSOA
#include <string>
#include <iostream>
using namespace std;

class Pessoa
{
private:
    string CPF;
    string nome;

public:
    Pessoa(string CPF, string nome); //Contrutor
    string getCPF(); 
    string getNome(); 
    void setCPF(string CPF); 
    void setNome(string nome);
    void virtual imprime(); //Método responsável pela impressão das informações (CPF e nome) de uma pessoa.
 
};

#endif 