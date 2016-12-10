#ifndef TARKISTA_OSUMA_H
#define TARKISTA_OSUMA_H

/*--------------------------------------------------
 *
 * nimi: tarkista_osuma
 * toiminta: T��ll� taphatuu suurin osa pelin aikaisista toiminnoista.
             Aliohjelma ottaa sis��ns� kaikki pelin vitaalit taulut ja tietueet.
             Aliohjelma lukee sille sy�tettyj� koordinaatteja.
             Aliohjelma sijoittaa ammunnat ammuntojen sijantitauluun, ja p�ivitt�� siin� sivussa tilastoja.

 * parametri(t): K�ytt�j�n tai simulaattorin tuottama koordinaattisy�te.

 * paluuarvo(t): Palauttaa true mik�li annetut koordinaatit aiheuttivat vahinkoa laivaan, tai false mik�li ne eiv�t.
 *
 *--------------------------------------------------*/
bool tarkista_osuma(const VektoriTaulu &, VektoriTaulu &, ID_Luettelo &, string, TilastoTiedot &, PeliTilanne &);

#endif
