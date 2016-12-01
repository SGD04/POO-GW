/*
 * MainTest.cpp
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
 * @Resume: Fichier main permettant de tester les classes
 * @toto NA
 * @bug NA
*/


#include "Coordonne.h"
#include "Personnage.h"
#include "Ennemi.h"
#include "Joueur.h"
#include "Map.h"

#include <iostream>
using namespace std;



int main()
{
    Map carte;
    carte.afficher();


	Joueur j("test",99999,6,6,2,12);
	//je.affiche();

	Ennemi en(222222,9,4,2,10,carte);
	en.affiche();

	en.deplacer(j);
	en.affiche();








	return 0;
}
