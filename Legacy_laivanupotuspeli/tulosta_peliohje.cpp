//                                                                  //
//                      Tulosta peliohje
//                                                                  //

#include <cstdlib>
#include <iostream>
using namespace std;

void tulosta_peliohje()
{
    cout << "====================================================\n";
    cout << "===================Pelin ohjeet=====================\n";
    cout << "====================================================\n\n";
    cout << "Aseta aluksi laivat pelialueelle itse (toiminto 1)\n";
    cout << "tai arpomalla (toiminto 3)\n\n";
    cout << "Kaynnista sitten peli (toiminto 2) ja nauti.\n\n";
    cout << "Kun peli kysyy koordinaatteja, anna ne muodossa KN, missa:\n\n";
    cout << "K = kirjainkoordinaatti, yleensa valilla A-G\n";
    cout << "N = numerokoordinaatti, yleensa valilla 1-7\n\n";
    cout << "Mikali haluat xiitata, voit kurkistaa milta laivojen sijoittelu nayttaa\n";
    cout << "kirjoittamalla komennoksi '/@' ilman hipsukoita.\n\n";
    system("PAUSE");
}
