#include "Inventario.h"
#include <algorithm>

//Construtor que já lê os dados do arquivo
inventario::Inventario::Inventario()
{
    le();
};

//Metodo que adiciona mais itens no aquivo
bool inventario::Inventario::adicionaIten()
{
    int tipo, tam, raridade, valor, elemento, peca;
    float peso, dano, critico, defesa;
    string nome, tipoArma;
    Iten *iten;

    cout << "Digite o nome do iten" << endl;
    cin.ignore();
    getline(std::cin, nome);
    cout << "Digite o peso do iten" << endl;
    cin >> peso;
    cout << "Digite a raridade do iten" << endl;
    cout << "Digite 1 para comum, 2 para raro, 3 para epico e 4 para lendario" << endl;
    cin >> raridade;
    cout << "Digite o valor do iten" << endl;
    cin >> valor;
    cout << "Digite o Tipo do item (digite 0 para arma e 1 para armadura)" << endl;
    cin >> tipo;

    if (tipo == 0)
    {
        cout << "Digite o dano da arma" << endl;
        cin >> dano;
        cout << "Digite o tipo de dano da arma" << endl;
        cout << "digite 1 para sagrado, 2 para magico, 3 para fogo, 4 para raio e 5 para fisico" << endl;
        cin >> elemento;
        cout << "Digite o tipo da arma" << endl;
        cin.ignore();
        getline(std::cin, tipoArma);
        iten = new Arma(nome, peso, raridade, valor, dano, elemento, tipoArma);
    }
    else
    {
        cout << "Digite a defesa da armadura" << endl;
        cin >> defesa;
        cout << "Digite qual parte da armadura é" << endl;
        cout << "Digite 1 para elmo, 2 para peitoral, 3 para perna e 4 para manopla" << endl;
        cin >> peca;
        iten = new Armadura(nome, peso, raridade, valor, defesa, peca);
    }
    
    Itens.push_back(iten);
    grava();

    return true;
}

//Metodo procura por um iten no arquivo pelo nome e apaga ele 
bool inventario::Inventario::removeIten(string nome)
{
    bool achou = false;
    
    for (int i = 0; (i < Itens.size()) && (achou == false); i++)
    {
        if (Itens[i]->getNome() == nome)
        {
            Itens.erase(Itens.begin() + i);
            grava();
            achou = true;
        }
    }
    return achou;
}

//Metodo que procura um iten no arquivo e imprime ele
bool inventario::Inventario::obtemIten(string nome)
{
    bool achou = false;
    
    for (int i = 0; (i < Itens.size()) && (achou == false); i++)
    {
        if (Itens[i]->getNome() == nome)
        {
            cout << "=====================================================================" << endl;
            Itens[i]->imprimeDados();
            cout << "=====================================================================" << endl;
            achou = true;
        }
    }
    return achou;
}

//Metodo que procura um iten e modifica ele
bool inventario::Inventario::modificaIten(string nomeIten)
{
    bool achou = false;
    int tipo, tam, raridade, valor, elemento, peca;
    float peso, dano, critico, defesa;
    string nome, tipoArma;
    Arma *arma;
    Armadura *armadura;

    for (int i = 0; (i < Itens.size()) && (achou == false); i++)
    {
        if (Itens[i]->getNome() == nomeIten)
        {
            cout << "Digite o novo nome do iten" << endl;
            cin >> nome;
            cout << "Digite o novo peso do iten" << endl;
            cin >> peso;
            cout << "Digite a nova raridade do iten" << endl;
            cout << "Digite 1 para comum, 2 para raro, 3 para epico e 4 para lendario" << endl;
            cin >> raridade;
            cout << "Digite o novo valor do iten" << endl;
            cin >> valor;
            cout << "Digite o Tipo do item (digite 1 para arma e 2 para armadura)" << endl;
            cin >> tipo;

            if (tipo == 0)
            {
                cout << "Digite o dano da arma" << endl;
                cin >> dano;
                cout << "Digite o tipo de dano da arma" << endl;
                cout << "digite 1 para sagrado, 2 para magico, 3 para fogo, 4 para raio e 5 para fisico" << endl;
                cin >> elemento;
                cout << "Digite o tipo da arma" << endl;
                cin >> tipoArma;
                Itens[i] = new Arma(nome, peso, raridade, valor, dano, elemento, tipoArma);
            }
            else
            {
                cout << "Digite a defesa da armadura" << endl;
                cin >> defesa;
                cout << "Digite qual parte da armadura é" << endl;
                cout << "Digite 1 para elmo, 2 para peitoral, 3 para perna e 4 para manopla" << endl;
                cin >> raridade;
                Itens[i] = new Armadura(nome, peso, raridade, valor, defesa, peca);
            }
            grava();
            achou = true;
        }
    }

    return achou;
}

//Imprime todos os itens do arquivo de forma ordenada 
void inventario::Inventario::imprimeInventario()
{
    ordena();
    cout << "=====================================================================" << endl;
    for (int i = 0; i < Itens.size(); i++)
    {
        Itens[i]->imprimeDados();
        cout << endl;
    }
    cout << "=====================================================================" << endl;
}

