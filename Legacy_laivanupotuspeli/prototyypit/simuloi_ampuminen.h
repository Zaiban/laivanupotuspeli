#ifndef SIMULOI_AMPUMINEN_H
#define SIMULOI_AMPUMINEN_H

/*--------------------------------------------------
 *
 * nimi: simuloi_ampuminen
 * toiminta: Simuloi ampumistilanteen. Arpoo satunnaisia koordinaatteja ja l‰hett‰‰ ne aliohjelmalle tarkista_osuma
 * parametri(t):
 * paluuarvo(t): Palauttaa true kun simulaatio on viety loppuun saakka.
 *
 *--------------------------------------------------*/
bool simuloi_ampuminen(const VektoriTaulu &, VektoriTaulu &, ID_Luettelo &, TilastoTiedot &, PeliTilanne &, const int &);

#endif
