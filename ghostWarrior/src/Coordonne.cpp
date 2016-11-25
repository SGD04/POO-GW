
/*
 * Coordonne.cpp
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

#include "Coordonne.h"

	/* @classe Coordonne
	* Constructeur des coordonnées des objets
	* @arg: x abcisse des objets
     	* @arg: y ordonnee des objets
     	* @arg: lo la longueur de l'objet graphique
     	* @arg: lo la longueur de l'objet graphique
     	*/
	Coordonne::Coordonne(int x, int y, int lo, int la) {
			_x = x;
			_y = y;
			_longueur = lo;
			_largeur = la;
	}

	/*@classe Coordonne:
	* Affichage des coordonnees (virtual)
	*/
	void Coordonne::affiche(void) const
	{
		    cout<<"Affichage des coord"<<endl;
		    cout<<_x<<" "<<_y<<" "<<_longueur<<" "<<_largeur<<" ";
		    cout<<endl;
	}



	Coordonne::~Coordonne(void)
	{
	    //rien alloué dynamiquement
	}
