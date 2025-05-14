#include"CD.h"

CD::CD(string titulo, int ano, string artista):Midia(titulo, ano), artista(artista){
};

int CD::getTipo(){ 
    return 1;
}

//Imprimi os dados basicos da midia e o nome do artista e as faixas 
void CD::imprimeDados(){
    int min;
    
    imprimeFicha();
    cout<<"Artista: "<<artista<<endl;

    for (int i = 0; i < Faixas.size(); i++)
    {
        min = Faixas[i].getTempo()/6;

        cout<<"Faixa"<<i<<": "<<Faixas[i].getMusica()<<", duração: "<<min<<":"<<(Faixas[i].getTempo() - (min*60))<<endl;
    }
}

//Adiciona uma Faixa no fim do vetor 
void CD::adicionaFaixa(string nome, int tempo){
    faixa nfaixa(nome, tempo);//cria um objeto faixa
        
    Faixas.push_back(nfaixa);
}