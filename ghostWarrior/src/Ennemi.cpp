/*
 * Ennemi.cpp
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
 * @version 1 / 25-11-2016
 * @Resume: Classe des personnages géré par le programme
 * @toto NA
 * @bug NA
*/

#include "Ennemi.h"


/* Constructeurs des personnages:
* @arg: n numero du personnage dans le jeu
* @arg: x abcisse des objets
* @arg: y ordonnee des objets
* @arg: lo la longueur de l'objet graphique
* @arg: lo la longueur de l'objet graphique
*/
Ennemi::Ennemi(int n, int x, int y, int lo, int la) :  Personnage(n,x,y,lo,la)
{
    //ctor
}

/*Valeur aléatoire donne entre a et b (a<b)
@param: a entier inclus
@param: b entier exclus de l'intervalle
@return: valeur comprise entre [a,b[
*/
int rand_a_b(int a, int b)
{
    return rand()%(b-a) +a;
}

/* Choix du comportement de l'ennemi (defense, attaque ou deplacement) en fonction du joueur
* @param : Le joueur du jeu (personnage controlé par l'humain)
*/
void Ennemi::combattre(Joueur j)
{
    if(_y == j.get_y())                          //Si au meme niveau
    {
        if(rand_a_b(0,10) <= 7) attaque();       //Attaque de manière aléatoire avec plus de probabilite
        else defendre();

    }else                                        //impossible attaquer
    {
        deplacer(j);
    }

}


/* Detecte s'il y a un obstacle entre l'ennemi et le joueur
* @Param: vect_x est la coordonnée x du vecteur joueur/ennemi
* @Param: vect_y est la coordonnée y du vecteur joueur/ennemi
* @Return: booléen 1 s'il y a des obstacles et 0 sinon.
*/
/*
bool Ennemi::obstace(int vect_x, int vect_y, Map m)
{

}*/

/* L'ennemi avance vers le joueur en fonction de la map
* @Param: le joueur vers qui l'ennemi approche
*/
void Ennemi::deplacer(Joueur j)
{
    if(_y == j.get_y())                    //Meme niveau
    {
        if(_x > j.get_x()) _x = _x-1;      //prendre en compte peut être sur plateforme differente
        else _x = _x+1;
    }
    else//if(_y >= j.get_y())                     //Ennemi au dessus personnage
    {
        _y = _y+1;                          //saut
        if(_x > j.get_x()) _x = _x-1;
        else _x = _x+1;
    }
}


void Ennemi::defendre()
{

}

void Ennemi::attaque()
{

}




void Ennemi::affiche() const
{
    cout<<"Ennemi"<<endl;
	cout<<"num : "<<_num<<" "<<_x<<" "<<_y<<" "<<_longueur<<" "<<_largeur<<endl;
}

Ennemi::~Ennemi()
{
    //dtor
}
