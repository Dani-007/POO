#ifndef ALUNO
#define ALUNO
#include "Pessoa.h"
#include <string>
#include <iostream>
using namespace std;

class Aluno : public Pessoa{ //Aluno é uma classe que herdada de Pessoa
private:
    int RA;
    double p1, p2, t;

public:
    Aluno(string CPF, string nome, int RA, double p1,double p2,double t); //Contrutor
    int getRA();
    double getP1();
    double getP2();
    double getT();
    void setRA(int RA);
    void setP1(double p1);
    void setP2(double p2);
    void setT(double T);
    double media();//Método responsavel por calular a média do Aluno 
    bool aprovado();// Método responsável por retornar verdadeiro se o aluno foi aprovado (MF ≥ 6.0) e falso, caso contrário.
    bool sac(); //Método responsável por retornar verdadeiro se o aluno ficou em SAC
    double notaSAC(); //Método responsável por calcular qual a nota mínima necessária, na prova de avaliação complementar (SAC), para aprovação na disciplina. 
    void imprime(); //Método responsável pela impressão das informações (CPF, nome, RA e média final) de um aluno.
};

#endif 