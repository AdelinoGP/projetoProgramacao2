#include "DadoSimulador.h"

#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

string DadoSimulador::paraString()
{
    ostringstream oss;
    oss << "DataHora: " << put_time(&dataTempoCaptura, "%d-%m-%Y %H-%M-%S") << " Temperatura: " << to_string(temperatura) << " Resistor: " << to_string(resistorOn) << " Cooler: " << to_string(coolerOn);
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
