/*************************************************************************
                              Read -  description
                             -------------------
    début                : 12/2020
    copyright            : (C) 2020 par B.Pluvinet et M.Moutot
    e-mail               : berenice.pluvinet@insa-lyon.fr ; matthieu.moutot@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Read> (fichier Read.h) ----------------
#if ! defined ( Read_H )
#define Read_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Log
{
    string IP;
    string userLogName;
    string authenticatedUserName;

    string date;
    int hour;
    int min;
    int sec;
    string GMT_diff;

    string actionType;
    string target;
    string targetExtension;

    string returnCode;
    string dataAmount;

    string referer;
    string webBrowserID;

} Log;
//------------------------------------------------------------------------
// Rôle de la classe <Read>
// Lit un fichier de log Apache
//
//------------------------------------------------------------------------

class Read
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool openFile ( string fileName );
    // Mode d'emploi :
    // Ouvre le fichier de log donné en entrée
    // Contrat :
    //

    bool endOfFile ( );
    // Mode d'emploi :
    // Indique si la fin du fichier est atteinte
    // Contrat :
    //

    void translate ( );
    // Mode d'emploi :
    // Traduit une ligne de log pour et la stocke dans lastLog
    // Contrat :
    //

    void displayLog ( );
    // Mode d'emploi :
    // Affiche les composants d'un log pour voir si il a bien été retranscrit
    // Contrat :
    //

    Log getMyLog ( );
    // Mode d'emploi :
    // Renvoie le dernier log
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Read ( const Read & unRead );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Read ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Read ( string fileName ) ;

    virtual ~Read ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
ifstream file;
Log myLog;

};

//-------------------------------- Autres définitions dépendantes de <Read>

#endif // Read_H
