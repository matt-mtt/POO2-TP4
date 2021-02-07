
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int compteur;

#include "Graph.h"
  

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

        map<string, string> nodes;
        int i = 0; //compteur de noeuds
        save << "digraph {" << endl;

        //recuperer tous les nodes dans une map< nom du noeud, numero du noeud > et le nb de hits
        for( map <string, pair <map <string, int>,int>>::iterator target = TargetGraph.begin(); target != TargetGraph.end(); ++target){
            if(nodes.find(target->first)==nodes.end()){
                string n = "node" + to_string(i); 
                nodes[target->first]=n;
                i++;
            }
            for(map <string, int>::iterator ref = target->second.first.begin(); ref != target->second.first.end(); ++target){
                if(nodes.find(ref->first)==nodes.end()){
                    string n = "node" + to_string(i);
                    nodes[ref->first]=n;
                } 
            }
        }
        //ecrire tous les noeuds
        for(map<string, string>::iterator no = nodes.begin(); no != nodes.end(); ++no){
            save << no->second << "[label=\"" << no->first <<"\"];" <<endl;
        }
    
    //recuperer les arcs d'un noeud à l'autre
    for( map <string, pair <map <string, int>,int>>::iterator target = TargetGraph.begin(); target != TargetGraph.end(); ++target){
        for(map <string, int>::iterator ref = target->second.first.begin(); ref != target->second.first.end(); ++target){
            save << nodes.find(ref->first)->second << "->" << nodes.find(target->first)->second << "[label=\"" << ref->second <<"];" <<endl;
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

    map <int, string> hits; //creer une map du nom des cibles et de leur nb de hits 
    for(map <string, pair <map <string, int>,int>>::iterator target = TargetGraph.begin(); target != TargetGraph.end(); ++target){
        hits[target->second.second]= target->first;
    }                                               
    
    int i = 0;
    while (i <10)
    {    
        for(map <int, string>::iterator top10 = hits.begin(); top10!= hits.end(); ++top10){
            cout << top10->second << " (" << top10->first << " hits)" << endl;
            i++;
        }
    }
}