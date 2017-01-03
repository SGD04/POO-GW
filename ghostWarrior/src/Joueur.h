/*
 * joueur.h
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

#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "Bonus.h"
#include "Personnage.h"
#include "Evenement.hpp"



#ifndef JOUEUR_H
#define JOUEUR_H


class Joueur : public Personnage
{
    protected:
        string _nom;


    public:
        Joueur(int n, int x, int y, float lo, float la, Map c, const string & nom);
       // Joueur(int n, int x, int y, float lo, float la, Map c);
        virtual ~Joueur();

        void affiche() const;
        //void deplacer();
        int get_x();
        int get_y();
        void colision(bool,bool,bool);
        float get_longueur();
        float get_largeur();
        void changerAttribut(int);

};

#endif // JOUEUR_H

