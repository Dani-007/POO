#ifndef DATAHORARIO
#define DATAHORARIO
#include <string>
#include <iostream>
using namespace std;

class DataHorario {
private:
    int ano, mes, dia, hora, min, seg;

public:
    DataHorario(int dia, int mes, int ano, int hora, int min, int seg); //Construtor que verifica se uma data é valida
    ~DataHorario(); //Destrutor
    int getAno();
    int getMes();
    int getDia();
    int getHora();
    int getMinuto();
    int getSegundo();
    void setAno(int ano);
    void setMes(int mes);
    void setDia(int dia);
    void setHora(int hora);
    void setMinuto(int min);
    void setSegundo(int seg);
    int compare(DataHorario& data); // Compara a data fornecida com outra indicada por um ponteiro, e diz se são iguais ou se uma é maior que a outra
    void imprime(bool x); // imprime a data, podendo imprimir em no formato de 12 horas ou 24 horas, dependendo da booleana passada como parametro
    void imprimePorExtenso(); // imprime a data por extenso 
};

#endif 