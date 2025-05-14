#include "Cesar.h"

cifra::Cesar::Cesar(){
};

void cifra::Cesar::encripte(string fileIn, string fileOut, int k){
    int x;
    string linha;
    ifstream in(fileIn);
    ofstream out(fileOut);
    // garante que o parametro k fique entre -26 e 26
    x = k/26;

    if(k > 26)
        k = k - (x*26);

    if(k < (-26))
        k = k - (x*26); 

    while (getline(in, linha)){ //lê linha por linha do arquivo e armazena a linha na string
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] >= 'A' && linha[i] <= 'Z'){ //verifica se é uma letra maiuscula
                
                /*verifica se o caractere deslocado não sai do alfabeto na tabela ascii
                se s,im ele corrige o deslocamento para que ele fique dentro do alfabeto*/ 
                if((linha[i] + k) < 65) 
                    linha[i] = linha[i] + k + 26;
                else if((linha[i] + k) > 90)
                    linha[i] = linha[i] + k - 26;
                else
                    linha[i] = linha[i] + k;
            }
            else if(linha[i] >= 'a' && linha[i] <= 'z'){ //verifica se é uma letra minuscula
                
                /*verifica se o caractere deslocado não sai do alfabeto na tabela ascii
                se sim ele coriige o deslocamento para que ele fique dentro do alfabeto*/
                if((linha[i] + k) < 97)
                    linha[i] = linha[i] + k + 26;
                else if((linha[i] + k) > 122)
                    linha[i] = linha[i] + k - 26;
                else
                    linha[i] = linha[i] + k;
            }
        }
        out << linha << '\n'; //imprimi a linha já criptografada no arquivo
    }
}
