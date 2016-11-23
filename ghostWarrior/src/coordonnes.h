/*
 * coordonnes.h
 *
 *  Created on: 23 nov. 2016
 *      Author: Sergio
 *
 *      @resume: Indication des coordonnées de l'ensemble des objets du programme
 */

#ifndef COORDONNES_H_
#define COORDONNES_H_

class coordonnes {
public:

	/*Déclaration des attributs*/
	private int _x;								//Point de coordonnée (x,y)
	private int _y;
	private int _longueur;						//Taille de l'objet
	private int _largeur;

	/* Constructeur des coordonnées des objets*/
	coordonnes(int x, int y, int lo, int la);


	/*Déclarations fonctions*/
	virtual ~coordonnes();
};

#endif /* COORDONNES_H_ */
