#ifndef RAKENTEET_H
#define RAKENTEET_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector< vector<char> > VektoriTaulu;
typedef vector< string > ID_Luettelo;

struct LaivanRunko
{
    int pituus;
    string koordinaatit;
    string suunta;
};


struct TilastoTiedot
{
    int i_ammuntoja_yht;
    int ii_hutit_alussa;
    vector<int> iii_vi_monesko_upotti;
    vector<int> iii_vi_laivankoko;
    vector<int> iii_vi_ekalaukaus;
    int vii_pisin_hutisarja;
};

struct PeliTilanne
{
    int elamia_jaljella;
    bool ammunta_kaynnissa;
    bool laivat_sijoiteltu;
    int ohilaukaus_sarja;
};


#endif
