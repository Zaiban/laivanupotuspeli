#ifndef AMMUNTA_H
#define AMMUNTA_H

/*--------------------------------------------------
 *
 * nimi: ammunta
 * toiminta: Ammuntatilan tulostukset ja sy�tteenkyselyt pelaajalta. L�hett�� k�ytt�j�n sy�tteen eteenp�in funktiolle tarkitsa_osuma.
 * parametri(t): Pelin p��muuttujat (taulut ja tietueet, jotka sis�lt�v�t pelin oleelliset tiedot)
 * paluuarvo(t): Palauttaa true mik�li ammunta suoritettiin loppuun asti, tai muuten false.
 *
 *--------------------------------------------------*/
bool ammunta(const VektoriTaulu &, VektoriTaulu &,ID_Luettelo &, PeliTilanne &, TilastoTiedot &);

#endif
