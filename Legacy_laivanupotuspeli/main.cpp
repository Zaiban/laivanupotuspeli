//Tampereen Ammattikorkeakoulu; Ohjelmointikielet, jatko; 2014
//Laivanupotuspeli
//Esa Parkkila, 12I200C
//esa.parkkila@eng.tamk.fi
//Työn tekemiseen kulunut aika: kymmeniä tunteja
//Lisäominaisuudet: 1a / 1b / 2b / 2c / 2d / 2e
/*

Lähdin tekemään peliä täysin ilman minkäänalista pseudokoodia. Tein koodin kokonaisuudessaan yksin.
Lisäksi lisäsin lähes kaikki kommentit vasta jälkikäteen, kun ohjelma oli jo lähes valmis. Tämän vuoksi koodi saattaa olla paikoin sekavahkoa.

Pyrin koodissa siihen, että kaikki parametrit välitetään aliohjelmille viittauksina.

Lähes kaikki aliohjelmat palauttavat tietoa näiden viittausten kautta. Aliohjelmat ovat joko tyypittömiä,
tai niiden tyyppi on bool, jolloin ne palauttavat yleensä onnistuessaan truen tai muuten falsen.

Nämä asiat asiat pätevät siis suurimpaan osaan koodista, toki muutamia poikkeuksiakin löytyy.

Kun lähdin tekemään ohjelmaa, tavoitteenani oli toteuttaa kaikki lisätoiminnot. Kuitenkin jossain vaiheessa laiskuus vei voiton,
ja siksipä pelin tallennus- ja lataustoiminnot jäivät kokonaan pois. Muut toiminnot sain mielestäni toteutettua kohtuullisella työllä.

Lopputulokseen olen itse varsin tyytyväinen. Toki näin jälkikäteen on hyvä viisastella, ja jos lähtisin tekemään urakkaa alusta
niin esimerkiksi pseudokoodia en jättäisi tekemättä, ja kommenttejakin varmasti kirjoittaisin koodauksen aikana enemmän.

Pelin tekemiseen kulunutta aikaa on mahdoton tarkasti arvoida, puhutaan kuitenkin vähintäänkin kymmenistä tunneista ja
mahdollisesti jopa sadoista. Koodia kirjoittelin silloin kuin siltä tuntui, pitkin kevättä, enkä mitannut kulunutta aikaa millään tavalla.

Peli on koodattu ja testattu CodeBlocksin avulla. GNU GCC -kääntäjä ei anna käännettäessä virheitä eikä varoituksia.

Peli on testattu myös Visual Studio 2010 kääntäjällä, joka antaa käännettäessä 1 varoituksen (warning).
Tämä varoitus johtuu time_t tyypin (jollaisen funktio time(0) palauttaa) käytöstä satunnaislukugeneraattorin siemenlukuna.
Varoitus ei kuitenkaan käsittääkseni vaikuta ohjelman toimintaan millään tavalla negatiivisesti, joten annoin sen olla sellaisenaan.

-------------
Kaikki vitaali pelidata (esim: taulut jotka sisältävät laivojen sijainnit ja ammuntojen sijainnit, tilastot, ym)
on tallennettuna pääohjelman muuttujissa. Näitä muuttujia välitetään eteenpäin aliohjelmille viittausten avulla.
Aliohjelmat käsittelvät näitä muuttujia suoraan tarpeensa mukaan. Seuraavaksi lyhyt kuvaus tärkeimmistä muuttujista.

VektoriTaulu M_ammuntojen_sijainnit;

    Sisältää suoritettujen ammuntojen sijainnit vektorityyppisessä taulukossa. Tätä muuttujaa tulostetaan näytölle jatkuvasti pelin aikana.
    Muuttujaa luetaan useissa aliohjelmissa, mutta sitä muokataan ainoastaan aliohjelmissa kehys sekä tarkista_osuma.

VektoriTaulu M_laivojen_sijainnit;

    Sisältää laivojen sijainnit pelialueella vektorityyppisessä taulukossa. Tätä muuttujaa tulostetaan näytölle ainoastaan vakoilukomennon jälkeen.
    Muuttujaa luetaaan useissa aliohjelmissa, mutta sitä muokataan ainoastaan aliohjelmissa kehys sekä aseta_laiva.

TilastoTiedot M_tilasto;

    Sisältää kaiken tilastodatan. Tätä muuttujaa tulostetaan näytölle pelin päättyessä tai päävalikossa kun pelaaja antaa komennoksi 7.
    Muuttujaa luetaan muutamissa aliohjelmissa, mutta erityisesti aliohjelmassa tulosta_tilastot joka tulostaa sen koko sisällön näkyville.
    Muuttujaa muokataan ainoastaan alioihjelmassa tarkista_osuma, minkä tehtävänä on osumien sijoittamisen lisäksi niiden tilastointi.

ID_Luettelo M_luettelo;

    Sisältää kaikkien laivojen yksilöidyt tiedot, joista tarkemmin aliohjelman alusta_laiva_id kommenteissa.
    Muuttujaa luetaan ja muokataan useissa aliohjelmissa, jotka käsittelevät laivojen tietoja.

Pelitilanne M_tilanne;

    Sisältää muutamia satunnaisia, mutta tärkeitä, tietoja, kuten tiedon siitä onko laivat sijoiteltu taululle tai onko peli jo käynnistetty.

-------------
Ohjelmaan käynnistyessä ohjelma lukee ensin asetustiedoston laiva.txt joka sijaitsee ohjelman ajokansiossa. Mikäli
tiedostoa ei ole vielä olemassa, se luodaan ensin.
  Laiva.txt tiedoston avulla pelaaja voi säätää 3 eri asiaa:
pelialueen kokoa, laivojen määrää sekä ammunna simulointimoodin viivettä.

Seuraavaksi ohjelmassa mennään päävalikkoon. Päävalikkoa toistetaan niin kauan, kunnes pelaaja sulkee
ohjelman kirjoittamalla komentoriville L -kirjaimen.

Mikäli pelaaja kirjoittaa päävalikossa jonkin muista komennoista komentoriville, tapahtuu seuraavaa:

-------------
Komentorivi: 1

Mikäli ammuntamoodi (manuaalinen tai simulointi) on jo käynnistetty, kysytään pelaajalta varmistus haluaako
hän varmasti sijoitella laivat uudelleen, jolloin edellinen pelitilanne menetetään ja uusi peli alkaa.

Pelaajan vaastatessa kyllä, siirrytään eteenpäin. Muuten palataan päävalikkoon.

Tämän jälkeen ohjelma kysyy pelaajalta, minne hän haluaa sijoitella laivat.
Pelaaja voi halutessaan poistua sijoittelumoodista kirjoittamalla komentoriville "p" ohjelman kysyessä koordinaatteja.
Kirjoittamalla komentoriville vakoilukomennon "/@" pelaaja voi milloin hyvänsä vakoilla sijoiteltujen laivojen sijaintia.

Kun kaikki laivat on sijoiteltu, palataan takaisin päävalikkoon.

-------------
Komentorivi: 2

Mikäli laivoja ei ole vielä sijoiteltu, ohjelma tulostaa virheilmoituksen.
Muuten siirrytään manuaaliseen ammuntamoodiin.

Ohjelma kysyy pelaajalta ammunnan koordinaatteja. Mikäli koordinaatit ovat jollain tapaa virheelliset, ohjelma tulostaa virheilmoituksen.
Pelaaja voi halutessaan poistua ammuntamoodista kirjoittamalla komentoriville "p" ohjelman kysyessä koordinaatteja.
Kirjoittamalla komentoriville vakoilukomennon "/@" pelaaja voi milloin hyvänsä vakoilla laivojen sijaintia.

Kun kaikki laivat on tuhottu, ohjelma tulostaa ilmoituksen onnistuneesta suorituksesta sekä erinäisiä tilastotietoja pelistä.

Tämän jälkeen palataan päävalikkoon.

-------------
Komentorivi: 3

Mikäli ammuntamoodi (manuaalinen tai simulointi) on jo käynnistetty, kysytään pelaajalta varmistus haluaako
hän varmasti sijoitella laivat uudelleen, jolloin edellinen pelitilanne menetetään ja uusi peli alkaa.

Pelaajan vaastatessa kyllä, siirrytään eteenpäin. Muuten palataan päävalikkoon.

Ohjelma arpoo laivojen sijainnit pelikentälle, ja tulostaa sen merkiksi viestin käyttäjälle.

Tämän jälkeen palataan päävalikkoon.

-------------
Komentorivi: 6

Mikäli laivoja ei ole vielä sijoiteltu, ohjelma tulostaa virheilmoituksen.
Muuten siirrytään simuloituun ampumismoodiin.

Simulaatiossa tietokone suorittaa ammunnat pelaajan puolesta. Vakioasetuksillla pelaajan on painettava näppäintä
edetäkseen ammunnassa. Halutessaan pelaaja voi myös antaa asetustiedostossa laiva.txt haluamansa viiveen,
jolloin simulaatio etenee viiveen määräämää nopeutta.

Kun kaikki laivat on tuhottu, ohjelma tulostaa ilmoituksen onnistuneesta suorituksesta sekä erinäisiä tilastotietoja pelistä.

Tämän jälkeen palataan päävalikkoon.

-------------
Komentorivi: 7

Ohjelma tulostaa nykyisen pelitilanteen tilastot.

Tämän jälkeen palataan päävalikkoon.

-------------
Komentorivi: H

Ohjelma tulostaa lyhyehkön peliohjeen.

Tämän jälkeen palataan päävalikkoon.

*/


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>


