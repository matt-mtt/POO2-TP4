/*************************************************************************
                              Trajet -  description
                             -------------------
    début                : 11/2020
    copyright            : (C) 2020 par B.Pluvinet et M.Moutot
    e-mail               : berenice.pluvinet@insa-lyon.fr ; matthieu.moutot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe  (Read.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Read.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Read::openFile ( string fileName )
{
    file.open( fileName, ios::in );

    if( file )
    {
        return true;
    }
    return false;
}

bool Read::endOfFile ( )
{
    if( !file.eof() )
    {
        return false;
    }
    else
    {
        return true;
    }
}


// 192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] "GET /temps/4IF16.html HTTP/1.1" 200 12106
// "http://intranet-if.insa-lyon.fr/temps/4IF15.html"
// "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1"

void Read::translate ( )
{
        getline( file, myLog.IP, '-' );
        getline( file, myLog.userLogName, '-' );
        getline( file, myLog.authenticatedUserName, '[' );
        getline( file, myLog.date, ':');
        string shour, smin, ssec;
        getline( file, shour, ':' );
        getline( file, smin, ':');
        getline( file, ssec, '+' );
        myLog.hour = stoi(shour);
        myLog.min = stoi(smin);
        myLog.sec = stoi(ssec);
        getline( file, myLog.GMT_diff, ']' );
        file.ignore();
        file.ignore();

        getline( file, myLog.actionType, '/' ); // attention, ne lit pas le /
        string firstpart;
        getline( file, firstpart, '.' );
        getline( file, myLog.targetExtension, ' ' );
        string lastpart;
        getline(file, lastpart, '"');
        myLog.target = firstpart + '.' + myLog.targetExtension;
        file.ignore();

        getline( file, myLog.returnCode, ' ' );
        getline( file, myLog.dataAmount, '"' );
        getline( file, myLog.referer, '"' );
        file.ignore();
        file.ignore();

        getline( file, myLog.webBrowserID, '"' );
        file.ignore();
        file.ignore();

}



void Read::displayLog ( )
{
    cout << "Affichage du log " << endl;
    cout << "----------------" << endl;
    cout << "IP:                    " << myLog.IP << endl;
    cout << "userLogName:           " << myLog.userLogName << endl;
    cout << "authenticatedUserName: " << myLog.authenticatedUserName << endl;
    cout << "date:                  " << myLog.date << endl;
    cout << "hour:                  " << myLog.hour << endl;
    cout << "min:                   " << myLog.min << endl;
    cout << "sec:                   " << myLog.sec << endl;
    cout << "GMT_diff:              " << myLog.GMT_diff << endl;
    cout << "actionType:            " << myLog.actionType << endl;
    cout << "target:                " << myLog.target << endl;
    cout << "extension:             " << myLog.targetExtension << endl;
    cout << "returnCode:            " << myLog.returnCode << endl;
    cout << "dataAmount:            " << myLog.dataAmount << endl;
    cout << "referer:               " << myLog.referer << endl;
    cout << "webBrowserID:          " << myLog.webBrowserID << endl;
    cout << endl;
}


Log Read::getMyLog ( )
{
    return myLog;
}



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Read::Read ( const Read & unRead )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Read>" << endl;
#endif
} //----- Fin de Read (constructeur de copie)


Read::Read ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Read>" << endl;
#endif
} //----- Fin de Read

Read::Read ( string fileName ) : file(fileName)
{

}


Read::~Read ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Read>" << endl;
#endif
} //----- Fin de ~Read


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
