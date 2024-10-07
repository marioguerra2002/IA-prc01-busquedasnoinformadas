#include "bfs.h"

#include <set>
#include <iostream>
#include <queue>
#include <stack>

class DFS {
  public:
    DFS(Grafo& grafo_, Nodo& nodo_inicial, Nodo& nodo_final);
    DFS() {};
    void printDFS(Nodo, Nodo); // imprime el recorrido DFS
  private:
    Grafo grafo;
    Nodo nodo_inicial;
    Nodo nodo_final;
    Nodo nodo_actual;
    std::set<int> visitados;
    std::vector<int> padres;
    int amplitud_maxima = 4;
    // amplitud maxima del arbol para evitar ramas infinitas
    

    
};