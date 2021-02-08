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
int count=0;

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

     /*cout << "TYPE Selection --> " << typeSelection << endl;
     cout << "TIME Selection --> " << timeSelection <<endl;
     cout << "GRAPH --> " << doGraph << endl;*/
}

void displayArgs( int argc, char * argv[] )
{
  for( int i=0; i<=argc; i++ )
  {
    cout << argv[i] << endl;
  }

}

int main ( int argc, char * argv[] )
{
    //displayArgs(argc, argv);
    getActions(argc, argv);
    Read myRead = Read ( );
    // Graph myGraph = Graph();

    myRead.openFile( "anonyme2.log" );
    Graph myGraph = Graph();

    // Ajout des logs
    while ( myRead.endOfFile( ) == false )
    {
            Log newLog;
            myRead.translate( );
            newLog = myRead.getMyLog();

            if ( typeSelection == true && timeSelection == false )
            {
              if ( newLog.targetExtension != "css" && newLog.targetExtension != "jpg" && newLog.targetExtension != "gif" && newLog.targetExtension != "ico")
              {
                myGraph.addLog( newLog.target, newLog.referer );
              }
            }

            else if ( timeSelection == true && typeSelection == false )
            {
              if ( newLog.hour >= hour && newLog.hour <= hour+1 )
              {
                myGraph.addLog( newLog.target, newLog.referer );
              }
            }
            else if ( typeSelection == true && timeSelection == true )
            {
                if ( newLog.targetExtension != "css" && newLog.targetExtension != "jpg" && newLog.targetExtension != "gif" && newLog.targetExtension != "ico" && newLog.hour >= hour && newLog.hour <= hour+1 )
                {
                    myGraph.addLog( newLog.target, newLog.referer );
                }
            }

            else
            {
               myGraph.addLog( newLog.target, newLog.referer );
            }

   }
   //myGraph.displayTargets();
   // Opérations sur le graph
   myGraph.searchTop();

   if ( doGraph == true )
   {
      myGraph.drawGraph(fichierDot);
   }

   return 0;
}
