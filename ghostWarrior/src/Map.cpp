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
    /*vector< vector<int> > _grille(LONGUEUR_ECRAN);
    int h;
    for(h = 0; h< LONGUEUR_ECRAN; h++)
    {
        _grille[h] = vector<int> (10);
    }
    for(int i=0; i < _grille.size(); i++)
    {
        for(int j=0; j < _grille[i].size(); j++)
        {
            _grille[i][j] = 0;
        }
    }*/
   /* int i, j;
      for(j=0; j<LONGUEUR_ECRAN; j++)
    {
        cout<<"J: "<<j<<"-> ";
        for(i=0; i<LARGEUR_ECRAN; i++)
        {
            if(j%2 )
            {
                if( i == 0) _grille[j][i] == 1;

                else if ((j== 1) && (i==1 || i==4)) _grille[j][i] == 1;
                else if((j== 3) && ((i>=1 && i<=6) || (i == 8))) _grille[j][i] == 1;
                else if((j== 5) && (i==3 || i==6 || i == 9)) _grille[j][i] == 1;
                else if((j== 7) && (i==2 || i==4 || (i >= 6 && i<=9))) _grille[j][i] == 1;
                else if((j==9)&& (i==1 || i==3 || i==4 || i==6 || i==7 || i==8)) _grille[j][i] == 1;
                else _grille[j][i] == 0;
            }
            else  _grille[j][i] = 0;
            cout<<_grille[j][i]<<"|";
        }
        cout<<endl;
        cout<<"--------------------"<<endl;*/
    int i, j;
    for(j=0; j<LONGUEUR_ECRAN; j++)
    {
        for(i=0; i<LARGEUR_ECRAN; i++)
        {
            if(j%2 ) cout;
            else _grille[j][i] = 0;
        }
    }
    _grille[1][0] = 1;
    _grille[1][1] = 1;
    _grille[1][2] = 0;
    _grille[1][3] = 0;
    _grille[1][4] = 1;
    _grille[1][5] = 0;
    _grille[1][6] = 0;
    _grille[1][7] = 0;
    _grille[1][8] = 0;
    _grille[1][9] = 0;
    _grille[3][0] = 1;
    _grille[3][1] = 1;
    _grille[3][2] = 1;
    _grille[3][3] = 1;
    _grille[3][4] = 1;
    _grille[3][5] = 1;
    _grille[3][6] = 1;
    _grille[3][7] = 0;
    _grille[3][8] = 1;
    _grille[3][9] = 0;
    _grille[5][0] = 1;
    _grille[5][1] = 0;
    _grille[5][2] = 0;
    _grille[5][3] = 1;
    _grille[5][4] = 0;
    _grille[5][5] = 0;
    _grille[5][6] = 1;
    _grille[5][7] = 0;
    _grille[5][8] = 0;
    _grille[5][9] = 1;
    _grille[7][0] = 1;
    _grille[7][1] = 0;
    _grille[7][2] = 1;
    _grille[7][3] = 0;
    _grille[7][4] = 1;
    _grille[7][5] = 0;
    _grille[7][6] = 1;
    _grille[7][7] = 1;
    _grille[7][8] = 1;
    _grille[7][9] = 0;
    _grille[9][0] = 1;
    _grille[9][1] = 1;
    _grille[9][2] = 0;
    _grille[9][3] = 1;
    _grille[9][4] = 1;
    _grille[9][5] = 0;
    _grille[9][6] = 1;
    _grille[9][7] = 1;
    _grille[9][8] = 1;
    _grille[9][9] = 0;
    _grille[4][4] = 1;
}

/** \brief Constructeur par recopie d'un objet MAP
 *
 * \param c: un objet MAP
 */
Map::Map(const Map & c)
{
    _grille[LONGUEUR_ECRAN][LARGEUR_ECRAN] = c._grille[LONGUEUR_ECRAN][LARGEUR_ECRAN];
    for(int j=0; j<LONGUEUR_ECRAN; j++)
    {
        for(int i=0; i<LARGEUR_ECRAN; i++)
        {
            _grille[j][i] = c._grille[j][i];
        }
    }
    _background = c._background;
    _plateforme = c._plateforme;
}

/** \brief Affichage en 0 et 1 de la map
 */
void Map::afficher()
{
    cout<<"Grille :"<<endl;
    for(int j=0; j<LONGUEUR_ECRAN; j++)
    {
        cout<<"J: "<<j<<"-> ";
        for(int i=0; i<LARGEUR_ECRAN; i++)
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

Map::~Map()
{
    delete _grille;
}
