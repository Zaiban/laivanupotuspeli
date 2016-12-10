//                                                                  //
//                      Aseta laiva
//                                                                  //

#include "vakiot.h"
#include "rakenteet.h"

using namespace std;

bool aseta_laiva(VektoriTaulu &laivojen_sijainnit, LaivanRunko &raakile, ID_Luettelo &luettelo)
{
// T‰m‰ muuttuja s‰ilytt‰‰ tiedon siit‰, monettako laivaa ollaan    //
// pelialueelle asettamassa.                                        //
    static unsigned monesko_laiva = 0;

// M‰‰ritet‰‰n kehyksen sis‰reunan koordinaatit. T‰m‰ tehd‰‰n,      //
// koska halutaan k‰sitell‰ vain kehyksen sis‰puolista aluetta.     //
    const int L_REUNAMIN = KEHYKSENPAKSUUS;
    const int L_REUNAMAX = laivojen_sijainnit.size()-KEHYKSENPAKSUUS;

// Tallennetaan laivaehdokkaan alkukoordinaatit integer -muotoisina //
    const int L_KIRJAINKOORDINAATTI=raakile.koordinaatit.at(0)-ASCII_A+2;
    const int L_NUMEROKOORDINAATTI=raakile.koordinaatit.at(1)-ASCII_0+1;

// Tarkistetaan, sijaitsevatko laivaehdokkaan alkukoordinaatit      //
// pelialueen ulkopuolella.                                         //
    if(L_KIRJAINKOORDINAATTI < L_REUNAMIN || L_KIRJAINKOORDINAATTI > L_REUNAMAX
            || L_NUMEROKOORDINAATTI < L_REUNAMIN || L_NUMEROKOORDINAATTI > L_REUNAMAX )
    {
        cout << "Virhe! Koordinaatit pelialueen ulkopuolella." << endl;
        return false; // Laivan asettelu ep‰onnistunut
    }

// Alustetaan tarkistusmuuttujat. Tarkistusmuuttujat m‰‰ritt‰v‰t,   //
// mihin suuntaan tarkistussilmukka l‰htee tutkimaan pelialuetta.   //
    int n_tarkistus = 0;
    int k_tarkistus = 0;

    if(raakile.suunta.at(0) == 'i' || raakile.suunta.at(0) == 'I')
        n_tarkistus = 1;

    if(raakile.suunta.at(0) == 'l' || raakile.suunta.at(0) == 'L')
        n_tarkistus = -1;

    if(raakile.suunta.at(0) == 'e' || raakile.suunta.at(0) == 'E')
        k_tarkistus = 1;

    if(raakile.suunta.at(0) == 'p' || raakile.suunta.at(0) == 'P')
        k_tarkistus = -1;

// Ajetaan tarkistussilmukka. Silmukka tarkistaa aloituspisteest‰   //
// alkaen, onko laivaehdokkaan tiell‰ muita laivoja. Silmukka       //
// etenee laivan pituuden verran siihen suuntaan, mik‰ on           //
// m‰‰ritelty tarkistusmuuttujassa.                                 //
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<raakile.pituus; j++)
        {
            if(i==1)
            {
                laivojen_sijainnit[ L_KIRJAINKOORDINAATTI + ( j * k_tarkistus) ][ L_NUMEROKOORDINAATTI + ( j * n_tarkistus) ] = ASCII_0 + raakile.pituus;
            }
            else if(laivojen_sijainnit[ L_KIRJAINKOORDINAATTI + ( j * k_tarkistus) ][ L_NUMEROKOORDINAATTI + ( j * n_tarkistus) ] != ASCII_SPACE && i == 0)
                return false; // Laivan asettelu ep‰onnistunut

        }
    }


// T‰ss‰ vaiheessa laivan asettelu on onnistunut. Tallennetaan      //
// laivan tiedot ID -luetteloon.                                    //
    luettelo[monesko_laiva].at(1)=raakile.koordinaatit.at(0);
    luettelo[monesko_laiva].at(2)=raakile.koordinaatit.at(1);
    luettelo[monesko_laiva].at(3)=raakile.suunta.at(0);

// Lis‰t‰‰n laskuriin yksi, jotta pysyt‰‰n tietoisina monettako     //
// laivaa ollaan pelialueelle asettamassa.
    monesko_laiva++;

// Jos pelialueelle on nyt aseteltu kaikki laivat, nollataan        //
// laskuri seuraavaa asettelukierrosta varten.                      //
    if(monesko_laiva == luettelo.size())
        monesko_laiva=0;

    return true; // Laivan asettelu onnistunut
}
