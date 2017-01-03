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
#include <SFML/Graphics.hpp>            //library graphic
#include <windows.h>

/*#define WIDTH_SCREEN 480
#define LENGHT_SCREEN 640*/

#ifndef COORDONNE_H_
#define COORDONNE_H_

class Coordonne {

	/*Déclaration des attributs*/
	protected:
		float _longueur;					/*Taille de l'objet*/
		float _largeur;
        /*Taille de l'ecran (full screen sans la bare windows)*/
        int _hautEcran ;
        int _longEcran;



	public:
	     sf::Vector2f pos /*= sf::Vector2f(320, 240)*/;

		/* Constructeur des coordonnées des objets*/
		Coordonne(int x, int y, int lo, int la);

		virtual void affiche() const; 	        //Fonction abstraite

		 /*Déclarations destructeur*/
		 	virtual ~Coordonne();

};

#endif /* COORDONNE_H_ */
