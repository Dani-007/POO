#ifndef VOO
#define VOO
#include "DataHorario.h"
#include "Pessoa.h"
#include <string>
#include <iostream>
using namespace std;

class Voo{
private:
    int nv;//numero do voo e 
    DataHorario* data;
    Pessoa* passageiro[100];

public:
    Voo(int nv, DataHorario& data);
    int getNv();
    DataHorario* getData();
    void setNv(int nv);
    void setData(DataHorario& data);
    int proximoLivre(); //Método responsável por retornar o número da próxima poltrona livre
    bool verifica(int np); //Método responsável por verificar se o número da poltrona recebido como parâmetro está ocupada
    bool ocupa(int np, Pessoa& pas); //Método responsável por ocupar determinada poltrona do vôo, cujo número é recebido como parâmetro
    bool desocupa(int np); //Método responsável por desocupar determinada poltrona do vôo, cujo número é recebido como parâmetro
    int vagas(); //Método responsável por retornar o número de poltronas vagas disponíveis (não ocupadas) no vôo
    void imprime(); //Método responsavel pela impressão das informações de um voo
};

#endif 