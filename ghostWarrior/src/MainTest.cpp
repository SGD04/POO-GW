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


#include "MainTest.h"
#include <iostream>
using namespace std;



int main(void)
{
	Coordonne coord = new Coordonne(0,0,5,10);
	coord.affichage();

}
