#include "grafo.h"

#include <set>
#include <iostream>
#include <queue>
#include <stack>

class BFS {
  public:
    BFS(Grafo& grafo_, Nodo& nodo_inicial, Nodo& nodo_final);
    BFS() {};
    void printBFS(Nodo); // imprime el recorrido BFS
    std::set<Nodo> camino(); // camino desde el nodo inicial al nodo final
  private:
    Grafo grafo;
    Nodo nodo_inicial;
    Nodo nodo_final;
    Nodo nodo_actual;
    std::set<int> visitados;
    std::vector<int> padres;
    

    
};