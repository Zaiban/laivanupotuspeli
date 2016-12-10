//                                                                  //
//                      Arvonta
//                                                                  //

#include <cstdlib>
#include "rakenteet.h"
#include "vakiot.h"

#include "prototyypit/aseta_laiva.h"

void sijainti_arpomalla(VektoriTaulu &laivojen_sijainnit, int conf_laivojen_lkm[], ID_Luettelo &luettelo)
{
// M‰‰ritell‰n muuttuja, joka sis‰lt‰‰ uuden laivan                 //
// alkutiedot.                                                      //
    LaivanRunko raakile;

    raakile.pituus = PIENIN_LAIVA;
    raakile.koordinaatit = "XX";
    raakile.suunta = "X";

// M‰‰ritell‰‰n stringit, joiden sis‰lt‰ laivan alkutiedot          //
// valitaan satunnaisesti.                                          //

    const string L_KIRJAIMET = "ABCDEFGHI";
    const string L_NUMEROT = "123456789";
    const string L_ILMANSUUNNAT = "ILPE";

    const int L_SIVUNPITUUS = laivojen_sijainnit.size() - 2 * KEHYKSENPAKSUUS;

// Alustetaan laskuri joka s‰ilytt‰‰ tiedon siit‰, monesko          //
// nykyisen pituinen laiva on k‰sittelyss‰.                         //
    int laskuri = 0;

// Toistetaan silmukkaa, kunnes kaikki laivat on arvottu            //
    while(raakile.pituus <= SUURIN_LAIVA)
    {
    // Arvotaan laivan alkutiedot satunnaisesti, ja sijoitetaan ne      //
    // raakile -muuttujaan.                                             //
        raakile.koordinaatit.at(0) = L_KIRJAIMET.at( rand()%L_SIVUNPITUUS );
        raakile.koordinaatit.at(1) = L_NUMEROT.at( rand()%L_SIVUNPITUUS );
        raakile.suunta.at(0) = L_ILMANSUUNNAT.at( rand()%4 );

    // Yritet‰‰n asettaa laivaa arvotuilla alkutiedoilla                //
        if( aseta_laiva(laivojen_sijainnit, raakile, luettelo) == true )
        {

        // Jos laivan asettelu onnistui, kasvatetaan laskuria yhdell‰       //
            laskuri++;

        // Mik‰li aseteltu laiva oli viimeinen nykyisen pituinen laiva,     //
        // kasvatetaan pituusmuuttujaa yhdell‰ ja nollataan laaskuri.       //
            if( laskuri == conf_laivojen_lkm[raakile.pituus] )
            {
                raakile.pituus++;
                laskuri=0;
            }
        }
    }
}
