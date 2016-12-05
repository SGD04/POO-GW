/*
 * Personnage.cpp
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

#include "Personnage.h"

/* Constructeurs des personnages:
* @arg: n numero du personnage dans le jeu
* @arg: x abcisse des objets
* @arg: y ordonnee des objets
* @arg: lo la longueur de l'objet graphique
* @arg: lo la longueur de l'objet graphique
*/
Personnage::Personnage(int n, int x, int y, int lo, int la) : Coordonne(x,y,lo,la)
{
    _num = n;
    _vie = 100;
}

/*Fonction d'affichage*/
void Personnage:: affiche(void) const
{
    cout<<"num Perso"<<endl;
	cout<<"num : "<<_num<<" "<<_x<<" "<<_y<<" "<<_longueur<<" "<<_largeur<<endl;
}

void Personnage::Initval(){
    // player position
    sf::Vector2f pos(320, 240);

    // player velocity (per frame)
    sf::Vector2f vel(0, 0);

    // gravity (per frame)
    sf::Vector2f gravity(0, .5f);

}


void Personnage::ColisionEnv(){
    // check for collision with the ground
        if (pos.y > 480) {
            vel.y = 0;
            pos.y = 480;
        }
        // check for collision with the left border
        if (pos.x < 16) {
            vel.x = 0;
            pos.x = 16;
        }
        else if (pos.x > 624) {
            vel.x = 0;
            pos.x = 624;
        }
}

void Personnage::Jump(){
// jumping
        if (jump) {
            if(onground){ // on the ground
                vel.y += jumpacc * 2;
                jumpcounter = jumpframes;
            }
            else if (jumpcounter > 0) { // first few frames in the air
                vel.y += jumpacc;
                jumpcounter--;
            }
        }
        else { // jump key released, stop acceleration
            jumpcounter = 0;
        }
}

void Personnage::UpdatePerso(){
     // first, apply velocities
        pos += vel;

        // determine whether the player is on the ground
        onground = pos.y >= 480;
        // now update the velocity by...
        // ...updating gravity
        vel += gravity;

        // ...capping gravity
        if (vel.y > maxfall)
                vel.y = maxfall;
        if (left & !right) { // running to the left
            vel.x -= runacc;
        }
        if (!left & right) { // running to the right
            vel.x += runacc;
        }
        if(!left & !right) { // not running anymore; slowing down each frame
            vel.x *= 0.7;
        }
        if(left & right) { // if left and right keyboard press -> stop
            vel.x *= 0.0;
        }
}

/*Destructeur*/
Personnage::~Personnage()
{
    //pas d'elements dynamiques
}

