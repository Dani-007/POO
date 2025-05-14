#include "DataHorario.h"

DataHorario::DataHorario(int dia, int mes, int ano, int hora, int min, int seg):ano(ano), mes(mes), dia(dia), hora(hora), min(min), seg(seg){
    
    bool aux = true;

    if (ano < 0 || mes < 0 || mes > 12 || dia < 0 || hora < 0 || hora > 23 || min < 0 || min > 59 || seg < 0 || seg > 59) //Verifica se os dados são validos
    {
        aux = false;
    }
    
    switch (mes)
    {
    case 1: 
    case 3:
    case 5:
    case 7: 
    case 8: 
    case 10: 
    case 12:
        if(dia > 31){ //verifica se os numero de dias dos meses que possuem 31 dias está correto
            aux = false; 
        }
        break;
    
    case 2:
        if(ano % 400 == 0){ //verifica se o ano é bisexto, e se sim ve se ele não possui mais de 29 dias ou 28 se não for bisexto  
                if(dia > 29)
                    aux = false;
        }
        else{
            if( (ano % 4 == 0) && (ano % 100 != 0) ){
                if(dia > 29)
                    aux = false;
            }
            else{
                if(dia > 28)
                    aux = false;
            }
        }
        break;

    default:
        if(dia > 30){ //verifica o numero de dia dos meses com 30 dias
            aux = false;
        }
        break;
    }

    if(aux = false) // se a data inserida for invalida será setado a data 01/01/0001 00:00:00
    {
        ano = 1;
        mes = 1;
        dia = 1;
        hora = 0;
        min = 0;
        seg = 0;
    }
}

DataHorario::~DataHorario(){

}

int DataHorario::getAno(){
    return ano;
}

int DataHorario::getMes(){
    return mes;
}

int DataHorario::getDia(){
    return dia;
}

int DataHorario::getHora(){
    return hora;
}

int DataHorario::getMinuto(){
    return min;
}

int DataHorario::getSegundo(){
    return seg;
}

void DataHorario::setAno(int ano){
    this -> ano = ano;
}

void DataHorario::setMes(int mes){
    this -> mes = mes;
}

void DataHorario::setDia(int dia){
    this -> dia = dia;
}

void DataHorario::setHora(int hora){
    this -> hora = hora;
}

void DataHorario::setMinuto(int min){
    this -> min = min;
}

void DataHorario::setSegundo(int seg){
    this -> seg = seg;
}

int DataHorario::compare(DataHorario& data){
    int data1, data2, aux;

    data1 = ano*10000000000+mes*100000000+dia*1000000+hora*10000+min*100+seg; //converte as datas para numero inteiro para que seja possivel a comparação
    data2 = data.ano*10000000000+data.mes*100000000+data.dia*1000000+data.hora*10000+data.min*100+data.seg;

    if(data1 == data2){ //verifica se as datas são iguais ou se uma é maior que a outra
        aux = 0;
    }
    else if (data1 > data2)
    {
        aux = 1;
    }
    else
    {
        aux = -1;
    }
    
    return aux;
}

void DataHorario::imprime(bool x){
    if(x){ //dependendo da boleana passada como parametro a data será imprimida no sistema de 12 ou 24 horas
        if(hora > 12){
            cout<<dia<<"/"<<mes<<"/"<<ano<<" "<<hora-12<<":"<<min<<":"<<seg<<" PM"<<endl;
        }
        else
        {
            cout<<dia<<"/"<<mes<<"/"<<ano<<" "<<hora<<":"<<min<<":"<<seg<<" AM"<<endl;
        }
    }
    else
    {
        cout<<dia<<"/"<<mes<<"/"<<ano<<" "<<hora<<":"<<min<<":"<<seg<<endl;
    }
    
}

void DataHorario::imprimePorExtenso(){ // ultilizando um vetor de string com o nomes dos meses, associamos a posição deles a o numero de cada mês
    string meses[12] = {"Janeiro","Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    cout<<dia<<" de "<<meses[mes-1]<<" de "<<ano<<" - "<<hora<<" horas, "<<min<<" minutos e "<<seg<<" segundos."<<endl;
}