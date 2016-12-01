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

#include <SFML/Graphics.hpp>
#include "Coordonne.h"
#include <iostream>

using namespace std;


class Personnage : public Coordonne
{
    protected:
        int _num;                        //Numero du personnage
        int _vie;                        //vie du personnage


    public:
        Personnage(int n, int x, int y, int lo, int la);
        Personnage(int x, int y, int lo, int la);
        virtual ~Personnage();

        void affiche(void) const;
         // player position
        sf::Vector2f pos = sf::Vector2f(320, 240);
        // player velocity (per frame)
        sf::Vector2f vel = sf::Vector2f(0, 0);
        // gravity (per frame)
        sf::Vector2f gravity = sf::Vector2f(0, .5f);

        // max fall velocity
        const float maxfall = 5;
        // run acceleration
        const float runacc = .15f;
        // max run velocity
        const float maxrun = 0.5f;
        // jump acceleration
        const float jumpacc = -1;
        // number of frames to accelerate in
        const unsigned char jumpframes = 13;
        // counts the number of frames where you can still accelerate
        unsigned char jumpcounter = 0;
        //is perso on ground
        bool onground = false;
        // inputs
        bool left = false;
        bool right = false;
        bool jump = false;

        //fonctions
        void Jump();
        void Initval();
        bool BOnground();
        void ColisionEnv();
        void UpdatePerso();
        
       //deplacer();
      // virtual void defendre();
        //attaque();
        //gravite();




};

#endif // PERSONNAGE_H
