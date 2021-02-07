// Includes
#include "Read.h"
#include "Graph.h"
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
int hour;

// Methodes

void getActions ( int argc, char * argv[] )
{
    for ( int i=0; i<argc; i++)
    {
      if (strcmp(argv[i],"-g") == 0 )
      {
        doGraph = true;
        fichierDot = argv[i+1];
      }
      if (strcmp(argv[i],"-e") == 0 )
      {
        typeSelection = true;
      }
      if (strcmp(argv[i],"-t") == 0 )
      {
        timeSelection = true;
        hour = atoi(argv[i+1]);
      }
    }

     cout << "TYPE Selection --> " << typeSelection << endl;
     cout << "TIME Selection --> " << timeSelection <<endl;
     cout << "GRAPH --> " << doGraph << endl;
}

void displayArgs( int argc, char * argv[] )
{
  for( int i=0; i<=argc; i++ )
  {
    cout << argv[i] << endl;
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
    //displayArgs(argc, argv);
    getActions(argc, argv);
    Read myRead = Read ( );
    // Graph myGraph = Graph();

    myRead.openFile( "log.txt" );
    Graph myGraph = Graph();

    // Ajout des logs
    while ( myRead.endOfFile( ) == false )
    {
            Log newLog;
            myRead.translate( );
            newLog = myRead.getMyLog();

            if ( typeSelection == true )
            {
              if ( newLog.targetExtension.compare("css") != 0 || newLog.targetExtension.compare("jpg") != 0 )
              {
                myGraph.addLog( newLog.target, newLog.referer );
              }
            }

            else if ( timeSelection == true )
            {
              if ( newLog.hour >= hour && newLog.hour <= hour+1 )
              {
                myGraph.addLog( newLog.target, newLog.referer );
              }
            }

            else
            {
               myGraph.addLog( newLog.target, newLog.referer );
            }

   }

   // Opérations sur le graph
   myGraph.searchTop();

   if ( doGraph == true )
   {
      // methode du graph
      myGraph.drawGraph();
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
