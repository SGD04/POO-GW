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
 * @version 2 / 30-11-2016
 * @Resume: Comprend l'architecture de l'environnement du jeu (background et plateforme)
 * @toto : Plus tard: faire la map avec les textures de SFML
 * @bug NA
*/

#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <windows.h>
using namespace std;


/*Taille de l'écran de l'ordinateur et donc de la carte*/
#define NB_CASE_LAR  20
#define NB_CASE_LONG 20




class Map
{

    public:


        std::vector< std::vector<int> > _grille;
        int _background;                                        //Textures de la map
        int _plateforme;
        float _largeurCase;
        float _longueurCase;
        int  _hautEcran ;
        int  _longEcran ;






    public:
        Map();
        Map(const Map &);
        virtual ~Map();

        void afficher() ;
        int infos_case (int i, int j);
        float getLongeurCase();
        float getLargeurCase();

};

#endif // MAP_H
