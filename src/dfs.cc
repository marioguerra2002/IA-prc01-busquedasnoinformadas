#include "dfs.h"

DFS::DFS(Grafo& grafo_, Nodo& nodo_inicial_, Nodo& nodo_final_) {
  // en este caso, a diferencia del BFS, no voy a usar
  // una cola, sino una pila para el recorrido DFS
  // ya que el DFS es recursivo, pero para evitar problemas
  // de stack overflow, lo haremos iterativo, que significa que
  // usaremos una pila
  Nodo nodo_inicial = nodo_inicial_;
  Nodo nodo_final = nodo_final_;
  if (nodo_inicial.getId() == nodo_final.getId()) {
    printCaso1nodo(nodo_final, nodo_inicial);
    return;
  }
  padres.resize(grafo_.getNodos().size(), -1);
  padres[nodo_inicial.getId()] = nodo_inicial.getId();
  // std::cout << "Padre nodo inicial: " << padres[nodo_inicial.getId()] << std::endl;
  grafo = grafo_;
  std::stack<Nodo> a_inspeccionar; // aqui se guardan los nodos a visitar (no visitados)
  // ponemos nodo inicial como padre de si mismo
  // comprobacion de todo este bien.
  // std::cout << "Nodo inicial: " << nodo_inicial.getId() << std::endl;
  // std::cout << "Vecinos del nodo inicial: " << std::endl;
  // nodo_inicial.printVecinos();
  a_inspeccionar.push(nodo_inicial); // encolamos el nodo inicial
  visitados.insert(nodo_inicial.getId()); // insertamos el nodo inicial
  cabezera(nodo_inicial, nodo_final);
  int iteracion = 0;
  while (!a_inspeccionar.empty()) {
    nodo_actual = a_inspeccionar.top();
    // std::cout << "Nodo actual: " << nodo_actual.getId() << std::endl;
    a_inspeccionar.pop();
    if (nodo_actual == nodo_final) {
      printDFS(nodo_final, nodo_inicial);
      break;
    }
    hh << "Iteracion: " << iteracion << std::endl;
    for (const auto& vecino : nodo_actual.getVecinos()) {
      if (visitados.find(vecino.first) == visitados.end()) {
        a_inspeccionar.push(grafo.getNodos()[vecino.first]);
        visitados.insert(vecino.first);
        padres[vecino.first] = nodo_actual.getId();
      }
    }
    Iteracion(nodo_actual, a_inspeccionar, iteracion);
    iteracion++;
    // std::cout << "Nodos a inspeccionar: ";
    // std::stack<Nodo> aux = a_inspeccionar;
    // while (!aux.empty()) {
    //   std::cout << aux.top().getId() << " ";
    //   aux.pop();
    // }
    // std::cout << std::endl;
  }
}

std::string DFS::printDFS(Nodo nodofinal, Nodo nodo_inicial) {
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
  hh << "Camino hasta el nodo final: ";
  while (!camino.empty()) {
    // std::cout << camino.top() << " -> ";
    hh << camino.top() << " -> ";
    camino.pop();
  }
  hh << nodofinal.getId() << std::endl;
  hh << "Coste total: " << coste_total << std::endl;
  
  return hh.str();
}

void DFS::cabezera(Nodo nodo_inicial, Nodo nodo_final) {
    hh << "Numero de nodos: " << grafo.getNodos().size() << std::endl;
    hh << "Numero de aristas: " << grafo.getNumeroAristas() << std::endl;
    hh << "Nodo inicial: " << nodo_inicial.getId() << std::endl;
    hh << "Nodo final: " << nodo_final.getId() << std::endl;
    hh << "_________________________________________" << std::endl;
}

void DFS::Iteracion(Nodo nodo_actual, std::stack<Nodo>& a_inspeccionar, int iteracion) {
    
    hh << "Iteracion: " << iteracion << std::endl;
    hh << "Nodos generados: ";
    for (const auto& vecino : nodo_actual.getVecinos()) {
        hh << vecino.first << " ";
    }
    hh << std::endl;
    hh << "Nodos inspeccionados: ";
    std::stack<Nodo> aux = a_inspeccionar;
    while (!aux.empty()) {
        hh << aux.top().getId() << " ";
        aux.pop();
    }
    hh << std::endl;
    hh << "_________________________________________" << std::endl;
    
}

std::string DFS::printCaso1nodo(Nodo nodofinal, Nodo nodo_inicial) {
    hh << "Numero de nodos: 1" << std::endl;
    hh << "Numero de aristas: 1" << std::endl;
    hh << "Nodo inicial: " << nodo_inicial.getId() << std::endl;
    hh << "Nodo final: " << nodofinal.getId() << std::endl;
    hh << "_______________________________________" << std::endl;
    hh << "Iteracion: 0" << std::endl;
    hh << "Nodos generados: " << nodo_inicial.getId() << std::endl;
    hh << "Nodos inspeccionados: " << nodo_inicial.getId() << std::endl;
    hh << "_______________________________________" << std::endl;
    hh << "Camino hasta el nodo final: " << nodo_inicial.getId() << " -> " << nodofinal.getId() << std::endl;
    hh << "Coste total: 0.00" << std::endl;

    return hh.str();
}

