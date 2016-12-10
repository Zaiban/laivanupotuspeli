#ifndef SIJAINTI_KASIN_H
#define SIJAINTI_KASIN_H

/*--------------------------------------------------
 *
 * nimi: sijainti_kasin
 * toiminta: Ottaa sis‰‰ns‰ tyhj‰n laivojen sijaintitaulun, kyselee k‰ytt‰j‰lt‰ laivojen sijainnit, ja antaa ne eteenp‰in aliohjelmalle aseta_laiva
 * parametri(t): Tyhj‰ laivojen sijaintitaulu, laivojen ID-luettelo
 * paluuarvo(t): Valmis laivojen sijaintitaulu & true, tai false jos laivojen sijoittelu keskeytettiin
 *
 *--------------------------------------------------*/
bool sijainti_kasin(VektoriTaulu &, int [], ID_Luettelo &);

#endif
