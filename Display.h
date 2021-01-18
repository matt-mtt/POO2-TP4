/*************************************************************************
                           Display  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Display> (fichier Display.h) ----------------
#if ! defined ( Display_H )
#define Display_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes
//enum Action { Default, Graph, Exclude, Time }; // ici et/ou dans le main ?

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Display>
// Affiche le résultat demandé en fonction de l'action choisie par l'utilisateur
//
//------------------------------------------------------------------------

class Display
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void defaultDisp ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void graphDisp ( );


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Display ( const Display & unDisplay );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Display ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Display ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

//-------------------------------- Autres définitions dépendantes de <Display>

#endif // Display_H