//Imprime todos os itens de um tipo do arquivo de forma ordenada 
void inventario::Inventario::imprimeInventarioTipo(int tipo)
{
    ordena();
    cout << "=====================================================================" << endl;
    for (int i = 0; i < Itens.size(); i++)
    {
        if(Itens[i]->getTipo() == tipo)
            Itens[i]->imprimeDados();
            cout << endl;
    }
    cout << "=====================================================================" << endl;
}

//Metodo que ordena os itens do arquivo
void inventario::Inventario::ordena()
{
    sort(Itens.begin(), Itens.end(), Iten::comparaIten);
    grava();
}

//Metodo que serve como menu para acessar todas as funções da classe
int inventario::Inventario::opcoes()
{
    int op;
    cout << "==============================Inventario==============================" << endl;
    cout << "[1] Imprimir todos os Itens do Inventario" << endl;
    cout << "[2] Imprimir so as armas/armaduras" << endl;
    cout << "[3] Adicionar iten" << endl;
    cout << "[4] Atualizar iten" << endl;
    cout << "[5] Remover iten" << endl;
    cout << "[6] Procurar Iten" << endl;
    cout << "[7] Fim" << endl;
    cout << "======================================================================" << endl;
    cin >> op;
    return op;
}

//metodo responsavel por passar os itens de um vetor e salvar em um arquivo binario
void inventario::Inventario::grava()
{
    int aux1, tam;
    float aux2;
    string aux3;
    Arma *arma;
    Armadura *armadura;

    ofstream out("inventario.dat", ios::binary);

    for (long unsigned int i = 0; i < Itens.size(); i++)
    {
        aux1 = Itens[i]->getTipo();
        out.write(reinterpret_cast<char *>(&aux1), sizeof(aux1));

        aux3 = Itens[i]->getNome();
        tam = aux3.size();
        out.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        out.write(reinterpret_cast<char *>(&aux3[0]), tam);

        aux2 = Itens[i]->getPeso();
        out.write(reinterpret_cast<char *>(&aux2), sizeof(aux2));

        aux1 = Itens[i]->getRaridade();
        out.write(reinterpret_cast<char *>(&aux1), sizeof(aux1));

        aux1 = Itens[i]->getValor();
        out.write(reinterpret_cast<char *>(&aux1), sizeof(aux1));

        if (Itens[i]->getTipo() == 0)
        {
            arma = dynamic_cast<Arma *>(Itens[i]);

            aux2 = arma->getDano();
            out.write(reinterpret_cast<char *>(&aux2), sizeof(aux2));

            aux1 = arma->getElemento();
            out.write(reinterpret_cast<char *>(&aux1), sizeof(aux1));

            aux3 = arma->getTipoArma();
            tam = aux3.size();
            out.write(reinterpret_cast<char *>(&tam), sizeof(tam));
            out.write(reinterpret_cast<char *>(&aux3[0]), tam);
        }
        else if (Itens[i]->getTipo() == 1)
        {
            armadura = dynamic_cast<Armadura *>(Itens[i]);

            aux2 = armadura->getDefesa();
            out.write(reinterpret_cast<char *>(&aux2), sizeof(aux2));

            aux1 = armadura->getPeca();
            out.write(reinterpret_cast<char *>(&aux1), sizeof(aux1));
        }
    }
    out.close();
}

//Metodo responsavel por ler os itens arquivos de um arquivo binario e armazenar em um vetor
void inventario::Inventario::le()
{
    int tipo, tam, raridade, valor, elemento, peca;
    float peso, dano, critico, defesa;
    string nome, tipoArma;

    ifstream in("inventario.dat", ios::binary);

    if (in.is_open())
    {
        Itens.clear();

        in.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        while (in.good())
        {
            in.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            nome.resize(tam);

            in.read(reinterpret_cast<char *>(&nome[0]), tam);

            in.read(reinterpret_cast<char *>(&peso), sizeof(peso));

            in.read(reinterpret_cast<char *>(&raridade), sizeof(raridade));

            in.read(reinterpret_cast<char *>(&valor), sizeof(valor));

            switch (tipo)
            {
            case 0:
                in.read(reinterpret_cast<char *>(&dano), sizeof(dano));

                in.read(reinterpret_cast<char *>(&elemento), sizeof(elemento));

                in.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                tipoArma.resize(tam);
                in.read(reinterpret_cast<char *>(&tipoArma[0]), tam);

                Itens.push_back(new Arma(nome, peso, raridade, valor, dano, elemento, tipoArma));

                break;
            case 1:
                in.read(reinterpret_cast<char *>(&defesa), sizeof(defesa));

                in.read(reinterpret_cast<char *>(&peca), sizeof(peca));

                Itens.push_back(new Armadura(nome, peso, raridade, valor, defesa, peca));
                break;
            }

            in.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        }
    }

    in.close();
}