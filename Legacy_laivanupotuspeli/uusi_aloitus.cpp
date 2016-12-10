//                                                                  //
//                      Uusi aloitus
//                                                                  //

#include "rakenteet.h"
#include "vakiot.h"

#include "prototyypit/kehys.h"
#include "prototyypit/alusta_laiva_id.h"

bool uusi_aloitus(const VektoriTaulu &TYHJATAULU, VektoriTaulu &laivojen_sijainnit, VektoriTaulu &ammuntojen_sijainnit,
                  PeliTilanne &tilanne, TilastoTiedot &tilastot, ID_Luettelo &luettelo, const int laivojen_kpl_maarat[])
{
    string varmistus="x";

    while( (varmistus != "k" || varmistus != "e") && tilanne.ammunta_kaynnissa == true)
    {
        cout << "\nVaroitus! Tama toiminto poistaa kaynnissa olevan pelitilanteen."
             "\n(k)ylla/(e)i" << endl;
        cin >> varmistus;

// Jos uutta peliä ei halutakkaan aloittaa,         //
// palautetaan FALSE.                               //
        if(varmistus == "e")
            return false;
    }

// Alustetaan tilannetietueen muuttujat             //

    tilanne.laivat_sijoiteltu = false;
    tilanne.ammunta_kaynnissa = false;
    tilanne.elamia_jaljella = 0;
    tilanne.ohilaukaus_sarja = 0;


// Nollataan ID -luettelo                           //

    alusta_laiva_id(luettelo, laivojen_kpl_maarat);

// Lasketaan laivojen elamien kokonaislukumaara     //
// ja tallennetaans se tilanne-tietueeseen          //
    for(unsigned i=0; i < luettelo.size(); i++)
    {
        tilanne.elamia_jaljella += ( luettelo[i].at(4)-ASCII_0 );
    }

// Nollataan tilastojen arvot                       //
    TilastoTiedot tyhjatilasto;
    tilastot = tyhjatilasto;
    tilastot.i_ammuntoja_yht=0;
    tilastot.ii_hutit_alussa=0;
    tilastot.vii_pisin_hutisarja=0;

// Alustetaan laivojen sijaintitaulukko             //
    laivojen_sijainnit = TYHJATAULU;
    kehys(laivojen_sijainnit);

// Alustetaan ammuntojen sijaintitaulukko           //
    ammuntojen_sijainnit = TYHJATAULU;
    kehys(ammuntojen_sijainnit);

    tilanne.ammunta_kaynnissa = false;

// Taulut ja tilastot nollattu, palautetaan TRUE    //
    return true;
}
