/*
 * Coordonne.h
 *
  *  Created on: 23 nov. 2016
 *      Author: Sergio Galan-Delea & Justine Denis
 *      Version: 1
 *
 *      @resume: Indications des coordonnées de l'ensemble des objets du programme.
 */
#include <iostream>
#include <string.h>
using namespace std;


#ifndef COORDONNE_H_
#define COORDONNE_H_

class Coordonne {

	/*Déclaration des attributs*/
	protected:
		int _x;							/*Point de coordonnée (x,y)*/
		int _y;
		int _longueur;					/*Taille de l'objet*/
		int _largeur;

	public:
		/* Constructeur des coordonnées des objets*/
		Coordonne(int x, int y, int lo, int la);

		 virtual void afficher_nvx(ostream & flot) const = 0; 	//Fonction abstraite

		 /*Déclarations destructeur*/
		 	virtual ~Coordonne();

};

#endif /* COORDONNE_H_ */
