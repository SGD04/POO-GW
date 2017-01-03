/*
 * MainTest.cpp
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
 * @Resume: Fichier main permettant de tester les classes
 * @toto NA
 * @bug NA
*/


#include "Coordonne.h"
#include "Personnage.h"
#include "Ennemi.h"
#include "Joueur.h"
#include "Map.h"
#include "Evenement.hpp"
#include "Bonus.h"
#include <windows.h>

#include <string>
#include <iostream>
#include <vector>
using namespace std;



int main()
{
    /*Taille de l'ecran (full screen sans la bare windows)*/
    int xScreen = GetSystemMetrics( SM_CXSCREEN );
    int yScreen = GetSystemMetrics( SM_CYSCREEN );

    Evenement evenement;
   Map carte;
    carte.afficher();
    /*Map copie(carte);
    cout<<endl<<"-------------------------Coppie!!!!!"<<endl;
    copie.afficher();*/





    string name("Player1");
    Joueur ghost1(1,320,420,3*carte.getLongeurCase(), 3*carte.getLargeurCase(),carte,name);

    Ennemi en(1,10,10,100,100,carte);
    Bonus bonus(0,0,0,0,0,carte);



    //-----------------------------CLASS GRAPHIQUE A FAIRE-----------------------------------------------

    sf::Texture Background;
    if (!Background.loadFromFile("fond_ville_nuit.png"))
    {
    // error...
        cout<<"erreur chargement texture"<<endl;
    }

    sf::Texture Ghost_t;
    if (!Ghost_t.loadFromFile("fantome_essai_pixel_ia.png"))
    //if (!Ghost_t.loadFromFile("testVert.png"))
    {
    // error...
        cout<<"erreur chargement texture"<<endl;
    }
    Ghost_t.setSmooth(true);
    sf::Sprite ghost;
    ghost.setTexture(Ghost_t);
    sf::Vector2f taille = sf::Vector2f(3*(carte.getLongeurCase()/500),3*(carte.getLargeurCase()/500));
    //cout<<"taille: "<<carte.getLongeurCase()/_longEcran<<" , "<<carte.getLargeurCase()/_hautEcran<<endl;
    ghost.setScale(taille);
    //ghost.setTextureRect(sf::IntRect(495, 652, 3*carte.getLongeurCase(), 3*carte.getLargeurCase()));
    //ghost.setTextureRect(sf::IntRect(0, 0, 3*carte.getLargeurCase(), 3*carte.getLongeurCase()));
    //ghost.setScale(0.15f,0.15f);
    //ghost.setPosition(0,0);
    //ghost.setOrigin(495,652);
    ghost.setOrigin(495,652);

    sf::Sprite background;
    background.setTexture(Background);
    background.setScale(xScreen,yScreen);

    //plateforme
    sf::Texture plateforme;
    if (!plateforme.loadFromFile("brique.png"))
    {
        cout<<"erreur chargement texture"<<endl;
    }
    plateforme.setSmooth(true);
    plateforme.setRepeated(true);           //repete la plateforme
    sf::Sprite platef;                      //creation sprite
    platef.setTexture(plateforme);
    platef.setTextureRect(sf::IntRect(1, 0, carte.getLargeurCase(), carte.getLongeurCase()));


    //Ennemi
   /* sf::Texture ene;
    if (!ene.loadFromFile("perso_robot.png"))
    {
    // error...
        cout<<"erreur chargement texture"<<endl;
    }
    ene.setSmooth(true);
    sf::Sprite robot;
    robot.setTexture(ene);
    sf::Vector2f taille2 = sf::Vector2f(3*(carte.getLongeurCase()/500),3*(carte.getLargeurCase()/500));
    robot.setScale(taille2);
    robot.setOrigin(495,500);*/


    //----------------------------------------------------------------------------
    carte.afficher();

    clock_t last = clock();
    //boucle principale
    while(evenement.window.isOpen()){

        evenement.KeyBoardEventJ();           //recupe clavier
        ghost1.UpdatePerso(evenement.left,evenement.right);                    // mise a jour du perso(application vitesse/gravite/acceleration)
        ghost1.Jump(evenement.jump);                           // fonction pour sauter
        ghost1.ColisionEnv();                       // collision mur lateral et sol -> a ameliorer pour suivre map
        //ghost1.colision(evenement.jump, evenement.left, evenement.right);
        //ghost1.defense(evenement.def);
        //en.combattre(ghost1);

        last = bonus.apparitionBonus(last,ghost1);

        ghost.setPosition(ghost1.pos);              // mise a jour de la position du perso

        evenement.window.clear();                   //effaçage de l'ecran
        evenement.window.draw(background);          // dessin fond
        for(int i=0; i<20; i++)
        {
           for(int j=0; j<20; j++)
            {
                if(carte.infos_case(i,j) == 1)
                {
                    platef.setPosition(sf::Vector2f(i*carte.getLongeurCase(),j*carte.getLargeurCase())); // position absolue
                    evenement.window.draw(platef);              //dessin plateforme
                }
           }
        }

        evenement.window.draw(ghost);               // dessin joueur
        //evenement.window.draw(robot);               // dessin ennemi
        evenement.window.display();                 // afichage ecran
    }

	return 0;
}
