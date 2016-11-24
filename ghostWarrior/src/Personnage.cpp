/*
 * Personnage.cpp
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
 * @version 1 / 24-11-2016
 * @Resume: Classe mère des personnages du jeu.
 * @toto NA
 * @bug NA
*/

#include "Personnage.h"

/* Constructeurs: */
Personnage::Personnage(int n, int x, int y, int lo, int la) : Coordonne(x,y,lo,la)
{
    _num = n;
    //Coordonne(x,y,lo,la);
}


/*Fonction d'affichage*/
void Personnage:: afficher()
{
    cout<<"num Perso"<<endl;
	cout<<"num : "<<_num<<" "<<_x<<" "<<_y<<" "<<_longueur<<" "<<_largeur<<endl;
}

/*Destructeur*/
Personnage::~Personnage()
{
    //pas d'elements dynamiques
}
