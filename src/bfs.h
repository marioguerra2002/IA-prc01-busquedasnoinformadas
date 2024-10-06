#include "grafo.h"

#include <set>
#include <iostream>
#include <queue>

class BFS {
  public:
    BFS(Grafo grafo_, int nodo_inicial_);
    BFS() {};
    void printBFS(); // imprime el recorrido BFS
    bool isFinalNode(); // verifica si el nodo final fue visitado
    std::set<Nodo> camino(); // camino desde el nodo inicial al nodo final
  private:
    Grafo grafo;
    Nodo nodo_inicial;
    Nodo nodo_final;
    Nodo nodo_actual;
    std::set<int> visitados;
    std::set<int> no_visitados;

    
};