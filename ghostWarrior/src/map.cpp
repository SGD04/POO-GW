/*
 * Map.cpp
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
#include "Map.h"

/** \brief
 *  Creation de la map avec 0 s'il n'y a pas d'obstacle et 1 sinon
 */
Map::Map()
{
    _background = 0;
    _plateforme = 1;
    for(int i=0; i<LARGEUR_ECRAN; i++)
    {
        for(int j=0; j<LONGUEUR_ECRAN; j++)
        {
            _grille[i][j] =rand()%(2-0);
        }
    }
}



/** \brief Affichage en 0 et 1 de la map
 */
void Map::afficher() const
{
    for(int i=0; i<LARGEUR_ECRAN; i++)
    {
        for(int j=0; j<LONGUEUR_ECRAN; j++)
        {
            cout<<_grille[i][j]<<"|";
        }
        cout<<endl;
        cout<<"----------"<<endl;
    }
}

Map::~Map()
{
    delete _grille;
}
