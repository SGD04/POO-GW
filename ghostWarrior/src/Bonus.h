/*
 * Bonus.h
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

#ifndef BONUS_H
#define BONUS_H

#include "Coordonne.h"
#include "Map.h"
#include "Joueur.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



class Bonus : public Coordonne
{
    private:
        Map _carte;
        int _type;
        int _duree;                 //duree d'utilisation du bonus
        int _tpsProchain;

    public:
        Bonus(int t,int x, int y, int lo, int la, Map c);
        clock_t apparitionBonus(clock_t dernier,Joueur j);
        bool contact(Joueur);
        virtual ~Bonus();

    protected:

    private:
};

#endif // BONUS_H
