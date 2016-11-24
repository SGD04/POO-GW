/*
 * coordonnes.h
 *
 *  Created on: 23 nov. 2016
 *      Author: Sergio Galan-Delea & Justine Denis
 *      Version: 1
 *
 *      @resume: Indication des coordonn�es de l'ensemble des objets du programme
 */

#include <iostream>
#include <string.h>
using namespace std;


#ifndef COORDONNES_H_
#define COORDONNES_H_

class coordonnes {

	/*D�claration des attributs*/
protected:

	int _x;							/*Point de coordonn�e (x,y)*/
	int _y;
	int _longueur;					/*Taille de l'objet*/
	int _largeur;

public:
	/* Constructeur des coordonn�es des objets*/
	coordonnes(int x, int y, int lo, int la);

	 virtual void afficher_nvx(ostream & flot) const = 0; 	//Fonction abstraite


	/*D�clarations destructeur*/
	virtual ~coordonnes();
};

#endif /* COORDONNES_H_ */
