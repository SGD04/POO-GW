/*
 * coordonnes.cpp
 *
 *  Created on: 23 nov. 2016
 *      Author: Sergio
 *
 *      @resume: Indication des coordonnées de l'ensemble des objets du programme
 */

#include "coordonnes.h"

/* Constructeur des coordonnées des objets*/
coordonnes::coordonnes(int x, int y, int lo, int la) {
			_x = x;
			_y = y;
			_longueur = lo;
			_largeur = la;
}

coordonnes::~coordonnes() {
	// TODO Auto-generated destructor stub
}

