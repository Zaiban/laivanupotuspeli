#ifndef TARKISTA_OSUMA_H
#define TARKISTA_OSUMA_H

/*--------------------------------------------------
 *
 * nimi: tarkista_osuma
 * toiminta: Täällä taphatuu suurin osa pelin aikaisista toiminnoista.
             Aliohjelma ottaa sisäänsä kaikki pelin vitaalit taulut ja tietueet.
             Aliohjelma lukee sille syötettyjä koordinaatteja.
             Aliohjelma sijoittaa ammunnat ammuntojen sijantitauluun, ja päivittää siinä sivussa tilastoja.

 * parametri(t): Käyttäjän tai simulaattorin tuottama koordinaattisyöte.

 * paluuarvo(t): Palauttaa true mikäli annetut koordinaatit aiheuttivat vahinkoa laivaan, tai false mikäli ne eivät.
 *
 *--------------------------------------------------*/
bool tarkista_osuma(const VektoriTaulu &, VektoriTaulu &, ID_Luettelo &, string, TilastoTiedot &, PeliTilanne &);

#endif
