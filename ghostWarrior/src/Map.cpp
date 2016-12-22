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
 * @version 2 / 30-11-2016
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
    using std::vector;

    _grille.resize(NB_CASE_LONG);
    for (int i = 0; i < NB_CASE_LAR; i++)               //Initialisation taille tableau dynamique
    {
      _grille[i].resize(NB_CASE_LONG);
    }

    _background = 0;
    _plateforme = 1;
    _hautEcran = GetSystemMetrics( SM_CYSCREEN );
    _longEcran = GetSystemMetrics( SM_CXSCREEN );
    _largeurCase = _hautEcran/NB_CASE_LAR;       //taille écran /nb cases
    _longueurCase =_longEcran/NB_CASE_LONG;      //taille écran /nb cases


    /*Initialisation des données*/
    int i,j;
    for(i=0; i< _grille.size(); i++)
    {
        for(j=0; j< _grille[i].size(); j++)
        {
            _grille[i][j] = 0;
        }
    }

    for(i=0; i< _grille.size(); i++)
    {
        for(j=0; j< _grille[i].size(); j++)
        {
           _grille[1][i] = 1;
        }
    }

}

/** \brief Constructeur par recopie d'un objet MAP
 *
 * \param c: un objet MAP
 */
Map::Map(const Map & c)
{
    using std::vector;

    int tailleI = c._grille[0].size();
    _grille.resize(c._grille.size());
    for (int i = 0; i < tailleI; i++)               //Initialisation taille tableau dynamique
    {
      _grille[i].resize(c._grille.size());
    }

    int i ,j;                                       //copie tableau
    for(i=0; i< _grille.size(); i++)
    {
        for(j=0; j< _grille[i].size(); j++)
        {
           _grille[i][j] = c._grille[i][j] ;
        }
    }

    _background = c._background;
    _plateforme = c._plateforme;
    _longueurCase = c._longueurCase;
    _largeurCase = c._largeurCase;
}

/** \brief Affichage en 0 et 1 de la map
 */
void Map::afficher()
{
    for(int j=0; j<_grille.size(); j++)
    {
        cout<<"J: "<<j<<"-> ";
        for(int i=0; i<_grille[j].size(); i++)
        {
            cout<<_grille[j][i]<<"|";
        }
        cout<<endl;
        cout<<"--------------------"<<endl;
    }
}


int Map::infos_case (int x, int y)
{
    return(_grille[y][x]);
}


float Map::getLongeurCase()
{
    return(_longueurCase);
}

float Map::getLargeurCase()
{
    return(_largeurCase);
}

Map::~Map()
{
//    delete _grille;
}

