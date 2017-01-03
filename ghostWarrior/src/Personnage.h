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
 * @version 2 / 6-12-2016
 * @Resume: Classe mère des personnages du jeu.
 * @toto NA
 * @bug NA
*/

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <SFML/Graphics.hpp>
#include "Coordonne.h"
#include "Map.h"
#include <iostream>
#include <time.h>
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
*/
#include <Windows.h>                //pour creation des threds
#include <tchar.h>
#include <process.h>
#include <stdio.h>
//#include <strsafe.h>

using namespace std;


class Personnage : public Coordonne
{
    protected:
        int _num;                        //Numero du personnage
        int _vie;                        //vie du personnage
        Map _carte;                      // Carte du jeu
        clock_t _lastDefense;              //derniere fois que le personnage a utilisé la defense
        static unsigned int __stdcall faireDef(void* data);



    public:
        Personnage(int n, int x, int y, float lo, float la, Map c);
        //Personnage(int x, int y, int lo, int la, Map c);
        virtual ~Personnage();

        void affiche(void) const;
         // player position

        // player velocity (per frame)
        sf::Vector2f vel = sf::Vector2f(0, 0);
        // gravity (per frame)
        sf::Vector2f gravity = sf::Vector2f(0, .5f);

        // max fall velocity
        const float maxfall = 5;
        // run acceleration
        const float runacc = .15f;
        // max run velocity
        const float maxrun = 0.3f;
        // jump acceleration
        const float jumpacc = -1;
        // number of frames to accelerate in
        const unsigned int jumpframes = 15;
        // counts the number of frames where you can still accelerate
        unsigned int jumpcounter = 0;
        //is perso on ground
        bool onground = false;



        //fonctions
        void Jump(bool jump);
        void Initval();
        bool BOnground();
        void ColisionEnv();
        void UpdatePerso(bool left, bool right);
        void defense(bool def);

       // virtual void colision();

       //deplacer();
      // virtual void defendre();
        //attaque();





};

#endif // PERSONNAGE_H

