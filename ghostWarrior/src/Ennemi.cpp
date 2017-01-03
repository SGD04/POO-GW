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
Ennemi::Ennemi(int n, int x, int y, float lo, float la, Map c) : Personnage(n,x,y,lo,la,c)
{
        cout<<"Constructeur ennemi"<<endl;
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



/* Detecte s'il y a un obstacle entre l'ennemi et le joueur
* @Return: booléen 1 s'il y a des obstacles et 0 sinon.
*  @Param: le joueur vers qui l'ennemi approche
*/
bool Ennemi::obstacle(Joueur j)
{
    int jPosX = round(j.get_x()/_carte._longueurCase);
    if(jPosX >= 19) jPosX = 19;

    bool b = false;
    for(int i=pos.x; i<=jPosX; i++)                //parcours entre ennemie et joueur
    {
        if(_carte.infos_case(pos.y,i) == 1)            //si obstacle
        {
            b = true;
        }
    }
    return(b);
}

/* Choix du comportement de l'ennemi (defense, attaque ou deplacement) en fonction du joueur
* @param : Le joueur du jeu (personnage controlé par l'humain)
*/
void Ennemi::combattre(Joueur j)
{

    int jPosY = round(j.get_y()/_carte._largeurCase);                   //Todo: achanger quand grapisme = OK
    if(jPosY >= 19) jPosY = 19;

    if((pos.y == jPosY) && (obstacle(j) == 0))                          //Si au meme niveau sans obstacle
    {
        if(rand_a_b(0,10) <= 7) attaque();                              //Attaque de manière aléatoire avec plus de probabilite
        else defense(true);

    }else if((jPosY >= pos.y-2) || (jPosY <= pos.y+2) || ((pos.y == jPosY) && (obstacle(j) != 0)))       //impossible attaquer => se rapproche
    {
        deplacer(j);
    }
    //Ne fais rien si joueur trop loin

}

  void Ennemi::attaque(){cout<<"ATTAQUE ENNEMI -----> "<<endl;}


/** \brief Fait tomber l'ennemi jusqu'a la prochaine plateforme
 * \return La nouvelle ordonnée (y) de l'ennemi
 */
int Ennemi::tomber()
{
    int ord = pos.y;
    while((_carte.infos_case(pos.x, ord) == 0) && (ord < 19))   //Tombe s'il n'y a pas de plateforme
    {
        ord++;
    }
    return(ord);
}






/* L'ennemi avance vers le joueur en fonction de la map
* @Param: le joueur vers qui l'ennemi approche
* \Todo: Quand graphisme OK: recalculer les positions du joueur
* /!\ le faire aussi dans fonction combatre et obstacle!
* \Todo: Quand fonction colision OK: enlever les calcul de bord de map
*/
void Ennemi::deplacer(Joueur j)
{
    /*int jPosX = round((j.get_x()/_carte._longueurCase)- (j.get_longueur()/_carte._longueurCase)); //devrait etre les bonnes positions
    int jPosY = round((j.get_y()/_carte._largeurCase)- (j.get_largeur()/_carte._longueurCase));*/

        int jPosY = round(j.get_y()/_carte._largeurCase);                       //Position temporaire tant que partie graphique pas OK
        int jPosX = round(j.get_x()/_carte._longueurCase);
        if(jPosY >= 19) jPosY = 19;
        if(jPosX >= 19) jPosX = 19;


    cout<<"Ennemi: "<<pos.x<<","<<pos.y<<" ET Joueur case: "<<jPosX<<","<<jPosY<<endl;
    if((pos.x <= 0) || (pos.x >= 19) || (pos.y >= 19) || (pos.y <= 0))                   // si en dehors Map
    {
        /*appeler d'abord colision avant deplacer*/          /*A enelver plus tard quan colision = OK*/
        if(pos.x <= 0) pos.x = 0;
        else if(pos.x >= 19) pos.x = 19;
        else if(pos.y >= 19) pos.y = 19;
        else pos.y = 0;
        /*@TODO: gére colision bore de la map et avec les autres perso! ==> pas que soit au meme endroit!*/
    }
        //Ennemi en haut, à gauche du joueur
        if(pos.x < jPosX && pos.y > jPosY)
        {
            if (_carte.infos_case(pos.x+1,pos.y) == 0)            //Priorite 1: Deplacement vers la droite
            {
                pos.x++;
                pos.y = tomber();
            }else if(_carte.infos_case(pos.x-1,pos.y) == 0)       //Priorite 2: Deplacement vers la gauche
            {
                pos.x--;
                pos.y = tomber();
            }else                                                  //Priorite 3: saut
            {
                if(_carte.infos_case(pos.x+1,pos.y+1) == 0) {pos.x++; pos.y++;}     //saut à droite
                else {pos.x--; pos.y++;}                                            //saut à gauche
            }
        }
        //Ennemi en haut, à droite du joueur
        else if(pos.x >= jPosX && pos.y >= jPosY)
        {
            if (_carte.infos_case(pos.x-1,pos.y) == 0)            //Priorite 1: Deplacement vers la gauche
            {
                pos.x--;
                pos.y = tomber();
            }else if(_carte.infos_case(pos.x+1,pos.y) == 0)       //Priorite 2: Deplacement vers la droite
            {
                pos.x++;
                pos.y = tomber();
            }else                                                   //Priorite 3: saut
            {
                if(_carte.infos_case(pos.x-1,pos.y+1) == 0) {pos.x--; pos.y++;}     //saut à gauche
                else {pos.x++; pos.y++;}                                      //saut à droite
            }
        }
        //Ennemi en bas, à droite du joueur
        else if(pos.x <= jPosX && pos.y <= jPosY)
        {
            if(_carte.infos_case(pos.x+1,pos.y) == 0)            //Priorite 1: Deplacement vers la droite
            {
                pos.x++;
                pos.y = tomber();
            }else if(_carte.infos_case(pos.x-1,pos.y) == 0)       //Priorite 2: Deplacement vers la gauche
            {
                pos.x--;
                pos.y = tomber();
            }else                                                  //Priorite 3: saut
            {
                if(_carte.infos_case(pos.x+1,pos.y+1) == 0) {pos.x++; pos.y++;}     //saut à droite
                else {pos.x--; pos.y++;}                                      //saut à gauche
            }
        }
        //Ennemi en bas, à gauche du joueur
        else if(pos.x > jPosX && pos.y < jPosY)
        {
            if(_carte.infos_case(pos.x-1,pos.y) == 0)       //Priorite 1: Deplacement vers la gauche
            {
                pos.x--;
                pos.y = tomber();
            }
            else if(_carte.infos_case(pos.x+1,pos.y) == 0)            //Priorite 2: Deplacement vers la droite
            {
                pos.x++;
                pos.y = tomber();
            }else                                                  //Priorite 3: saut
            {
                if(_carte.infos_case(pos.x-1,pos.y+1) == 0) {pos.x--; pos.y++;}     //saut à gauche
                else {pos.x++; pos.y++;}                                            //saut à droite
            }
        }


}




/* @Brief detecte si le joeur rentre dans une plateforeme, un joueur ou un bonus et indique l'action à réaliser
*
*
*/
void Ennemi::colision()
{
    if(_carte.infos_case(pos.x,pos.y) == 1)         //Si plateforme présente
    {

    }

}




void Ennemi::affiche() const
{
    cout<<"Ennemi"<<endl;
	cout<<"num: "<<_num<<" Coord: ("<<pos.x<<","<<pos.y<<") "<<_longueur<<" "<<_largeur<<endl;
}

Ennemi::~Ennemi()
{
    cout<<"Destructeur Ennemi"<<endl;
    //dtor
}
