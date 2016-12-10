//                                                                  //
//                      Alusta laiva ID
//                                                                  //

#include "rakenteet.h"
#include "vakiot.h"

void alusta_laiva_id(ID_Luettelo &luettelo, const int KUNKIN_LAIVAN_LKM[])
{
// Tyhjennet‰‰n edellinen luettelo                                  //
    luettelo.clear();

    int temp[SUURIN_LAIVA+1];

// Luodaan tilap‰istaulukko, jossa jokainen alkio sis‰lt‰‰ alkion   //
// numeron pituisten laivojen lukum‰‰r‰n.                           //
    for(int i=PIENIN_LAIVA; i<=SUURIN_LAIVA; i++)
        temp[i] = KUNKIN_LAIVAN_LKM[i];

// Luodaan muuttuja, joka sis‰lt‰‰ kaikkien laivojen yhteenlasketun //
// kappalem‰‰r‰n                                                    //
    int montakolaivaa = 0;

    for(int i=PIENIN_LAIVA; i<SUURIN_LAIVA+1; i++)
        montakolaivaa += KUNKIN_LAIVAN_LKM[i];


    int pituus=PIENIN_LAIVA;

// Alustetaan luettelo, jonka jokaiselle riville kirjoitetaan       //
// yhden laivan tiedot.                                             //
    for(int i=0; i < montakolaivaa; i++)
    {

        // Siirryt‰‰n luettelossa seuraavalle riville                       //
            luettelo.push_back("PKNSE");
            //Miss‰:    i = laivan oma ID
            //          P = laivan pituus
            //          K = laivan alkup‰‰n kirjainkoordinaatti
            //          N = laivan alkup‰‰n numerokoordinaatti
            //          S = laivan suunta
            //          E = j‰jlell‰ olevat el‰m‰t

        // Tallennetaan laivan pituus kohtiin P ja E                        //
            luettelo[i].at(0) = pituus+ASCII_0;
            luettelo[i].at(4) = pituus+ASCII_0;

        // V‰hennet‰‰n tilap‰istaulukon nykyisen alkion sis‰ltˆ‰ merkiksi   //
        // siit‰, ett‰ yksi alkion numeron kokoinen laiva on k‰sitelty.     //
            temp[pituus]--;

        // Jos kaikki kyseisen kokoiset laivat on jo k‰sitelty, siirryt‰‰n  //
        // k‰sittelem‰‰n seuraavan kokoisia laivoja.                        //
            if(temp[pituus] == 0)
                pituus++;
    }
}
