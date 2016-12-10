//                                                                  //
//                      Setup
//                                                                  //

#include "vakiot.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool setup(int &sivunpituus, int laivat[], int &s_viive)
{
// Tarkistetaan ensin, onko laiva.txt jo olemassa. Mikäli sitä ei   //
// löydy, se luodaan oletusarvoja käyttäen ohjelman ajohakemistoon. //                   //

    ifstream config_i("laiva.txt");

    if (!config_i)
    {
        cout << "\nAsetustiedostoa ei loytynyt, luodaan..\n";
        ofstream config_o("laiva.txt");

// Tarkistetaan tässä välissä, onnistuiko tiedoston luominen.       //
// Mikäli se epäonnistui (ohjelman ajohakemisto on esimerkiksi      //
// kirjoitussuojattu), aliohjelma keskeytetään.                     //

        if(!config_o)
            return false; // Asetustiedoston käsittely epäonnistui

        config_o << "#Pelikentan sivun pituutta voi saataa valilla 5-9: " << endl;
        config_o << "pelikentan_sivu=7" << endl;
        config_o << "#Eripituisten laivojen lukumaaraa voi saataa valilla 0-5: " << endl;
        config_o << "5_laivat=1" << endl;
        config_o << "4_laivat=1" << endl;
        config_o << "3_laivat=1" << endl;
        config_o << "2_laivat=1" << endl;
        config_o << "#Simuloinnin nopeutta voi saataa asettamalla halutun" << endl;
        config_o << "#viiveen kokonaisina sekunteina. Jos viiveeksi asetetaan 0," << endl;
        config_o << "#pelaajan taytyy painaa nappainta edetakseen simulaatiossa." << endl;
        config_o << "simulointi_viive=0" << endl;
        config_o.close();
        cout << "..asetustiedosto 'laiva.txt' luotu onnistuneesti!" << endl;
        config_i.open("laiva.txt");
    }

// Stringstream -olion avulla voidaan helposti muuttaa sille        //
// syötetyt string -tyyppiset numeroita sisältävät merkkijonot      //
// integereiksi.                                                    //

    stringstream ss;
    string config_rivi;

// Seuraavaksi tutkitaan asetustiedoston sisältö rivi kerrallaan,   //
//  ja parsitaan sieltä tarvittavat arvot.                          //

    while(getline(config_i, config_rivi))
    {
    // Etsitään käsiteltävästä rivistä tekstiosuutta  joka määrittää,   //
    // minkä asetuksen rivi sisältää.                                   //

        if(!config_rivi.find("pelikentan_sivu="))
        {
        // Jos tekstiosuus löytyy, se poistetaan rivistä. Jäljelle jää      //
        // pelkästään asetuksen numeroarvo.                                 //
            config_rivi.erase(0,16);

        // Jäljelle jäänyt string -muotoinen numeroarvo lähetetään          //
        // stringstream -oliolle.                                           //
            ss << config_rivi;

        // Stringstream -olion sisältö palautetaan integer -tyyppiselle     //
        // muuttujalle, jolloin se muuttuu automaattisesti integeriksi.     //
            ss >> sivunpituus;
        }
        if(!config_rivi.find("5_laivat="))// ks. edellinen if-lause
        {
            config_rivi.erase(0,9);
            ss << config_rivi;
            ss >> laivat[5];

        }
        if(!config_rivi.find("4_laivat="))// ks. edellinen if-lause
        {
            config_rivi.erase(0,9);
            ss << config_rivi;
            ss >> laivat[4];
        }
        if(!config_rivi.find("3_laivat="))// ks. edellinen if-lause
        {
            config_rivi.erase(0,9);
            ss << config_rivi;
            ss >> laivat[3];
        }
        if(!config_rivi.find("2_laivat="))// ks. edellinen if-lause
        {
            config_rivi.erase(0,9);
            ss << config_rivi;
            ss >> laivat[2];
        }
        if(!config_rivi.find("simulointi_viive="))// ks. edellinen if-lause
        {
            config_rivi.erase(0,17);
            ss << config_rivi;
            ss >> s_viive;
        }
    // Silmukan päätteeksi stringstream -olio tyhjennetään.             //
        ss.str("");
        ss.clear();
    }

// Varmistetaan sitten, että asetustiedostosta poimitut arvot       //
// jäävät määriteltyjen rajojen sisäpuolelle.                       //

    if(sivunpituus > 9 )
        sivunpituus = MAX_SIVU;
    if(sivunpituus < 5 )
        sivunpituus = MIN_SIVU;
    for(int i=2; i<6; i++)
    {
        if(laivat[i] > 5 )
            laivat[i] = 5;
        if(laivat[i] < 0 )
            laivat[i] = 0;
    }
    if(s_viive < 0)
        s_viive = 0;

// Suljetaan lopuksi asetustiedosto.                                //

    config_i.close();

    return true; // Asetustiedoston käsittely onnistui
}
