//                                                                  //
//                      Debug
//                                                                  //

#include <cstdlib>
#include "rakenteet.h"
#include "vakiot.h"

void debug(VektoriTaulu x, VektoriTaulu z, int laivat[], int laivatyypit, const ID_Luettelo &alkio, const PeliTilanne &tilanne)
{
    cout << "\n========Debug alkaa========\n";

    cout << "\nConfig tiedoston sisalto:" << endl;

    cout << "pelikentan_sivu = " << z.size()-2*KEHYKSENPAKSUUS << endl;
    for(int i=2; i<laivatyypit; i++)
        cout << i << "_laivat = " << laivat[i] << endl;



    cout << "\nAmmuntojen sijainnit taulun sisalto:" << endl;

    for(unsigned i=0; i<x.size(); i++)
    {
        for(unsigned y=0; y<x.size(); y++)
        {
            cout << x[i][y] << " ";

        }
        cout << endl;
    }

    cout << "\nLaivojen sijainnit taulun sisalto:" << endl;

    for(unsigned i=0; i<z.size(); i++)
    {
        for(unsigned y=0; y<z.size(); y++)
        {
            cout << z[i][y] << " ";

        }
        cout << endl;
    }

    cout << alkio.size() << "\n:n kokoisen laivaluettelon sisalto:" << endl;

    for(unsigned i=0; i < alkio.size(); i++)
    {
        cout << alkio[i] << endl;
    }

    cout << "\nPelitilanne muuttujan sisalto:" << endl;
    cout << "ammunta_kaynnissa = " << tilanne.ammunta_kaynnissa << endl;
    cout << "laivat_sijoiteltu = " << tilanne.laivat_sijoiteltu << endl;
    cout << "elamia_jaljella = " << tilanne.elamia_jaljella << endl;
    cout << "ohilaukaus_sarja = " << tilanne.ohilaukaus_sarja << endl;

    cout << "Satunnaisluku valilta 1-4:";
    int luku;
    luku = rand()%4+1;
    cout << rand << endl;

    cout << "\n========Debug paattyy========\n\n";
    system("PAUSE");
}
