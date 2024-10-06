#include "bfs.h"

BFS::BFS(Grafo grafo_, int nodo_inicial_) {
  Nodo nodo_inicial = grafo_.getNodos()[nodo_inicial_];
  grafo = grafo_;
  // creamos cola de nodos vacia
  std::queue<Nodo> cola;
  // conjunto de nodos visitados
  cola.push(nodo_inicial); // encolamos el nodo inicial
  visitados.insert(nodo_inicial.getId()); // insertamos el nodo inicial
  while (!cola.empty()) {
    // desecolamos el nodo actual
    nodo_actual = cola.front();
    cola.pop();
    if (isFinalNode()) {
      break;
      // aqui habria falta de implementar el camino
    }
    // recorremos los vecinos del nodo actual
    for (const auto& vecino : nodo_actual.getVecinos()) {
      // si el vecino no ha sido visitado
      if (visitados.find(vecino.first) == visitados.end()) { // recorre el conjunto de visitados
        // lo añadimos a la cola
        cola.push(grafo.getNodos()[vecino.first]);
        // lo añadimos a los visitados
        visitados.insert(vecino.first);
      }

    }

  }


}

bool BFS::isFinalNode() {
  return nodo_actual == nodo_final;
}
  
std::set<Nodo> BFS::camino() {
  

}