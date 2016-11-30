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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Personnage.h"
#include "Joueur.h"

#ifndef ENNEMI_H
#define ENNEMI_H


class Ennemi : public Personnage
{
    //protected Map _grille;

    public:
        Ennemi(int n, int x, int y, int lo, int la);
        virtual ~Ennemi();

        //fonctions:
        void affiche() const;
        void attaque();
        void defendre();
        void combattre(Joueur j);
        void deplacer(Joueur j);
        bool obstace(int vect_x, int vect_y);

};

#endif // ENNEMI_H
