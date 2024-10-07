#include "bfs.h"

#include <set>
#include <iostream>
#include <queue>
#include <stack>

class DFS {
  public:
    DFS(Grafo& grafo_, Nodo& nodo_inicial, Nodo& nodo_final);
    DFS() {};
    std::string printDFS(Nodo, Nodo); // imprime el recorrido DFS
    void cabezera(Nodo, Nodo);
    void Iteracion(Nodo, std::stack<Nodo>&, int);
    std::string printCaso1nodo(Nodo, Nodo);
  private:
    Grafo grafo;
    Nodo nodo_inicial;
    Nodo nodo_final;
    Nodo nodo_actual;
    std::set<int> visitados;
    std::vector<int> padres;
    int amplitud_maxima = 4;
    // amplitud maxima del arbol para evitar ramas infinitas
    std::stringstream hh;
    

    
};