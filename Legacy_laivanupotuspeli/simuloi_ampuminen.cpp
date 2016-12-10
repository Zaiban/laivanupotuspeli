//                                                                  //
//                      Simuloi ampuminen
//                                                                  //

#include <cstdlib>
#include <windows.h>

#include "rakenteet.h"
#include "vakiot.h"

#include "prototyypit/tarkista_osuma.h"

bool simuloi_ampuminen(const VektoriTaulu &LAIVOJEN_SIJAINNIT, VektoriTaulu &ammuntojen_sijainnit,
                       ID_Luettelo &luettelo, TilastoTiedot &tilastot, PeliTilanne &tilanne, const int &simulointi_viive)
{
//                                                                  //
// Satunnaisgeneraattori koordinaateille                            //
    string ampumiskoordinaatti="XX";
    int sivunpituus=LAIVOJEN_SIJAINNIT.size() - 2 * KEHYKSENPAKSUUS;
    string kirjaimet="ABCDEFGHI";
    string numerot="123456789";

    ampumiskoordinaatti.at(0)=kirjaimet.at(rand()%sivunpituus);
    ampumiskoordinaatti.at(1)=numerot.at(rand()%sivunpituus);

    int int_kirjkoord = ampumiskoordinaatti.at(0)-ASCII_A+2;
    int int_nrokoord = ampumiskoordinaatti.at(1)-ASCII_0+1;

    int ilmsuunt_rand;
    string temp;
    int laskuri=0;

    cout << "Anna ampumiskoordinaatit: " << ampumiskoordinaatti << endl;

// Toistetaan silmukkaa kunnes elämät loppuvat                      //
    while (tilanne.elamia_jaljella > 0)
    {
        cout << "\n======================" << endl;
        cout << " Simulaatio kaynnissa " << endl;
        cout << "======================" << endl;

        // Jos laukaus osui, vähennetään jäljellä olevia elämiä             //
        if(tarkista_osuma(LAIVOJEN_SIJAINNIT, ammuntojen_sijainnit, luettelo, ampumiskoordinaatti, tilastot, tilanne ) == true)
        {
            tilanne.elamia_jaljella--;
        }



        // Tulostetaan pelitilanne                                          //
        cout << "\nPelitilanne on seuraava:\n" << endl;
        for(unsigned i=0; i<ammuntojen_sijainnit.size(); i++)
        {
            for(unsigned y=0; y<ammuntojen_sijainnit.size(); y++)
            {
                cout << ammuntojen_sijainnit[i][y] << " ";

            }
            cout << endl;
        }

        // Jos edellinen laukaus osui laivaan mutta ei upottanut sitä,      //
        // seuraava laukaus kohdistetaan kohtaan, joka on edellisen         //
        // ammunnan vieressä ja johon ei ole vielä ammuttu.                 //
        if( ammuntojen_sijainnit[int_kirjkoord][int_nrokoord] == '*' && laskuri != 20)
        {
            // Tallennetaan edellinen ampumiskoordinaatti                       //
            // väliaikaismuuttujaan                                             //
            temp = ampumiskoordinaatti;

            // Laskuri varmistaa, että silmukkaan ei jäädä jumiin mikäli        //
            // pakotietä ei ole
            laskuri = 0;

            // While silmukan ehto varmistaa, että ampumiskoordinaatiksi        //
            // valikoituu kohta, johon ei ole vielä ammuttu.                    //
            while(ammuntojen_sijainnit[int_kirjkoord][int_nrokoord] != ASCII_SPACE && laskuri < 20)
            {
                // Luodaan satunnaisesti luku välitä 1-4, joka määrittää mihin  //
                // kohtaan seuraavaksi ammutaan (pohj ete ita lans ?)           //
                ilmsuunt_rand = rand()%4+1;
                // Valitaan seuraava ammuntapiste riippuen randin tuloksesta    //
                if(ilmsuunt_rand == 1) //etelään
                {
                    ampumiskoordinaatti = temp;
                    ampumiskoordinaatti.at(0)++;
                }
                if(ilmsuunt_rand == 2) //pohjoiseen
                {
                    ampumiskoordinaatti = temp;
                    ampumiskoordinaatti.at(0)--;
                }
                if(ilmsuunt_rand == 3) //itään
                {
                    ampumiskoordinaatti = temp;
                    ampumiskoordinaatti.at(1)++;
                }
                if(ilmsuunt_rand == 4) //länteen
                {
                    ampumiskoordinaatti = temp;
                    ampumiskoordinaatti.at(1)--;
                }
                int_kirjkoord = ampumiskoordinaatti.at(0)-ASCII_A+2;
                int_nrokoord = ampumiskoordinaatti.at(1)-ASCII_0+1;
                laskuri++;
            }
            // Jos silmukka epäonnistuu (laskuri saavuttaa 20), palautetaan     //
            // ampumiskoordinaatti ennalleen
            if(laskuri == 20)
            {
                ampumiskoordinaatti = temp;
                int_kirjkoord = ampumiskoordinaatti.at(0)-ASCII_A+2;
                int_nrokoord = ampumiskoordinaatti.at(1)-ASCII_0+1;
            }

        }

        // Muussa tapauksessa while -silmukan ehto varmistaa, että          //
        // ampumiskoordinaatiksi valikoituu kohta,                          //
        // johon ei ole vielä ammuttu.                                      //
        else while(( ammuntojen_sijainnit[int_kirjkoord][int_nrokoord] != ASCII_SPACE && tilanne.elamia_jaljella > 0) || laskuri == 20)
            {
                ampumiskoordinaatti.at(0)=kirjaimet.at(rand()%sivunpituus);
                ampumiskoordinaatti.at(1)=numerot.at(rand()%sivunpituus);

                int_kirjkoord = ampumiskoordinaatti.at(0)-ASCII_A+2;
                int_nrokoord = ampumiskoordinaatti.at(1)-ASCII_0+1;

                laskuri = 0;
            }

        // Jos simulointiviiveeksi on asetettu 0, tapahtuu seuraavaa        //
        if(tilanne.elamia_jaljella > 0 && simulointi_viive == 0)
        {
            cout << "Anna ampumiskoordinaatit: " << ampumiskoordinaatti << endl;
            system("PAUSE");
        }

        // Jos simulointiviiveeksi on asetettu >0, tapahtuu seuraavaa       //
        else if(tilanne.elamia_jaljella > 0 && simulointi_viive > 0)
        {
            cout << "Anna ampumiskoordinaatit: " << ampumiskoordinaatti << endl;
            Sleep(simulointi_viive * 1000);
        }
    }

    return true;
}
