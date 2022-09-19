#ifndef DADOSIMULADOR_H_
#define DADOSIMULADOR_H_

#define SEPARADOR ';'

#include <ctime>
#include <iostream>

using namespace std;

class DadoSimulador
{
protected:
    double temperatura;
    bool resistorOn;
    bool coolerOn;

public:
    DadoSimulador();
    DadoSimulador(double temperatura, bool resistorOn, bool coolerOn);
    DadoSimulador(double temperatura, bool resistorOn, bool coolerOn, time_t dataTempoCaptura);
    time_t dataTempoCaptura;

    double getTemperatura() const { return temperatura; }
    string paraString();
    string paraCSV();
    string operator+(string str);
    bool operator==(DadoSimulador dado);
    bool operator!=(DadoSimulador dado);
    bool operator>(DadoSimulador dado);
    bool operator>=(DadoSimulador dado);
    bool operator<(DadoSimulador dado);
    bool operator<=(DadoSimulador dado);
    friend ostream &operator<<(ostream &os, const DadoSimulador &dado);
};

#endif