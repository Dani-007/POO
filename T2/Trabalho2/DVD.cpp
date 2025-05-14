#include"DVD.h"

DVD::DVD(string titulo, int ano, string diretor):Midia(titulo, ano), diretor(diretor){
};

int DVD::getTipo(){
    return 2;
}

//imprime os dados basico da midia e os atores do elenco 
void DVD::imprimeDados(){
    imprimeFicha();
    cout<<"Diretor: "<<diretor<<endl;

    for (int i = 0; i < Elenco.size(); i++)
    {
        cout<<"Artista"<<i<<": "<<Elenco[i].getNome()<<", papel: "<<Elenco[i].getPapel()<<endl;
    }
}

//adiciona um ator/atriz no fiim do vetor 
void DVD::adicionaArtista(string nome, string papel){
    ator nAtor(nome, papel);

    Elenco.push_back(nAtor);
}