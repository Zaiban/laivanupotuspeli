#ifndef AMMUNTA_H
#define AMMUNTA_H

/*--------------------------------------------------
 *
 * nimi: ammunta
 * toiminta: Ammuntatilan tulostukset ja syötteenkyselyt pelaajalta. Lähettää käyttäjän syötteen eteenpäin funktiolle tarkitsa_osuma.
 * parametri(t): Pelin päämuuttujat (taulut ja tietueet, jotka sisältävät pelin oleelliset tiedot)
 * paluuarvo(t): Palauttaa true mikäli ammunta suoritettiin loppuun asti, tai muuten false.
 *
 *--------------------------------------------------*/
bool ammunta(const VektoriTaulu &, VektoriTaulu &,ID_Luettelo &, PeliTilanne &, TilastoTiedot &);

#endif
