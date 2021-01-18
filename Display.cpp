/*************************************************************************
                              Trajet -  description
                             -------------------
    début                : 11/2020
    copyright            : (C) 2020 par B.Pluvinet et M.Moutot
    e-mail               : berenice.pluvinet@insa-lyon.fr ; matthieu.moutot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe  (fichier .cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Display.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques






//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Display::Display ( const Display & unDisplay )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Display>" << endl;
#endif
} //----- Fin de Display (constructeur de copie)


Display::Display ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Display>" << endl;
#endif
} //----- Fin de Display


Display::~Display ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Display>" << endl;
#endif
} //----- Fin de ~Display


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
