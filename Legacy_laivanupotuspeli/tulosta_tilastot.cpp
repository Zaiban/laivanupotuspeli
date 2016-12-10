//                                                                  //
//                      Tulosta tilastot
//                                                                  //

#include <cfloat>
#include "rakenteet.h"

#include "prototyypit/nimet.h"
#include "prototyypit/numerot_sanoiksi.h"

void tulosta_tilastot(const TilastoTiedot &tilastot)
{
    const int KOKO = tilastot.iii_vi_laivankoko.size() /2;
    double nimittaja, osoittaja;
    double dtemp = DBL_MAX;
    int itemp[2];

    //---------------I: Ammuntoja yhteensa----------------------------------------------
    cout << "\nPelissa on suoritettu yhteensa " << tilastot.i_ammuntoja_yht << " ammuntaa." << endl;

    //---------------II: Perakkaiset hutilaukaukset pelin alussa -----------------------
    cout << "Pelin alussa ammuttiin " << tilastot.ii_hutit_alussa << " hutilaukausta perajalkeen." << endl;

    //---------------III: Vaaditut ammunnat ensimmaisesta laukauksesta -----------------
    cout << endl;
    for(int i=0; i < KOKO; i++)
    {
        nimet(tilastot.iii_vi_laivankoko.at(i*2));
        cout << " jonka pituus oli ";
        cout << tilastot.iii_vi_laivankoko.at(1+(i*2));
        cout << " upottamiseen \ntarvittiin " << tilastot.iii_vi_monesko_upotti.at(1+(i*2))
             << " laukausta pelin alusta laskettuna." << endl;
    }
    cout << endl;
    //---------------IV: Laivojen uppoamisjarjestys ------------------------------------
    for(int i=0; i < KOKO; i++)
    {
        nimet(tilastot.iii_vi_laivankoko.at(i*2));
        cout << " jonka pituus oli ";
        cout << tilastot.iii_vi_laivankoko.at(1+(i*2));
        cout << " upposi ";
        numerot_sanoiksi(i+201);
        cout << "." << endl;
    }
    cout << endl;
    // --------------V: Vaaditut ammunnat ensimmaisesta osumasta ------------------------
    for(int i=0; i < KOKO; i++)
    {
        nimet(tilastot.iii_vi_laivankoko.at(i*2));
        cout << ":n jonka pituus oli ";
        cout << tilastot.iii_vi_laivankoko.at(1+(i*2));
        cout << " upottamiseen \ntarvittiin " << tilastot.iii_vi_monesko_upotti.at(1+(i*2)) - tilastot.iii_vi_ekalaukaus.at(1+(i*2))
             << " laukausta siihen ensimmaisena osuneesta laukauksesta laskettuna." << endl;
    }
    cout << endl;
    // ---------------VI: Tehokkain ampumisjakso -----------------------------------------
    for(int i=0; i < KOKO; i++)
    {
        osoittaja = tilastot.iii_vi_monesko_upotti.at(1+(i*2)) - tilastot.iii_vi_ekalaukaus.at(1+(i*2)) +1;
        nimittaja = tilastot.iii_vi_laivankoko.at(1+(i*2));
        if(osoittaja / nimittaja < dtemp)
        {
            dtemp = osoittaja / nimittaja;
            itemp[0] = tilastot.iii_vi_laivankoko.at(i*2);
            itemp[1] = tilastot.iii_vi_laivankoko.at(1+(i*2));
        }
    }
    if(dtemp < DBL_MAX)
    {
        cout << "Tehokkain ampumisjakso oli kohteeseen ";
                nimet(itemp[0]);
        cout << " \njonka pituus oli " << itemp[1]
             << "\nja suhdeluku " << dtemp << endl;
        cout << endl;
    }
    // ---------------VI: Pisin ohilaukausjakso  -----------------------------------------
    cout << "Pisin ohilaukausjakso oli " << tilastot.vii_pisin_hutisarja << " laukausta pitka." << endl;

}
