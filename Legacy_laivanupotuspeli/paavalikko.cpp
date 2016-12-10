//                                                                  //
//                      P‰‰valikko
//                                                                  //

#include <iostream>
#include <string>

using namespace std;

string paavalikko()
{
    string valinta;
    cout << endl;
    cout << "Laivanupotuspeli\n";
    cout << "================\n\n";
    cout << "Valinnat:\n";
    cout << "1) Syota laivat\n";
    cout << "2) Pelaa\n";
    cout << "3) Arvo laivojen sijainnit\n";
    cout << "4) Talleta pelitilanne (ei toimi)\n";
    cout << "5) Lataa pelitilanne (ei toimi)\n";
    cout << "6) Simuloi ampuminen\n";
    cout << "7) Nayta tilastot\n";
    cout << "H) Peliohje\n";
    cout << "L) Lopeta\n\n";
    cout << "Valintasi:";

    cin >> valinta;
    cout << endl;

    return valinta;
}
