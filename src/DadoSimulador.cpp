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
    this->dataTempoCaptura = time(0);
}

DadoSimulador::DadoSimulador(double temperatura, bool resistorOn, bool coolerOn, time_t dataTempoCaptura)
{
    this->temperatura = temperatura;
    this->resistorOn = resistorOn;
    this->coolerOn = coolerOn;
    this->dataTempoCaptura = dataTempoCaptura;
}

string DadoSimulador::paraString()
{
    ostringstream oss;
    char buf[100];
    strftime(buf, 100, "%a %b %d %T %Y", localtime(&dataTempoCaptura));
    oss << "DataHora: " << buf << " Temperatura: " << to_string(temperatura) << " Resistor: " << to_string(resistorOn) << " Cooler: " << to_string(coolerOn);
    return oss.str();
}

string DadoSimulador::paraCSV()
{
    ostringstream oss;
    char buf[100];
    strftime(buf, 100, "%a %b %d %T %Y", localtime(&dataTempoCaptura));
    oss << buf << SEPARADOR << to_string(temperatura) << SEPARADOR << to_string(resistorOn) << SEPARADOR << to_string(coolerOn);
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

ostream &operator<<(ostream &os, const DadoSimulador &dado)
{
    char buf[100];
    strftime(buf, 100, "%a %b %d %T %Y", localtime(&(dado.dataTempoCaptura)));
    os << "DataHora: " << buf << " Temperatura: " << to_string(dado.temperatura) << " Resistor: " << to_string(dado.resistorOn) << " Cooler: " << to_string(dado.coolerOn);
    return os;
}
