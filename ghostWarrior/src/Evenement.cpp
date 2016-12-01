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


