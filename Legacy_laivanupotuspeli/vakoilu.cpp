//                                                                  //
//                      Vakoilu
//                                                                  //

#include "rakenteet.h"

void vakoilu(const VektoriTaulu & taulu)
{
    cout << "\nLaivat sijaitsevat seuraavissa paikoissa:\n" << endl;

    for(unsigned i=0; i<taulu.size(); i++)
    {
        for(unsigned y=0; y<taulu.size(); y++)
        {
            cout << taulu[i][y] << " ";

        }
        cout << endl;
    }
}
