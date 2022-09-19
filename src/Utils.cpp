#include "Utils.h"

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

time_t StringParaTempo(string tempoComoString)
{
	struct tm tm;
	istringstream str(tempoComoString);
	str >> get_time(&tm, "%a %b %d %T %Y");
	time_t time = mktime(&tm);
	return time;
}
