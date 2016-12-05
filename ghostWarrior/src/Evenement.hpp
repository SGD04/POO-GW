/*
 * Evenement.hpp
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
 * @version 1 / 01-12-2016
 * @Resume:
 * @toto NA
 * @bug NA
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

using namespace std;

#ifndef EVENEMENT_H
#define EVENEMENT_H

class Evenement
{
    public:
    //attribut

    //fonctions
    Evenement();
    ~Evenement();
    void KeyBoardEventJ();
    sf::Vector2i Evenement::KeyBoardEventM();
};
