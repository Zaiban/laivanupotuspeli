#ifndef UUSI_ALOITUS_H
#define UUSI_ALOITUS_H

/*--------------------------------------------------
 *
 * nimi: uusi_aloitus
 * toiminta: Kysyy pelaajalta, haluaako h�n aloittaa uuden pelin. Jos pelaaja vastaa kyll�, aliohjelma pyyhkii kaikki entisen pelin tiedot ja alustaa ne aloitusarvoille.
 * parametri(t): Kaikki muuttujat jotka sis�lt�v�t pelin aikana muokattavaa dataa.
 * paluuarvo(t): Palauttaa true mik�li uusi peli aloitettiin, muuten false.
 *
 *--------------------------------------------------*/
bool uusi_aloitus(const VektoriTaulu &, VektoriTaulu &, VektoriTaulu &, PeliTilanne &, TilastoTiedot &, ID_Luettelo &, const int []);

#endif
