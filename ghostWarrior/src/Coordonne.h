/*
 * Coordonne.h
 *
 * Polytech Marseille
 * Case 925 -163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut �tre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author DENIS Justine <justine.denis@etu.univ-amu.fr>
 * @author GALAN-DELEA Sergio <sergio.galan-delea@etu.univ-amu.fr>
 *
 * @version 1 / 23-11-2016
 * @Resume: Indications des coordonn�es de l'ensemble des objets du programme.
 * @toto NA
 * @bug NA
*/
#include <iostream>
#include <string.h>
using namespace std;


#ifndef COORDONNE_H_
#define COORDONNE_H_

class Coordonne {

	/*D�claration des attributs*/
	protected:
		int _x;							/*Point de coordonn�e (x,y)*/
		int _y;
		int _longueur;					/*Taille de l'objet*/
		int _largeur;

	public:
		/* Constructeur des coordonn�es des objets*/
		Coordonne(int x, int y, int lo, int la);

		/*virtual*/ void affichage(void) const; /*= 0;*/ 	//Fonction abstraite

		 /*D�clarations destructeur*/
		 	virtual ~Coordonne();

};

#endif /* COORDONNE_H_ */
