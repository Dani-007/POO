#include <cstdlib>
#include <iostream>

#include "Iten.h"
#include "Arma.h"
#include "Armadura.h"
#include "Inventario.h"

using namespace std;
using namespace inventario;

bool realizaTestes()
{
    int aux, op = 0;
    string nome;
    Inventario invent;

    while (op != 7)
    {
        op = invent.opcoes();

        if (op == 1)
            invent.imprimeInventario();

        if (op == 2)
        {
            cout << "Qual tipo de iten voce quer imprimir?" << endl;
            cout << "Digite 0 para armas e 1 para armaduras" << endl;
            cin >> aux;
            if(aux == 0 || aux == 1)
                invent.imprimeInventarioTipo(aux);
            else
                cout << "Erro: entrada invalida"<<endl;
        }
        if (op == 3)
            invent.adicionaIten();
        if (op == 4){
            cout << "Qual o nome do iten que voce quer atualizar?"<<endl;
            cin.ignore();
            getline(std::cin, nome);
            if(invent.modificaIten(nome) == false);
                cout<<"Iten nao encontrado"<<endl;
        }
        if(op == 5){
            cout << "Qual o nome do iten que voce quer remover?"<<endl;
            cin.ignore();
            getline(std::cin, nome);
            if(invent.removeIten(nome) == false);
                cout<<"Iten nao encontrado"<<endl;
        }
        if(op == 6){
            cout << "Qual o nome do iten que voce quer procurar?"<<endl;
            cin.ignore();
            getline(std::cin, nome);
            if(invent.obtemIten(nome) == false);
                cout<<"Iten nao encontrado"<<endl;
        }
        if(op < 1 || op > 7)
            cout << "Erro: entrada invalida";
    }

    return true;
}

int main()
{
    realizaTestes();
    return 0;
}
