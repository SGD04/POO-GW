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

Evenement::Evenement()
{
    cout<<"debut ev"<<endl;
     _hautEcran = GetSystemMetrics( SM_CYSCREEN );//480;//
     _longEcran = GetSystemMetrics( SM_CXSCREEN );
    // Declare and create a new window
    window.create(sf::VideoMode(_longEcran, _hautEcran), "Ghost Warrior",sf::Style::Default);
    //reglage du framerate
    window.setFramerateLimit(60);
    //synchronisation rafraichissement ecran
    window.setVerticalSyncEnabled(false);
    cout<<"fin ev"<<endl;
}

Evenement::~Evenement(){

}

void Evenement::KeyBoardEventJ(){
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
                case sf::Keyboard::D:                           //defense
                    def = event.type == sf::Event::KeyPressed;
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
    }
}

sf::Vector2i Evenement::KeyBoardEventM(){
    while (window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::MouseButtonReleased:
                switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    return sf::Mouse::getPosition();
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
    }
}


bool Evenement::get_left()
{
    return(left);
}

bool Evenement::get_right()
{
    return(right);
}

bool Evenement::get_jump()
{
    return(jump);
}
