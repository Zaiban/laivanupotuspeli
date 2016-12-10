//                                                                  //
//                      Kehys
//                                                                  //

#include "vakiot.h"
#include "rakenteet.h"

using namespace std;

void kehys(VektoriTaulu &taulu)
{
    const int L_KOKO=taulu.size();

    for(int i=KEHYKSENPAKSUUS; i<L_KOKO-KEHYKSENPAKSUUS; i++)
    {
        taulu[0][i]=ASCII_0-1+i;                 // Lis�� numerot taulun yl�reunaan
        taulu[L_KOKO-1][i]=ASCII_0-1+i;          // Lis�� numerot taulun alareunaan
        taulu[i][0]=63+i;                        // Lis�� kirjaimet taulun vasempaan reunaan
        taulu[i][L_KOKO-KEHYKSENPAKSUUS+1]=63+i; // Lis�� kirjaimet taulun vasempaan reunaan
        taulu[i][1]='|';                         // Lis�� viivat taulun vasempaan reunaan
        taulu[i][L_KOKO-KEHYKSENPAKSUUS]='|';    // Lis�� viivat taulun oikeaan reunaan

    }
    for(int i = KEHYKSENPAKSUUS - 1 ; i <= L_KOKO - KEHYKSENPAKSUUS; i++)
    {
        taulu[KEHYKSENPAKSUUS - 1][i]='-';      // Lis�� viivat taulun yl�reunaan
        taulu[L_KOKO - KEHYKSENPAKSUUS][i]='-'; // Lis�� viivat taulun alareunaan
    }

}
