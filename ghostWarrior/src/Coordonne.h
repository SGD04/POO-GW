/*
 * Coordonne.h
 *
 * Polytech Marseille
 * Case 925 -163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut être
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author DENIS Justine <justine.denis@etu.univ-amu.fr>
 * @author GALAN-DELEA Sergio <sergio.galan-delea@etu.univ-amu.fr>
 *
 * @version 1 / 23-11-2016
 * @Resume: Indications des coordonnées de l'ensemble des objets du programme.
 * @toto NA
 * @bug NA
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

		virtual void affiche() const; 	        //Fonction abstraite

		 /*Déclarations destructeur*/
		 	virtual ~Coordonne();

};

#endif /* COORDONNE_H_ */
