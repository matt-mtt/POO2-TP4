// Includes
#include "Read.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

// Constantes
bool doGraph = false;
bool typeSelection = false;
bool timeSelection = false;
string fichierDot;
string hour;

// Methodes

void getActions ( int argc, char * argv[] )
{
    for ( int i=1; i<argc; i++)
    {
      if (strcmp(argv[i],"-g") == 0 )
        doGraph = true;
        fichierDot = argv[i+1];
      if (strcmp(argv[i],"-e") == 0 )
        typeSelection = true;
      if (strcmp(argv[i],"-t") == 0 )
        timeSelectoin = true;
        hour = argv[i+1];
    }
}

// ./analog =  arg[0]
// -g = arg[1]
// nomfichier.dot = argv[2]
// -e = arg[3]
// -t = arg [4]
// heure = arg[5]
// nomfichier.log = arg[6]
int main ( int argc, char * argv[] )
{
    /* 1) le lis une ligne et j'en fais un log
    2) j'ajoute le lien si il n'existe pas
    3) quand il existe, j'ajoute la cible à sa map
    4) en foncton de l'action, j'affiche */

    Read myRead = Read ( );

    myRead.openFile( "log.txt" ); // argv[6]

    while ( myRead.endOfFile( ) == false )
    {
            Log newLog;
            //Graph myGraph;

            myRead.translate( );

            // switch ?


            newLog = myRead.getMyLog();

            if  ( typeSelection == true )
            {
              //check
              // add to graph   //myGraph.addLog( newLog.target, newLog.referer );
            }

            if ( timeSelection == true )
            {
              // same
            }

            if ( doGraph == true )
            {
              // 
            }

            //myRead.displayLog( );
    }

    return 0;

}



/*
while ( myRead.endOfFile( ) == false )
{
        Log newLog;
        //Graph myGraph;

        myRead.translate( );

        /*for ( int i=1; i<=argc; i++)
        {
            if ( strcmp(argv[i], '-e') == 0 )
            {
                // use
            }

            if ( strcmp(argv[i], '-t') == 0 )
            {
                // use argv[i+1] to get hour
            }
        }


        newLog = myRead.getMyLog();

        //myGraph.addLog( newLog.target, newLog.referer );

        myRead.displayLog( );
      }
*/
