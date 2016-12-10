#ifndef UUSI_ALOITUS_H
#define UUSI_ALOITUS_H

/*--------------------------------------------------
 *
 * nimi: uusi_aloitus
 * toiminta: Kysyy pelaajalta, haluaako hän aloittaa uuden pelin. Jos pelaaja vastaa kyllä, aliohjelma pyyhkii kaikki entisen pelin tiedot ja alustaa ne aloitusarvoille.
 * parametri(t): Kaikki muuttujat jotka sisältävät pelin aikana muokattavaa dataa.
 * paluuarvo(t): Palauttaa true mikäli uusi peli aloitettiin, muuten false.
 *
 *--------------------------------------------------*/
bool uusi_aloitus(const VektoriTaulu &, VektoriTaulu &, VektoriTaulu &, PeliTilanne &, TilastoTiedot &, ID_Luettelo &, const int []);

#endif
