#include "dfs.h"

DFS::DFS(Grafo& grafo_, Nodo& nodo_inicial_, Nodo& nodo_final_) {
  // en este caso, a diferencia del BFS, no voy a usar
  // una cola, sino una pila para el recorrido DFS
  // ya que el DFS es recursivo, pero para evitar problemas
  // de stack overflow, lo haremos iterativo, que significa que
  // usaremos una pila
  Nodo nodo_inicial = nodo_inicial_;
  Nodo nodo_final = nodo_final_;
  padres.resize(grafo_.getNodos().size(), -1);
  padres[nodo_inicial.getId()] = nodo_inicial.getId();
  // std::cout << "Padre nodo inicial: " << padres[nodo_inicial.getId()] << std::endl;
  std::stack<Nodo> a_inspeccionar; // aqui se guardan los nodos a visitar (no visitados)
  grafo = grafo_;
  // ponemos nodo inicial como padre de si mismo
  // comprobacion de todo este bien.
  if (nodo_inicial.getId() == nodo_final.getId()) {
    std::cout << "Nodo inicial y final son iguales\n";
    return;
  }
  // std::cout << "Nodo inicial: " << nodo_inicial.getId() << std::endl;
  // std::cout << "Vecinos del nodo inicial: " << std::endl;
  // nodo_inicial.printVecinos();
  a_inspeccionar.push(nodo_inicial); // encolamos el nodo inicial
  visitados.insert(nodo_inicial.getId()); // insertamos el nodo inicial
  while (!a_inspeccionar.empty()) {
    nodo_actual = a_inspeccionar.top();
    // std::cout << "Nodo actual: " << nodo_actual.getId() << std::endl;
    a_inspeccionar.pop();
    if (nodo_actual == nodo_final) {
      printDFS(nodo_final, nodo_inicial);
      break;
    }
    for (const auto& vecino : nodo_actual.getVecinos()) {
      if (visitados.find(vecino.first) == visitados.end()) {
        a_inspeccionar.push(grafo.getNodos()[vecino.first]);
        visitados.insert(vecino.first);
        padres[vecino.first] = nodo_actual.getId();
      }
    }
    // std::cout << "Nodos a inspeccionar: ";
    // std::stack<Nodo> aux = a_inspeccionar;
    // while (!aux.empty()) {
    //   std::cout << aux.top().getId() << " ";
    //   aux.pop();
    // }
    // std::cout << std::endl;
  }
}

void DFS::printDFS(Nodo nodofinal, Nodo nodo_inicial) {
  Nodo nodo_anterior;
  Nodo auxiliar = nodo_inicial;
  std::stack<int> camino;
  float coste_total = 0.0;
  while (nodo_actual.getId() != nodo_inicial.getId()) {
    nodo_anterior = nodo_actual;
    camino.push(padres[nodo_actual.getId()]);
    nodo_actual = grafo.getNodos()[padres[nodo_actual.getId()]]; 
    // asignamos el siguiente nodo, que es el padre del actual
    coste_total += nodo_anterior.getVecinos().at(nodo_actual.getId()); 
    // accedemos al map de vecinos y sumamos el coste
    
  }
  while (!camino.empty()) {
    std::cout << camino.top() << " -> ";
    camino.pop();
  }
  std::cout << nodofinal.getId() << std::endl;
  std::cout << "Coste total: " << coste_total << std::endl;
  
  
}