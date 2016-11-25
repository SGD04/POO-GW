/*
 * Ennemi.cpp
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
 * @version 1 / 25-11-2016
 * @Resume: Classe des personnages géré par le programme
 * @toto NA
 * @bug NA
*/

#include "Ennemi.h"

/* Constructeurs des personnages:
* @arg: n numero du personnage dans le jeu
* @arg: x abcisse des objets
* @arg: y ordonnee des objets
* @arg: lo la longueur de l'objet graphique
* @arg: lo la longueur de l'objet graphique
*/
Ennemi::Ennemi(int n, int x, int y, int lo, int la) :  Personnage(n,x,y,lo,la)
{
    //ctor
}


void Ennemi::affiche() const
{
    cout<<"Ennemi"<<endl;
	cout<<"num : "<<_num<<" "<<_x<<" "<<_y<<" "<<_longueur<<" "<<_largeur<<endl;
}

Ennemi::~Ennemi()
{
    //dtor
}
