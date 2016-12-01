/*
 * Evenement.cpp
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
 * @Resume: Classe des joueurs: personnages jouables par les utilisateurs
 * @toto NA
 * @bug NA
*/


#include "Evenement.hpp"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Main::Main(){
    Initval();
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Main::~Main(){

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void Main::KeyBoardEvent(){
    while (window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Left:
                    left = event.type == sf::Event::KeyPressed;
                    break;
                case sf::Keyboard::Right:
                    right = event.type == sf::Event::KeyPressed;
                    break;
                case sf::Keyboard::Space:
                    jump = event.type == sf::Event::KeyPressed;
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
    }
}


