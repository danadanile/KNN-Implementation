#include <sstream>
#include "DistanceType.h"
#include "VectorMap.h"
#include "Server.h"
#include "Cli.h"
#include "StandartIO.h"
#include "CheckFuncs.h"
#include <cstdlib>
#define P 2
#define CHAR_SUM_INT 10

using namespace std;

/// @brief which number simbolized distance name.
enum Choise
{
    AUC = 1,
    MAN = 2,
    CHB = 3,
    CAN = 4,
    MIN = 5
};

int main(int argc, char **argv){
    
    DefaultIO *dio = new StandartIO();
    Cli cli(dio);

}
