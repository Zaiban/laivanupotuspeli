//                                                                  //
//                      Tarkista osuma
//                                                                  //

#include "rakenteet.h"
#include "vakiot.h"

bool tarkista_osuma(const VektoriTaulu &laivojen_sijainnit, VektoriTaulu &ammuntojen_sijainnit, ID_Luettelo &id_tiedot, string ampumiskoordinaatti, TilastoTiedot &tilastot, PeliTilanne &tilanne)
{
    const int L_KIRJAINKOORDINAATTI=ampumiskoordinaatti.at(0)-ASCII_A+2;
    const int L_NUMEROKOORDINAATTI=ampumiskoordinaatti.at(1)-ASCII_0+1;
    const int LAIVACHECK = laivojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI]-ASCII_0;

    int id_numerokoordinaatti;
    int id_kirjainkoordinaatti;
    int id_suunta;
    int id_pituus;


// Jos ammuntoja ei ole vielä suoritettu, asetetaan hutit_alussa    //
// -lippu trueksi.                                                  //

    static bool hutit_alussa;           //TILASTOINTI
    if(tilastot.i_ammuntoja_yht == 0)   //TILASTOINTI
        hutit_alussa = true;            //TILASTOINTI

// Jos osumakohdassa on laiva ja siihen ei ole jo ammuttu           //
// aikaisemmin, tuloksena on..
    if(    laivojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI] != ASCII_SPACE
        && ammuntojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI] != '*'
        && ammuntojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI] != '#'
        && ammuntojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI  ] != 'x')
//==================================================== O S U M A =============================================//
    {
    // Käydään ID listan laivat läpi yksi kerrallaan. Tarkoituksena on löytää   //
    // laiva,
        for(unsigned i=0; i<id_tiedot.size(); i++)
        {
        // Tallennetaan käsitel
            id_kirjainkoordinaatti = id_tiedot[i].at(1)-ASCII_A+2;
            id_numerokoordinaatti = id_tiedot[i].at(2)-ASCII_0+1;
            id_suunta = id_tiedot[i].at(3);
            id_pituus = id_tiedot[i].at(0)-ASCII_0;
            if(LAIVACHECK == id_pituus)
            {
            // Alustetaan tarkistusmuuttujat. Tarkistusmuuttujat määrittävät,   //
            // mihin suuntaan tarkistussilmukka lähtee tutkimaan pelialuetta.   //
                int n_tarkistus = 0;
                int k_tarkistus = 0;

                if(id_suunta == 'i' || id_suunta == 'I')
                    n_tarkistus = 1;

                if(id_suunta == 'l' || id_suunta == 'L')
                    n_tarkistus = -1;

                if(id_suunta == 'e' || id_suunta == 'E')
                    k_tarkistus = 1;

                if(id_suunta == 'p' || id_suunta == 'P')
                    k_tarkistus = -1;

            // Ajetaan tarkistussilmukka. Silmukka tarkistaa osumakohdasta      //
            // alkaen ruutu kerrallaan, löytyykö
                for(int j=0; j<id_pituus; j++)
                {
                //Tarkistetaan, osuttiinko laivaan                                  //
                    if(id_kirjainkoordinaatti  + ( k_tarkistus * j ) == L_KIRJAINKOORDINAATTI && id_numerokoordinaatti + ( n_tarkistus * j ) == L_NUMEROKOORDINAATTI)
                    {

                    // Tarkistetaan, oliko tämä ensimmäinen osuma laivaan. Jos oli,     //
                    // tallennetaan laivan ID, ja tieto monesko laukaus oli kyseessä.   //
                        if(id_tiedot[i].at(0) == id_tiedot[i].at(4))
                        {
                            tilastot.iii_vi_ekalaukaus.push_back(i);                            //TILASTOINTI
                            tilastot.iii_vi_ekalaukaus.push_back(tilastot.i_ammuntoja_yht);     //TILASTOINTI
                        }

                    // Koska laivaan osuttiin, vähennetään sen jäljellä olevia elämiä.. //
                        id_tiedot[i].at(4)--;

                    // ..ja kasvatetaan ammuntojen kokonais lkm laskuria..              //
                        tilastot.i_ammuntoja_yht++;     //TILASTOINTI

                    // ..ja asetetaan alun hutilaskuri falseksi..                       //
                        hutit_alussa = false;           //TILASTOINTI

                    // .. ja nollataan ohilaukaus sarjan laskuri.                       //
                        tilanne.ohilaukaus_sarja = 0;   //TILASTOINTI

                    // Tarkistetaan, onko laivalla vielä elämiä jäljellä.               //
                    // Jos on, asetetaan osumakohtaan tähti, tulostetaan ilmoitus,      //
                    // ja palautetaan true.                                             //
                        if(id_tiedot[i].at(4) > '0')
                        {
                            ammuntojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI] = '*';
                            cout << "\nLaukaus kohtaan " << ampumiskoordinaatti << " osui laivaan." << endl;


                            return true; // Osuma aiheutti vahinkoa
                        }

                    // Jos laivan elämät ovat lopussa peitetään se risuaidoilla,        //
                    // tulostetaan ilmoitus, tehdään tarvittavat tilastointi-operaatiot,//
                    // ja palautetaan true.                                             //
                        else
                        {
                            for(int k=0; k<id_pituus; k++)
                                ammuntojen_sijainnit[id_kirjainkoordinaatti + ( k_tarkistus * k )][ id_numerokoordinaatti + ( n_tarkistus * k )] = '#';

                            cout << "\nLaukaus kohtaan " << ampumiskoordinaatti << " upotti laivan." << endl;

                        // Tallennetaan upotetun laivan ID, ja tieto siitä                  //
                        // monennesko laukaus upotti kyseisen laivan.                       //
                            tilastot.iii_vi_monesko_upotti.push_back(i);                            //TILASTOINTI
                            tilastot.iii_vi_monesko_upotti.push_back(tilastot.i_ammuntoja_yht);     //TILASTOINTI


                        // Tallennetaan upotetun laivan ID, ja tieto siitä                  //
                        // minkä kokoinen laiva oli kyseessä.                               //
                            tilastot.iii_vi_laivankoko.push_back(i);                                //TILASTOINTI
                            tilastot.iii_vi_laivankoko.push_back(id_tiedot[i].at(0) - ASCII_0);     //TILASTOINTI

                            return true; // Osuma aiheutti vahinkoa
                        }


                    }

                }
            }
        }
    } // OSUMA päättyy

