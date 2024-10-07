#include "grafo.h"

#include <sstream>
#include <set>
#include <iostream>
#include <queue>
#include <stack>

class BFS {
  public:
    BFS(Grafo& grafo_, Nodo& nodo_inicial, Nodo& nodo_final);
    BFS() {};
    std::string printBFS(Nodo, Nodo); // imprime el recorrido BFS
    void cabezera(Nodo, Nodo);
    void Iteracion(Nodo, std::queue<Nodo>&, int);
    std::string printCaso1nodo(Nodo, Nodo);

  
  private:
    Grafo grafo;
    Nodo nodo_inicial;
    Nodo nodo_final;
    Nodo nodo_actual;
    std::set<int> visitados;
    std::vector<int> padres;
    std::stringstream ss;
    

    
};