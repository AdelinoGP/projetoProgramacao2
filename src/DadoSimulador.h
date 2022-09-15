#ifndef DADOSIMULADOR_H_
#define DADOSIMULADOR_H_

#include <ctime>
#include <iostream>

using namespace std;

class DadoSimulador
{
public:
    double temperatura;
    bool resistorOn;
    bool coolerOn;
    tm dataTempoCaptura;
    string paraString();
    string operator+(string str);
    bool operator==(DadoSimulador dado);
    bool operator!=(DadoSimulador dado);
    bool operator>(DadoSimulador dado);
    bool operator>=(DadoSimulador dado);
    bool operator<(DadoSimulador dado);
    bool operator<=(DadoSimulador dado);
};

#endif