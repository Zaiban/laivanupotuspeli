//                                                                  //
//                      Ammunta
//                                                                  //

#include "rakenteet.h"
#include "vakiot.h"

#include "prototyypit/vakoilu.h"
#include "prototyypit/tarkista_osuma.h"

bool ammunta(const VektoriTaulu &laivojen_sijainnit, VektoriTaulu &ammuntojen_sijainnit, ID_Luettelo &id_tiedot, PeliTilanne &tilanne, TilastoTiedot &tilastot)
{
    tilanne.ammunta_kaynnissa = true;

// M��ritet��n kehyksen sis�reunan koordinaatit. T�m� tehd��n,      //
// koska halutaan k�sitell� vain kehyksen sis�puolista aluetta.     //
    const int L_REUNAMIN = KEHYKSENPAKSUUS;
    const int L_REUNAMAX = ammuntojen_sijainnit.size()-KEHYKSENPAKSUUS;

    string syote;
    bool syotteentarkistus;

// Toistetaan silmukkaa, kunnes kaikki laivat on tuhottu            //
    while(tilanne.elamia_jaljella > 0)
    {
    // Tulostetaan nykyinen pelitilanne                                 //
        cout << "\nPelitilanne on seuraava:\n";
        for(unsigned i=0; i<ammuntojen_sijainnit.size(); i++)
        {
            for(unsigned y=0; y<ammuntojen_sijainnit.size(); y++)
            {
                cout << ammuntojen_sijainnit[i][y] << " ";

            }
            cout << endl;
        }
    // Asetetaan sy�tteentarkistuslippu, ja pyydet��n                   //
    // pelaajalta ampumiskoordinaatit.                                  //
        syotteentarkistus = true;
        cout << "Anna ampumiskoordinaatit: ";
        cin >> syote;

    // Tarkistetaan, haluaako k�ytt�j� poistua ammuntatilasta           //
        if( syote == "p" || syote  == "P")
            return false; // Ammuntaa ei viel� viety loppuun asti

    // Tarkistetaan, haluaako k�ytt�j� vakoilla laivojen sijaintia      //
        if(syote == "/@" )
        {
            vakoilu(laivojen_sijainnit);
            syotteentarkistus = false;
        }

    // Tarkistetaan, onko sy�tteess� oikea m��r� merkkej�               //
        if( syote.size() != 2)
        {
            cout << "\nVirhe! Koordinaattien lkm ei tasmaa." << endl;
            syotteentarkistus = false;
        }

    // Jos sy�tteentarkistus on onnistunut..                            //
        if(syotteentarkistus == true)
        {
            const int KIRJAINKOORDINAATTI = syote.at(0)-ASCII_A+2;
            const int NUMEROKOODRINAATTI = syote.at(1)-ASCII_0+1;

        // ..tarkistetaan, ovatko koordinaatit pelialueen ulkopuolella..    //
            if(KIRJAINKOORDINAATTI < L_REUNAMIN || KIRJAINKOORDINAATTI > L_REUNAMAX
                    || NUMEROKOODRINAATTI < L_REUNAMIN || NUMEROKOODRINAATTI > L_REUNAMAX )

                cout << "\nVirhe! Koordinaatit pelialueen ulkopuolella." << endl;

        // ..ja mik�li eiv�t, suoritetan ammunta, ja jos ammus osui,        //
        // v�hennet��n j�ljell� olevista el�mist� yksi kappale.             //
            else if( tarkista_osuma(laivojen_sijainnit, ammuntojen_sijainnit, id_tiedot, syote, tilastot, tilanne ) == true)
            {
                tilanne.elamia_jaljella--;
            }
        }

    }
    return true; // Ammunta vietiin loppuun asti
}
