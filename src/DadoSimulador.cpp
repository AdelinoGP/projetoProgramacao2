#include "DadoSimulador.h"

#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

DadoSimulador::DadoSimulador()
{
    this->temperatura = 0;
    this->resistorOn = false;
    this->coolerOn = false;
    this->dataTempoCaptura = NULL;
}

DadoSimulador::DadoSimulador(double temperatura, bool resistorOn, bool coolerOn)
{
    this->temperatura = temperatura;
    this->resistorOn = resistorOn;
    this->coolerOn = coolerOn;
    time_t currentTime = time(0);
    this->dataTempoCaptura = gmtime(&currentTime);
}

string DadoSimulador::paraString()
{
    ostringstream oss;
    oss << "DataHora: " << put_time(dataTempoCaptura, "%d-%m-%Y %H-%M-%S") << " Temperatura: " << to_string(temperatura) << " Resistor: " << to_string(resistorOn) << " Cooler: " << to_string(coolerOn);
    return oss.str();
}

string DadoSimulador::operator+(string str)
{
    return str + paraString();
}
bool DadoSimulador::operator==(DadoSimulador dado)
{
    return this->temperatura == dado.temperatura;
}

bool DadoSimulador::operator!=(DadoSimulador dado)
{
    return this->temperatura != dado.temperatura;
}

bool DadoSimulador::operator>(DadoSimulador dado)
{
    return this->temperatura > dado.temperatura;
}

bool DadoSimulador::operator>=(DadoSimulador dado)
{
    return this->temperatura >= dado.temperatura;
}

bool DadoSimulador::operator<(DadoSimulador dado)
{
    return this->temperatura < dado.temperatura;
}

bool DadoSimulador::operator<=(DadoSimulador dado)
{
    return this->temperatura <= dado.temperatura;
}

ostream& operator<<(ostream& os, const DadoSimulador& dado)
{
    os << "DataHora: " << put_time(dado.dataTempoCaptura, "%d-%m-%Y %H-%M-%S") << " Temperatura: " << to_string(dado.temperatura) << " Resistor: " << to_string(dado.resistorOn) << " Cooler: " << to_string(dado.coolerOn);;
    return os;
}
