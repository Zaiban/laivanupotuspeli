#ifndef ASETA_LAIVA_H
#define ASETA_LAIVA_H

/*--------------------------------------------------
 *
 * nimi: aseta_laiva
 * toiminta: Ottaa sis‰‰nsÅEtaulun johon laiva on tarkoitus sijoittaa, ja laivan sijoitustiedot. Laiva asetetaan tauluun, mik‰li se mahtuu paikoilleen, annettujen koordinaattien mukaisesti.
 * parametri(t): laivojen sijaintitaulukko, sijoitettavan laivan tiedot
 * paluuarvo(t): Palauttaa true jos laivan sijoitus onnistui. Palauttaa false jos laiva ei mahtunut annettuun kohtaan.
 *
 *--------------------------------------------------*/
bool aseta_laiva(VektoriTaulu &,  LaivanRunko &, ID_Luettelo &);

#endif
