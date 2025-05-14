#include"Armadura.h"

Armadura::Armadura(string nome, float peso, int raridade, int valor, float defesa, int peca): inventario::Iten::Iten(nome, peso, raridade, valor), defesa(defesa), peca(peca){
};

float Armadura::getDefesa(){
    return defesa;
}

int Armadura::getPeca(){
    return peca;
}

int Armadura::getTipo(){
    return 1;
}

//imprime os dados da armadura e diz qual parte da armadura é com base no parametro recebido
void Armadura::imprimeDados(){
    inventario::Iten::imprimeFicha();
    cout<<"Defesa: "<<defesa<<endl;
    
    if(getPeca() == 1)
        cout<<"Elmo"<<endl;
    else if(getPeca() == 2)
        cout<<"Peitoral"<<endl;
    else if(getPeca() == 3)
        cout<<"Perna"<<endl;
    else
        cout<<"Manopla"<<endl;
}