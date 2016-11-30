/*
 * joueur.cpp
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
 * @Resume: Classe des joueurs: personnages jouables par les utilisateurs
 * @toto NA
 * @bug NA
*/
#include "Joueur.h"

/* Constructeurs des personnages:
* @arg: nom donné par le joueur pour la partie
* @arg: n numero du joueur dans le jeu n = {1,2} car il n'y a que deux joueurs
* @arg: x abcisse des objets
* @arg: y ordonnee des objets
* @arg: lo la longueur de l'objet graphique
* @arg: lo la longueur de l'objet graphique
*/
Joueur::Joueur(string nom, int n, int x, int y, int lo, int la) :  Personnage(n,x,y,lo,la)
{
    _nom = nom;
}

void Joueur::affiche() const
{
    cout<<"Joueur"<<endl;
	cout<<"num : "<<_num<<" "<<_x<<" "<<_y<<" "<<_longueur<<" "<<_largeur<<endl;
}

/*Accesseur à la varaible de position x du joueur*/
int Joueur::get_x()
{
    return(_x);
}

/*Accesseur à la varaible de position y du joueur*/
int Joueur::get_y()
{
    return(_y);
}


Joueur::~Joueur()
{
    //dtor
}
