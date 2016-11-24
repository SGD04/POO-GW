/*
 * Personnage.h
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

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Coordonne.h"
#include <iostream>
using namespace std;


class Personnage : public Coordonne
{
    protected:
        int _num;                        //Numero du personnage


    public:
        Personnage(int n, int x, int y, int lo, int la);
        virtual ~Personnage();

        void afficher();

       /* deplacer();
        defendre();
        attaque();
        gravite();*/




};

#endif // PERSONNAGE_H
