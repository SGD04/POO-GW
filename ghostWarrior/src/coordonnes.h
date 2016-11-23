/*
 * coordonnes.h
 *
 *  Created on: 23 nov. 2016
 *      Author: Sergio
 *
 *      @resume: Indication des coordonn�es de l'ensemble des objets du programme
 */

#ifndef COORDONNES_H_
#define COORDONNES_H_

class coordonnes {
public:

	/*D�claration des attributs*/
	private int _x;								//Point de coordonn�e (x,y)
	private int _y;
	private int _longueur;						//Taille de l'objet
	private int _largeur;

	/* Constructeur des coordonn�es des objets*/
	coordonnes(int x, int y, int lo, int la);


	/*D�clarations fonctions*/
	virtual ~coordonnes();
};

#endif /* COORDONNES_H_ */
