/*
 * Bonus.cpp
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
 * @version 1 / 31-12-2016
 * @Resume: Objet permettant de changer les attributs des joueurs
 * @bug NA
*/

#include "Bonus.h"


/** \brief Constructeur
 * \param les paramètres de la classe mère coordonné
 * \param la carte du jeu
 */
Bonus::Bonus(int t, int x, int y, int lo, int la, Map c) : Coordonne(x,y,lo,la)
{
    _type = t;
    if(t == 0)                  //type 0 -> ?
    {
        _duree = 10;
        _tpsProchain = 50;
    }else if (t == 1)           //Type 1 -> ?
    {
        _duree = 20;
        _tpsProchain = 20;

    }else                       //Type 2 -> ?
    {
        _duree = 15;
        _tpsProchain = 30;
    }
    Map _carte(c);
}

/*Valeur aléatoire donne entre a et b (a<b)
@param: a entier inclus
@param: b entier exclus de l'intervalle
@return: valeur comprise entre [a,b[
*/
int rand_a_b2(int a, int b)
{
    return rand()%(b-a) +a;
}


/** \brief Depose le bonus de manière aléatoire sur une plateforme
 * \param l'heure de la dernière apparition du bonus
 * \param Le joueur pouvant utilisé le bonus
 * \return le temps de la fin de la duree du bonus
 */
clock_t Bonus::apparitionBonus(clock_t dernier, Joueur j)
{
    if((clock()-dernier) >= _tpsProchain)                       //Si bonus peut apparaitre
    {
        int x = rand_a_b2(0,19);
        int y = 0;
        while(_carte.infos_case(x,y) == 0 && y <= 19)           //cherche à se deposer sur une plateforme
        {
            y++;
        }
        if(y >= 20)                                             //si pas trouve de plateforme
        {
            x++;
            while(_carte.infos_case(x,y) == 0 && y <= 19)           //cherche à se deposer sur une plateforme
            {
                y++;
            }
        }
        pos.x = x;
        pos.y = y;

        clock_t lancer = clock();                           //debut apparition
        while((clock()-lancer <= _duree) && (contact(j) == false) )
        {
            //lance l'apparition du bonus
            cout<<"Bonus à cet position : ("<<x<<","<<y<<")"<<endl;
            contact(j);
        }
        //this.delete;
        return(clock());
    }else                                                               //Si prochaine apparition pas autorisé
    {
        cout<<"Attend possible------------------------------"<<endl;
        return(dernier);
    }
}


/** \brief Indique si le joueur a utilisé le bonus
 * \param Le joueur afin de connaitre sa position
 * \return true si le joueur est entré en contact avec le bonus(= utilisé), false sinon
 */
bool Bonus::contact(Joueur j)
{
    bool bonusUsed = false;
    int jPosY = round(j.get_y()/_carte._largeurCase);                       //Position temporaire tant que partie graphique pas OK
    int jPosX = round(j.get_x()/_carte._longueurCase);
    if(jPosY >= 19) jPosY = 19;
    if(jPosX >= 19) jPosX = 19;

    if(pos.x == jPosX && pos.y == jPosY)                                    //Si contact, change attribut joueur
    {
        j.changerAttribut(_type);
        bonusUsed = true;                                                   //Bonus utilisé
    }

    return(bonusUsed);

}


Bonus::~Bonus()
{
    //dtor
}
