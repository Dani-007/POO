#include "Aluno.h"

Aluno::Aluno(string CPF, string nome, int RA, double p1, double p2, double t):Pessoa(CPF, nome), RA(RA), p1(p1), p2(p2), t(t){
}

int Aluno::getRA(){
    return RA;
}

double Aluno::getP1(){
    return p1;
}

double Aluno::getP2(){
    return p2;
}

double Aluno::getT(){
    return t;
}

void Aluno::setRA(int RA){
    this -> RA = RA;
}

void Aluno::setP1(double p1){
    this -> p1 = p1;
}

void Aluno::setP2(double p2){
    this -> p2 = p2;
}

void Aluno::setT(double t){
    this -> t = t;
}

double Aluno::media(){
    double med;
    med = ((p1*7)+(p2*7)+(t*6))/20; //Calcula a média do aluno baseado na suas notas das duas provas e do trabalho, com cada nota tendo um peso diferente diferentes 
    
    return med;
}

bool Aluno::aprovado(){
    bool aux;

    if(media() >= 6){ //Verifica se a media é maior ou igual a 6, se sim ele retorna verdadeiro, e caso contrario retona falso
        aux = true;
    }
    else{
        aux = false;
    }
    return aux;
}

bool Aluno::sac(){
    bool aux;

    if(media() >= 5 && media() < 6){ //Verifica se a média do aluno é menor que 6 e maior ou igual a 5, para atender os requisitos para entrar no SAC
        aux = true;
    }
    else{
        aux = false;
    }
    return aux;
}

double Aluno::notaSAC(){
    double aux;
    
    if(sac()){ //Verifica se o aluno se enquadra nos requisitos para fazer o SAC e se sim calcula a nota necessaria para que o aluno seja aprovado
        aux = (12 - media());
    }
    else{
        aux = 0;
    }

    return aux;
}

void Aluno::imprime(){
    Pessoa::imprime();
    cout<<"RA: "<<RA<<endl;
    if (media() < 5)
    {
        cout<<"Reprovado com media: "<<media()<<endl;
    }
    else if (sac())
    {
        cout<<"(SAC) Nota minima aprovacao: "<<notaSAC()<<endl;
    }
    else
    {
        cout<<"Aprovado com media: "<<media()<<endl;
    }
    
}