#include "vakiot.h"
#include "rakenteet.h"

#include "prototyypit/setup.h"
#include "prototyypit/paavalikko.h"
#include "prototyypit/kehys.h"
#include "prototyypit/sijainti_kasin.h"
#include "prototyypit/numerot_sanoiksi.h"
#include "prototyypit/aseta_laiva.h"
#include "prototyypit/vakoilu.h"
#include "prototyypit/uusi_aloitus.h"
#include "prototyypit/sijainti_arpomalla.h"
#include "prototyypit/alusta_laiva_id.h"
#include "prototyypit/ammunta.h"
#include "prototyypit/tarkista_osuma.h"
#include "prototyypit/simuloi_ampuminen.h"
#include "prototyypit/tulosta_peliohje.h"
#include "prototyypit/tulosta_tilastot.h"
#include "prototyypit/nimet.h"
#include "prototyypit/debug.h"


using namespace std;

int main()
{
// Määritellään päämuuttujat, joita                                 //
// käsitellään aliohjelmissa.                                       //
    VektoriTaulu M_ammuntojen_sijainnit;
    VektoriTaulu M_laivojen_sijainnit;
    TilastoTiedot M_tilasto;
    ID_Luettelo M_luettelo;
    PeliTilanne M_tilanne;

// Määritellään muuttujat, joihin luetaan laiva.txt                 //
// -asetustiedoston sisältö.
    int conf_sivunpituus;
    int conf_laivojen_lkm[SUURIN_LAIVA+1];
    int conf_simulointi_viive;

// Alustetaan & luetaan asetustiedosto laiva.txt. Mikäli tiedostoa  //
// ei löydy ja sen luominen ei syystä tai toisesta onnistu,         //
// näytetään virheilmoitus ja poistutaan ohjelmasta.                //

    if(setup(conf_sivunpituus, conf_laivojen_lkm, conf_simulointi_viive)  == false)
    {
        cerr << "Tiedostoa ei kyetty luomaan" << endl;
        cerr << "Ohjelman ajokansio on mahdollisesti kirjoitussuojattu" << endl;
        cerr << "Ohjelman suoritus lopetetaan." << endl;
        system("PAUSE");

        return 0; // Ohjelmasta poistutaan
    }


// Alustetaan tyhjä vakiotaulu. Tätä taulua käytetään pohjana       //
// muille tauluille.                                                //

    const VektoriTaulu TYHJATAULU(conf_sivunpituus + 2*KEHYKSENPAKSUUS, vector<char>(conf_sivunpituus + 2*KEHYKSENPAKSUUS, ' '));

// Luodaan satunnaislukugeneraattorin siemenluku                    //
// tietokoneen ajan avulla                                          //
    srand(time(0));



// Ajetaan funktio uusi_aloitus kerran, joka asettaa taulut         //
// ja muuttujat "alkutilaan".                                       //

    M_tilanne.ammunta_kaynnissa = false;
    uusi_aloitus(TYHJATAULU, M_laivojen_sijainnit, M_ammuntojen_sijainnit, M_tilanne, M_tilasto, M_luettelo, conf_laivojen_lkm);

// Mennään päävalikkoon, jota toistetaan kunnes                     //
// ohjelmasta poistutaan.                                           //

    string valinta = "x";

    while(valinta != "L" && valinta != "l")
    {
        valinta = paavalikko();

//========================= Päävalikko : vakoilukomento ============//

        if(valinta == "/@")
        {
            valinta.clear();
            vakoilu(M_laivojen_sijainnit);
        }

//========================= Päävalikko : 1 =========================//

        if(valinta == "1" && uusi_aloitus(TYHJATAULU, M_laivojen_sijainnit, M_ammuntojen_sijainnit, M_tilanne, M_tilasto, M_luettelo, conf_laivojen_lkm) == true)
        {

            if(sijainti_kasin(M_laivojen_sijainnit, conf_laivojen_lkm, M_luettelo) == true)

                M_tilanne.laivat_sijoiteltu = true;

        }

//========================= Päävalikko : 2 =========================//

        if(valinta == "2" && M_tilanne.laivat_sijoiteltu == true)
        {

            if(ammunta(M_laivojen_sijainnit, M_ammuntojen_sijainnit, M_luettelo, M_tilanne, M_tilasto) == true)
            {
                M_tilanne.ammunta_kaynnissa=0;
                cout << "\nAmmunta suoritettiin onnistuneesti loppuun!" << endl;
                tulosta_tilastot(M_tilasto);
            }
        }
        else if(valinta == "2" && M_tilanne.laivat_sijoiteltu == false)
        {
            cout << "Virhe: laivoja ei ole sijoiteltu!" << endl;
        }

//========================= Päävalikko : 3 =========================//

        if(valinta == "3" && uusi_aloitus(TYHJATAULU, M_laivojen_sijainnit, M_ammuntojen_sijainnit, M_tilanne, M_tilasto, M_luettelo, conf_laivojen_lkm) == true)
        {
            sijainti_arpomalla(M_laivojen_sijainnit, conf_laivojen_lkm, M_luettelo); //Arpoo laivat satunnaisesti ja sijoittaa ne laivojen sijaintitauluun.
            cout << "..sijainnit arvottu!" << endl;
            M_tilanne.laivat_sijoiteltu = true;
        }

//========================= Päävalikko : 4 =========================//

        if(valinta == "4")
        {
            cout << "Tama toiminto ei ole kaytossa" << endl;
        }

//========================= Päävalikko : 5 =========================//

        if(valinta == "5")
        {
            cout << "Tama toiminto ei ole kaytossa" << endl;
        }

//========================= Päävalikko : 6 =========================//

        if(valinta == "6" && M_tilanne.laivat_sijoiteltu == true)
        {
            if( simuloi_ampuminen(M_laivojen_sijainnit, M_ammuntojen_sijainnit, M_luettelo, M_tilasto, M_tilanne, conf_simulointi_viive) == true )
            {
                M_tilanne.ammunta_kaynnissa=0;
                cout << "\nAmmunta suoritettiin onnistuneesti loppuun!" << endl;
                tulosta_tilastot(M_tilasto);
            }
        }
        else if(valinta == "6" && M_tilanne.laivat_sijoiteltu == false)
                {
            cout << "Virhe: laivoja ei ole sijoiteltu!" << endl;
        }

//========================= Päävalikko : 7 =========================//

        if(valinta == "7")
        {
            tulosta_tilastot(M_tilasto);
        }

//========================= Päävalikko : H =========================//

        if(valinta == "H")
        {
            tulosta_peliohje();
        }

//===================Debug valikko, vain testausta varten============//
    /*
        if(valinta == "D")
        {
            debug(M_ammuntojen_sijainnit, M_laivojen_sijainnit, conf_laivojen_lkm, SUURIN_LAIVA+1, M_luettelo, M_tilanne);
        }
    */

    }

// Tänne päädytään kun päävalikossa on valittu käsky "lopeta";      //
// ohjelman ajo päättyy tähän.                                      //

    cout << endl;
    system("PAUSE");
    return 0;
}
