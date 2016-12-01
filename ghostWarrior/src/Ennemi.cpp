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
Ennemi::Ennemi(int n, int x, int y, int lo, int la, Map c) :  Personnage(n,x,y,lo,la)
{
    Map _carte(c);
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
    bool b = false;
    for(int i=_x; i<=j.get_x(); i++)                //parcours entre ennemie et joueur
    {
        if(_carte.infos_case(_y,i) == 1)            //si obstacle
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
    if((_y == j.get_y()) && (obstacle(j) == 0))                          //Si au meme niveau sans obstacle
    {
        if(rand_a_b(0,10) <= 7) attaque();       //Attaque de manière aléatoire avec plus de probabilite
        else defendre();

    }else                                        //impossible attaquer
    {
        deplacer(j);
    }

}


int Ennemi::tomber()
{
    int ord = _y;
     while((_carte.infos_case(_x, ord) == 0) && (ord > 0))   //Tombe s'il n'y a pas de plateforme
        {
            ord++;
        }
    return(ord-1);
}














/* L'ennemi avance vers le joueur en fonction de la map
* @Param: le joueur vers qui l'ennemi approche
*/
void Ennemi::deplacer(Joueur j)
{

   /* Noeud depart(_x,_y,0,0);    //depart = coordonne de l'ennemi
    list<Noeud> listeOuverte;
    list<Noeud> listeNoeudVerif;
    listeOuverte.push_back(depart);
    listeNoeudVerif.push_back(depart);
    while(!listeOuverte.empty())           //Non vide
    {
        //pas sur h = noeud
        Noeud h = listeOuverte.back();
        listeOuverte.pop_back();            //depile
        if((h.get_x() == j.get_x()) && (h.get_y() == j.get_y())) //si atteint objectif
        {
            /*reconstituerChemin(u)
            terminer le programme*/
     /*   }
        int vi, vj;             //coordonnees i et j voisins de h
        for(vi = h.get_x()-1; vi<=h.get_x()+1; vi++)
        {
            for(vj = h.get_y()-1; vj <= h.get_y()+1; vj++)
            {
                if(_grille.infos_case(vi,vj) == 0)          //si case n'est pas un obstacle
                {
                    //if(Noeud deja ds la listeOuverte)
                    {
                       // if(NoeudV.comparer(Noeud ds liste) == 1)
                       {
                           //maj heuristique du noeud ds liste ouverte
                           //maj lien parent
                       }else
                       {
                           //ajoute Noeud a la liste ouverte (lien parent = courant)
                       }
                    }
                }
            }

        }
        for(//Toute la liste ouverte)
        {
            //Noeud = meilleur qualite Noeud
            /*if(Noeud.compare(NoeudListOuverte) == 1)
            Noeud = NoeudListOuverte*/
       /* }
        //Mettre Noeud meilleur ds liste Fermer

    }*/

    /*int droit = _x+1;
    int gauche = _x-1;
    int dessus = _y+1;
    int dessous = _y-1;*/
   /* for(int i=gauche; i<=droit; i++)
    {
        for(int h=dessous; h<=dessus; h++)
        {
            if(_carte.infos_case(i,h) == 0)
            {
                if(_x < j.get_x()) _x = _x+1;
                else if( _x >= j.get_x()) _x = _x-1;
                else if(_y < j.get_y()) _y = _y+1;
                else _y = _y-1;

            }
        }
    }*/
    //Ennemi en haut, à gauche du joueur
    if(_x < j.get_x() && _y > j.get_y())
    {
        if (_carte.infos_case(_x+1,_y) == 0)            //Priorite 1: Deplacement vers la droite
        {
            _x++;
            _y = tomber();
        }else if(_carte.infos_case(_x-1,_y) == 0)       //Priorite 2: Deplacement vers la gauche
        {
            _x--;
            _y = tomber();
        }else                                           //Priorite 3: saut
        {
            if(_carte.infos_case(_x+1,_y+1) == 0) {_x++; _y++;}     //saut à droite
            else {_x--; _y++;}                                      //saut à gauche
        }
    }
    //Ennemi en haut, à droite du joueur
    else if(_x >= j.get_x() && _y >= j.get_y())
    {
        if (_carte.infos_case(_x-1,_y) == 0)            //Priorite 1: Deplacement vers la gauche
        {
            _x--;
            _y = tomber();
        }else if(_carte.infos_case(_x+1,_y) == 0)       //Priorite 2: Deplacement vers la droite
        {
            _x++;
            _y = tomber();
        }else                                           //Priorite 3: saut
        {
            if(_carte.infos_case(_x-1,_y+1) == 0) {_x--; _y++;}     //saut à gauche
            else {_x++; _y++;}                                      //saut à droite
        }
    }
    //Ennemi en bas, à droite du joueur
    else if(_x < j.get_x() && _y < j.get_y())
    {
        if(_carte.infos_case(_x+1,_y+1) == 0)            //Priorite 1: Deplacement vers la droite
        {
            _x++;
            _y = tomber();
        }else if(_carte.infos_case(_x-1,_y) == 0)       //Priorite 2: Deplacement vers la gauche
        {
            _x--;
            _y = tomber();
        }else                                           //Priorite 3: saut
        {
            if(_carte.infos_case(_x+1,_y+1) == 0) {_x++; _y++;}     //saut à droite
            else {_x--; _y++;}                                      //saut à gauche
        }
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
	cout<<"num: "<<_num<<" Coord: ("<<_x<<","<<_y<<") "<<_longueur<<" "<<_largeur<<endl;
}

Ennemi::~Ennemi()
{
    //dtor
}
