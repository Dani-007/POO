#include "Voo.h"
#include <cstring>

Voo::Voo(int nv, DataHorario& data):nv(nv), data(&data){
    memset(passageiro, 0, 100*sizeof(Pessoa*));
};

int Voo::getNv(){
    return nv;
}

DataHorario* Voo::getData(){
    return data;
}

void Voo::setNv(int nv){
    this -> nv = nv;
}

void Voo::setData(DataHorario& data){
    this -> data = &data;
}

int Voo::proximoLivre(){ //procura pela proxima poltrona livre e retorna o numero dessa poltrona
    int aux = 0;
    for(int i = 0; i < 99; i++){
        if (passageiro[i] == NULL && aux == 0){
            aux = i+1;
        }
    }
    return aux;
}

bool Voo::verifica(int np){ //verifica se a poltrona indicada está livre ou não
    bool aux;
    if (passageiro[np-1] == NULL){
        aux = false;
    }
    else{
        aux = true;
    }
    
    return aux;
}

bool Voo::ocupa(int np, Pessoa& pas){ //verifica se a poltrona indicada está livre e se estiver ocupa ela com uma pessoa e retona true, caso contrario retorna false
    bool aux;
    if (verifica(np) == false){
        passageiro[np-1] = &pas;
        aux = true;
    }
    else{
        aux = false; 
    }
    
    return aux;
}

bool Voo::desocupa(int np){ //verifica se a poltrona indicada está ocupada e se estiver deocupa ela e retona true, caso contrario retorna false
    bool aux;
    if (verifica(np) == true){
        passageiro[np-1] = NULL;
        aux = true;
    }
    else{
        aux = false;
    }
    return aux;
}

int Voo::vagas(){ //Contabiliza o numero de poltronas vazias
    int aux = 0;

    for(int i = 0; i < 100; i++){
        if (passageiro[i] == NULL){
            aux++;
        }
    }
    return aux;
}

void Voo::imprime(){ //Imprime os dados de um voo
    cout<<"Numero do voo: "<<nv<<endl;
    data->imprime(false);
    cout<<"Numero de Vaga(s): "<<vagas()<<endl;
    for(int i = 0; i < 100; i++){
        if (verifica(i + 1) == true){
            passageiro[i]->Pessoa::imprime(); //imprime os dados dos passageiros
        }
    }
}