// Jos osumakohdassa ei ole laivaa ja siihen ei ole ammuttu         //
// aikaisemmin, tuloksena on.. =======HUTI========                  //
    if(laivojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI] == ASCII_SPACE
       && ammuntojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI] == ASCII_SPACE)
//===================================================== H U T I ==============================================//
    {
    // Asetetaan osumakohtaan rasti, ja tulostetaan viesti.             //
        ammuntojen_sijainnit[L_KIRJAINKOORDINAATTI][L_NUMEROKOORDINAATTI] = 'x';
        cout << "\nLaukaus kohtaan " << ampumiskoordinaatti << " ei osunut." << endl;

    // Kasvatetaan ammuntojen kokonais lkm laskuria                     //
        tilastot.i_ammuntoja_yht++;         //TILASTOINTI

    // Jos hutit alussa -lippu on vielä tosi, kasvatetaan laskuria.     //
        if(hutit_alussa == true)            //TILASTOINTI
            tilastot.ii_hutit_alussa++;     //TILASTOINTI

    // Kasvatetaan ohilaukaus-sarjaa seuraavaa laskuria. Lisäksi jos se //
    // ylittää edellisen tilastoidun sarjan, tallennetaan uusi tieto    //
    // tilastoihin.                                                     //
        tilanne.ohilaukaus_sarja++;         //TILASTOINTI
        if( tilastot.vii_pisin_hutisarja < tilanne.ohilaukaus_sarja)    //TILASTOINTI
            tilastot.vii_pisin_hutisarja = tilanne.ohilaukaus_sarja;    //TILASTOINTI
    } // HUTI päättyy

// Muussa tapauksessa osumakohtaan on jo ammuttu aikaisemmin,       //
// joten tulostetaan viesti.                                      //
    else
        cout << "\nVirhe! Olet jo ampunut tahan kohtaan." << endl;

// Jos ohjelma pääsee tänne asti, palautetaan false merkiksi siitä, //
// että osuma ei aiheuttanut vahinkoa laivoihin.                    //
    return false; // Osuma ei aiheuttanut vahinkoa
}
