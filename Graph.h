
#if ! defined ( GRAPH_H )
#define GRAPH_H

#include <map>
#include <iostream>
#include <string>
#include <istream>


using namespace std;

class Graph
{    
    public:

        Graph();
        Graph(const map <string, pair <map <string, int>,int>> aTargetGraph);
        ~Graph();

        void addLog(string Target, string Referer);
        void drawGraph(string destination_dot);
        void searchTop(); 
        
        
    protected:
        map <string, pair <map <string, int>,int>> TargetGraph;
};
#endif