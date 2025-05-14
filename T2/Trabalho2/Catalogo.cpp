#include "Catalogo.h"
#include <algorithm>

catalogo::Catalogo::Catalogo(){
};

//adicona uma midia no fim do vetor 
bool catalogo::Catalogo::adicionaMidia(Midia &midia)
{
    Midias.push_back(&midia);
    
    return 1;
}

//percorre o vetor procurado um midia e remove ela do vetor
bool catalogo::Catalogo::removeMidia(string titulo)
{
    for (int i = 0; i < Midias.size(); i++)
    {
        if(Midias[i]->getTitulo() == titulo)
        {
            Midias.erase(Midias.begin()+i);
            return 1;
        }
    }

    return 0;
}

//percorre o vetor procurando uma midia e retorna o endereço dela caso ache
catalogo::Midia* catalogo::Catalogo::obtemMidia(string titulo) 
{
    for(int i = 0; i < Midias.size(); i++)
    {
        if (Midias[i]->getTitulo() == titulo)
        {
            return Midias[i];
        }
    }

    return nullptr;
}

//conta a quantidade total de midias 
int catalogo::Catalogo::quantidadeDeMidias()
{
    return Midias.size();
}

//conta a quantidade de CDs entre as midias
int catalogo::Catalogo::quantidadeDeCDs()
{
    int cont = 0;

    for(int i = 0; i < Midias.size(); i++)
    {
        if(Midias[i]->getTipo()==1)
            cont++;
    }

    return cont;

}

//conta a quantidade de DVDs entre as midias
int catalogo::Catalogo::quantidadeDeDVDs()
{
    int cont = 0;

    for(int i = 0; i < Midias.size(); i++)
    {
        if(Midias[i]->getTipo()==2)
            cont++;
    }

    return cont;
}

//conta a quantidade de jogos entre as midias
int catalogo::Catalogo::quantidadeDeJogos()
{
    int cont = 0;

    for(int i = 0; i < Midias.size(); i++)
    {
        if(Midias[i]->getTipo()==3)
            cont++;
    }

    return cont;
}

//imprime todas as midias organizadas pelo ano de criação(ordem decrescente) e caso tenham o mesmo nome ordena pelo titulo(ordem crescente)
void catalogo::Catalogo::imprimeColecao()
{
    
    sort(Midias.begin(), Midias.end(), Midia::comparaMidia);

    for (int i = 0; i < Midias.size(); i++)
    {
        Midias[i]->imprimeFicha();
        cout << endl;
    }
}

//imprime todas as midias de um tipo especificado, organizadas pelo ano de criação(ordem decrescente) e caso tenham o mesmo nome ordena pelo titulo(ordem crescente)
void catalogo::Catalogo::imprimeColecaoPorTipo(int tipo)
{
    sort(Midias.begin(), Midias.end(), Midia::comparaMidia);

    for (int i = 0; i < Midias.size(); i++)
    {
        if(Midias[i]->getTipo() == tipo)
        {
            Midias[i]->imprimeFicha();
            cout << endl;
        }
    }
}