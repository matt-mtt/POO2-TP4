/*************************************************************************
                              Graph -  description
                             -------------------
    début                : 12/2020
    copyright            : (C) 2020 par B.Pluvinet et M.Moutot
    e-mail               : berenice.pluvinet@insa-lyon.fr ; matthieu.moutot@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ----------------
#if ! defined ( GRAPH_H )
#define GRAPH_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>
#include <string>
#include <istream>
using namespace std;


//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Graph>
//
//
//------------------------------------------------------------------------

class Graph
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        void addLog(string Target, string Referer);
        // Mode d'emploi :
        // Permet d'ajouter un log au graph défini par une cible et un referer
        // Contrat :
        //

        void drawGraph(string destination_dot);
        // Mode d'emploi :
        // Permet de creer un fichier .dot pour dessiner le graph correspondant
        // Contrat :
        //

        void searchTop();
        // Mode d'emploi :
        // Permet d'afficher les 10 documents les plus consultés
        // Contrat :
        //

        void displayTargets();
        // Mode d'emploi :
        // Permet d'afficher tous les documents cibles pour verifier
        // le bon fonctionnement du programme
        // Contrat :
        //

        //------------------------------------------------- Surcharge d'opérateurs

        //-------------------------------------------- Constructeurs - destructeur
        Graph();
        // Mode d'emploi :
        //
        // Contrat :
        //

        Graph(const map <string, pair <map <string, int>,int>> aTargetGraph);
        // Mode d'emploi :
        //
        // Contrat :
        //

        ~Graph();
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
        map <string, pair <map <string, int>,int>> TargetGraph;

};
//-------------------------------- Autres définitions dépendantes de <Graph>

#endif //GRAPH_H
