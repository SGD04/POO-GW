/*
 * Map.h
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
 * @version 1 / 30-11-2016
 * @Resume: Comprend l'architecture de l'environnement du jeu (background et plateforme)
 * @toto : Plus tard: faire la map avec les textures de SFML
 * @bug NA
*/

#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

/*Taille de l'écran de l'ordinateur et donc de la carte*/
#define LARGEUR_ECRAN  5
#define LONGUEUR_ECRAN  5


class Map
{
    protected:
        int _grille[LARGEUR_ECRAN][LONGUEUR_ECRAN];            //Tableau de la carte de jeu
        int _background;                                        //Textures de la map
        int _plateforme;




    public:
        Map();
        virtual ~Map();

        void afficher() const;


};

#endif // MAP_H
