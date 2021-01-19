// Includes
#include "Read.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Constantes

enum Action { Graph, Exclude, Time };

// Methodes

void hello ( )
{
    cout << "this is a test for github" << endl;
}

Action convertAction ( char * arg )
{
    if( strcmp(arg,'-g')==0 )
    {
        return Graph;
    }
    if( strcmp(arg,'-e')==0 )
    {
        return Exclude;
    }
    if( strcmp(arg,'-t')==0 )
    {
        return Time;
    }
}

int main ( int argc, char ** argv )
{
    /* 1) le lis une ligne et j'en fais un log
    2) j'ajoute le lien si il n'existe pas
    3) quand il existe, j'ajoute la cible à sa map
    4) en foncton de l'action, j'affiche */

    Read myRead = Read ( );

    myRead.openFile( "log.txt" );

    while ( myRead.endOfFile( ) == false )
        {
            Log newLog;
            //Graph myGraph;

            myRead.translate( );

            for ( int i=1; i<=argc; i++)
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


    return 0;

}
