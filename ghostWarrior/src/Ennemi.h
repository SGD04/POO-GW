/*
 * Ennemi.h
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

#include <iostream>
#include <string.h>
using namespace std;
#include "Personnage.h"

#ifndef ENNEMI_H
#define ENNEMI_H


class Ennemi : public Personnage
{
    public:
        Ennemi(int n, int x, int y, int lo, int la);
        virtual ~Ennemi();
        void affiche() const;

};

#endif // ENNEMI_H
