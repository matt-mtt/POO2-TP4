/*************************************************************************
                              Graph -  description
                             -------------------
    début                : 12/2020
    copyright            : (C) 2020 par B.Pluvinet et M.Moutot
    e-mail               : berenice.pluvinet@insa-lyon.fr ; matthieu.moutot@insa-lyon.fr
*************************************************************************/
//---------- Réalisation de la classe  (Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Read.h"
#include "Graph.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Graph::Graph(){
}

Graph::Graph(const map <string, pair <map <string, int>,int>> aTargetGraph){
    map <string, pair <map <string, int>,int>> TargetGraph (aTargetGraph);
}

Graph::~Graph(){

}

void Graph::addLog(string Target, string Referer){
    TargetGraph[Target].first[Referer]++;
    TargetGraph[Target].second++;
}

void Graph::drawGraph(string destination_dot){

    ofstream save ( destination_dot );

    if( save.is_open() ){

        map<string, string> nodes; //
        int i = 0; //compteur de noeuds
        save << "digraph {" << endl;

        //recuperer tous les nodes dans une map< nom du noeud, numero du noeud > et le nb de hits
        for( map <string, pair <map <string, int>,int>>::iterator target = TargetGraph.begin(); target != TargetGraph.end(); ++target)
        { // on parcourt toutes les cibles
            if(nodes.find(target->first)==nodes.end())
            { // si la cible n'est pas deja dans les noeuds
                string n = "node" + to_string(i); // je rajoute la cible parmi les noeuds
                nodes[target->first]=n;
                i++; // j'incrémente le compteur de noeud
            }
            for(map <string, int>::iterator ref = target->second.first.begin(); ref != target->second.first.end(); ++ref)
            { // on parcourt la map associée à la cible
                if(nodes.find(ref->first)==nodes.end())
                { // si le referer n'est pas un noeud
                    string n = "node" + to_string(i); // on l'ajoute aux noeuds
                    nodes[ref->first]=n;
                    i++;
                }
            }
        }

        //ecrire tous les noeuds
        for(map<string, string>::iterator no = nodes.begin(); no != nodes.end(); ++no){
            save << no->second << "[label=\"" << no->first <<"\"];" <<endl;
        }
    //recuperer les arcs d'un noeud à l'autre
    for( map <string, pair <map <string, int>,int>>::iterator target = TargetGraph.begin(); target != TargetGraph.end(); ++target){
        for(map <string, int>::iterator ref = target->second.first.begin(); ref != target->second.first.end(); ++ref){
            save << nodes.find(ref->first)->second << "->" << nodes.find(target->first)->second << "[label=\"" << ref->second <<"\"];" <<endl;
        }

    }
    save << "}" << endl;
    }

    else
    {
      cerr << "Erreur de creation d'un fichier de Sauvegarde"<< endl;
    }
}

void Graph::searchTop(){
    multimap <int, string, greater<int>> hits; //creer une map du nom des cibles et de leur nb de hits
    for(map <string, pair <map <string, int>,int>>::iterator target = TargetGraph.begin(); target != TargetGraph.end(); ++target){
        hits.insert(pair<int,string>(target->second.second,target->first));
    }

    cout << "Affichage du Top10" << endl;
    cout << "------------------" << endl;
    int i = 0;
    for(multimap <int, string, greater<int>>::iterator top10 = hits.begin(); top10!= hits.end() ; ++top10){
        if ( i<10)
        {
            cout << top10->second << " (" << top10->first << " hits)" << endl;
            i++;
        }

    }
}

void Graph::displayTargets()
{
    int i=0;
    for( map <string, pair <map <string, int>,int>>::iterator target = TargetGraph.begin(); target != TargetGraph.end(); ++target){
        cout << i << ": " << target->first << endl;
        i++;
    }
}
