/*
 * Personnage.cpp
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
 * @version 2 / 6-12-2016
 * @Resume: Classe mère des personnages du jeu.
 * @toto NA
 * @bug NA
*/

#include "Personnage.h"

/* Constructeurs des personnages:
* @arg: n numero du personnage dans le jeu
* @arg: x abcisse des objets
* @arg: y ordonnee des objets
* @arg: lo la longueur de l'objet graphique
* @arg: lo la longueur de l'objet graphique
*/
Personnage::Personnage(int n, int x, int y, float lo, float la, Map c) : Coordonne(x,y,lo,la)
{
    _num = n;
    _vie = 100;
    Map _carte(c);
    _lastDefense = clock();
    cout<<"Creation personnage OK"<<endl;
}

/*Fonction d'affichage*/
void Personnage:: affiche(void) const
{
    cout<<"num Perso"<<endl;
	cout<<"num : "<<_num<<" "<<pos.x<<" "<<pos.y<<" "<<_longueur<<" "<<_largeur<<endl;
}



void Personnage::Initval(){
    // player position
    sf::Vector2f pos(320, 240);

    // player velocity (per frame)
    sf::Vector2f vel(0, 0);

    // gravity (per frame)
    sf::Vector2f gravity(0, .5f);

}




void Personnage::ColisionEnv(){
    // check for collision with the ground
        if (pos.y > _hautEcran-_largeur) {
            vel.y = 0;
            pos.y = _hautEcran;
        }
        // check for collision with the left border
        if (pos.x < 16) {
            vel.x = 0;
            pos.x = 16;
        }
        else if (pos.x > _longEcran) {
            vel.x = 0;
            pos.x = _longEcran;
        }
}



void Personnage::Jump(bool jump){
// jumping
        if (jump) {
            if(onground){ // on the ground
                vel.y += jumpacc * 2;
                jumpcounter = jumpframes;
            }
            else if (jumpcounter > 0) { // first few frames in the air
                vel.y += jumpacc;
                jumpcounter--;
            }
        }
        else { // jump key released, stop acceleration
            jumpcounter = 0;
        }
}

void Personnage::UpdatePerso(bool left, bool right){
     // first, apply velocities
        pos += vel;

        // determine whether the player is on the ground
        onground = pos.y >= _hautEcran-_largeur;
        // now update the velocity by...
        // ...updating gravity
        vel += gravity;

        // ...capping gravity
        if (vel.y > maxfall)
                vel.y = maxfall;
        if (left & !right) { // running to the left
            vel.x -= runacc;
        }
        if (!left & right) { // running to the right
            vel.x += runacc;
        }
        if(!left & !right) { // not running anymore; slowing down each frame
            vel.x *= 0.7;
        }
        if(left & right) { // if left and right keyboard press -> stop
            vel.x *= 0.0;
        }
}

/*void Personnage::colision()
{
    //pour le moment ya rien
}*/



/** \brief Creation de la fonction généré par le nouveau thread
 * \return valeur par defaut: 0
 * \TODO: ajouter impacte attaque
 */
unsigned int __stdcall Personnage::faireDef(void* data)
{
    Personnage  *pThis=reinterpret_cast< Personnage *>( data) ;         //initialisation thread avec classe Personnage

    clock_t debut;                                                      //temps au lancement de la defense
    clock_t fin;                                                        //temps actualisation
    int delai = 10;                                                     //temps d'utilisation du bonus
    debut = clock();
    fin = clock();
    while( (fin-debut) < delai)
    {
        fin = clock();
        //TODO: Stopper toute les attaques ICI (faire qd on aura la fonction attaque)!
    }
	return 0;
}




/** \brief Applique la défense du personnage pendant un temps limité
 * \param Le booléen indiquant si le joueur souhaite enclenché la défense
 */
void Personnage::defense (bool def)
{
    cout<<"Defense ON !!!!!!!!!!!!!!!!!!!"<<endl;
    if(def && ((clock()-_lastDefense) >= 10))                                          //si defense pas utiliser depuis plus de 10s
    {
        HANDLE myhandle;                                                               //valeur de retour de creation thread
        unsigned idThread;                                                            //identifiant thread
        myhandle = (HANDLE) _beginthreadex(NULL, 0, faireDef, this, 0, &idThread);    //thread -> appel fonction de defense
        if(!myhandle) cout<<"Erreur: thread non créer"<<endl;
        CloseHandle(myhandle);                                                        //fin du thread
        _lastDefense = clock();
    }
}



/*Destructeur*/
Personnage::~Personnage()
{
    //cout<<"Destructeur perso"<<endl;
    //pas d'elements dynamiques
}

