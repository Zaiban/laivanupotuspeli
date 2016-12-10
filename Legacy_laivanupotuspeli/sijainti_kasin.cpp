//                                                                  //
//                      Sijainti k‰sin
//                                                                  //

#include "vakiot.h"
#include "rakenteet.h"

#include "prototyypit/numerot_sanoiksi.h"
#include "prototyypit/vakoilu.h"
#include "prototyypit/aseta_laiva.h"

bool sijainti_kasin(VektoriTaulu &laivojen_sijainnit, int lukumaara[], ID_Luettelo &laiva_id)
{
// M‰‰ritell‰n muuttuja, joka sis‰lt‰‰ uuden laivan                 //
// alkutiedot.                                                      //
    LaivanRunko raakile;

    string syote;
    raakile.pituus=PIENIN_LAIVA;
    raakile.koordinaatit="XX";
    raakile.suunta="X";
    bool syotteentarkistus;

// Alustetaan laskuri joka s‰ilytt‰‰ tiedon siit‰, monesko          //
// nykyisen pituinen laiva on k‰sittelyss‰.                         //
    int laskuri = 0;

// Toistetaan silmukkaa, kunnes kaikki laivat on sijoiteltu         //
    while(raakile.pituus <= SUURIN_LAIVA)
    {

    // Asetetaan syˆtteentarkistuslippu, ja pyydet‰‰n                   //
    // pelaaajalta laivan koordinaatit.                                 //
        syotteentarkistus = true;
        cout << "\nAnna ";
        numerot_sanoiksi(raakile.pituus + 100);
        cout << " pituisen laivan alkupiste:";
        cin >> syote;

    // Tarkistetaan, haluaako k‰ytt‰j‰ poistua sijoittelutilasta        //
        if(syote == "p" ||syote  == "P")
            return false;


    // Tarkistetaan, onko syotteessa oikea m‰‰r‰ merkkej‰               //
        if(syote.size() != 2)
        {
            syotteentarkistus = false;
            cout << "\nVirhe! Koordinaattien lkm ei tasmaa." << endl;
        }

    // Tarkistetaan, haluaako k‰ytt‰j‰ vakoilla laivojen sijaintia      //
        if(syote == "/@")
        {
            vakoilu(laivojen_sijainnit);
            syotteentarkistus = false;
        }

    // Jos syˆte on t‰ss‰ kohta ok, talletetaan se raakileeseen         //
        if(syotteentarkistus == true)
        {
            raakile.koordinaatit.at(0)=syote.at(0);
            raakile.koordinaatit.at(1)=syote.at(1);

         // Tyhjennet‰‰n edellinen syˆte, ja kysyt‰‰n pelaajalta suuntaa    //
            syote.clear();
            cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
            cin >> syote;

        // Tarkistetaan suunnan oikeellisuus                                //
            if(syote != "P" && syote != "p" && syote != "E" && syote != "e" &&
                    syote != "L" &&syote != "l" && syote != "I" && syote != "i")
            {
                syotteentarkistus=false;
                cout << "\nVirhe! Suuntatieto ei tasmaa." << endl;
            }

        // Jos syˆte on t‰ss‰ kohtaa ok, talletetaan se raakileeseen        //
            if(syotteentarkistus == true)
            {
                raakile.suunta.at(0)=syote.at(0);
                syote.clear();

            // Tarkistetaan seuraavaksi, onnistuuko laivan asettelu             //
            // raakileen tiedoilla.                                             //
                if(aseta_laiva(laivojen_sijainnit, raakile, laiva_id) == true)
                {
                // Jos onnistuu, lis‰t‰‰n laskuria yhdell‰..                        //
                    laskuri++;

                // ..ja mik‰li kyseess‰ oli viimeinen nykyisen pituinen laiva,      //
                // kasvatetaan pituusmuuttujaa yhdell‰ ja nollataan laskuri.        //
                    if(laskuri==lukumaara[raakile.pituus])
                    {
                        raakile.pituus++;
                        laskuri=0;
                    }

                }
            // Jos laivan sijoittelu ep‰onnistui, tulostetaan virheviesti.          //
                else
                    cout << "\nVirhe! Laiva ei mahdu." << endl;
            }
        }
    }
    return true; // Laivojen sijoittelu k‰sin suoritettu loppuun
}
