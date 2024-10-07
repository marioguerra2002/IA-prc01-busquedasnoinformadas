#include "bfs.h"

std::stringstream final;
BFS::BFS(Grafo& grafo_, Nodo& nodo_inicial_, Nodo& nodo_final_) {
  std::stringstream ss;
  Nodo nodo_inicial = nodo_inicial_;
  Nodo nodo_final = nodo_final_;
  padres.resize(grafo_.getNodos().size(), -1);
  padres[nodo_inicial.getId()] = nodo_inicial.getId();

  // std::cout << "Nodo inicial: " << nodo_inicial.getId() << std::endl;
  grafo = grafo_;
  
  // creamos cola de nodos vacia
  std::queue<Nodo> a_inspeccionar; // aqui se guardan los nodos a visitar (no visitados)
  // conjunto de nodos visitados
  // ponemos nodo inicial como padre de si mismo
  
  
  // comprobacion de todo este bien.
  // std::cout << "Vecinos del nodo inicial: " << std::endl;
  // nodo_inicial.printVecinos();
  a_inspeccionar.push(nodo_inicial); // encolamos el nodo inicial
  visitados.insert(nodo_inicial.getId()); // insertamos el nodo inicial
  cabezera(nodo_inicial, nodo_final);
  int iteracion = 0;

  while (!a_inspeccionar.empty()) {
    // desecolamos el nodo actual
    nodo_actual = a_inspeccionar.front();
    // std::cout << "Nodo actual: " << nodo_actual.getId() << std::endl;
    a_inspeccionar.pop();

    if (nodo_actual == nodo_final) {
      printBFS(nodo_final, nodo_inicial);
      break;
    }
    ss << "Iteracion: " << iteracion << std::endl;
    for (const auto& vecino : nodo_actual.getVecinos()) {
      // si el vecino no ha sido visitado 
      if (visitados.find(vecino.first) == visitados.end()) { // recorre el conjunto de visitados
        // si llega al final es que no ha sido visitado, por lo que lo añadimos a la cola
        // visitados.insert(nodo_actual.getId()); // lo añadimos a los visitados
        
        a_inspeccionar.push(grafo.getNodos()[vecino.first]);
        // lo añadimos a los visitados
        visitados.insert(vecino.first);
        // lo ponemos como padre del nodo actual
        // std::cout << "Nodo actual: " << nodo_actual.getId() << std::endl;
        // std::cout << "Nodo al que se le asigna padre: " << grafo.getNodos() [vecino.first].getId() << std::endl;
        padres[vecino.first] = nodo_actual.getId();
      }
    }
    // nodos generados e inspeccionados
    Iteracion(nodo_actual, a_inspeccionar, iteracion);
    iteracion++;

    // std::cout << "Nodos a inspeccionar: " << std::endl;
    // std::queue<Nodo> aux = a_inspeccionar;
    // while (!aux.empty()) {
    //   std::cout << aux.front().getId() << " ";
    //   aux.pop();
    // }
    // std::cout << std::endl;

  }
  // std::cout << "Padres: " << std::endl;
  // for (int i = 0; i < padres.size(); ++i) {
  //   std::cout << padres[i] << " ";
  // }
}

std::string BFS::printBFS(Nodo nodofinal, Nodo nodo_inicial) { 
  Nodo nodo_anterior;
  std::stack<int> camino;
  // std::cout << "Nodo final: " << nodofinal.getId() << std::endl;
  float coste_total = 0.0;
  // std::cout << "Nodo actual: " << nodo_actual.getId() << std::endl;
  while (nodo_actual.getId() != nodo_inicial.getId()) {
    nodo_anterior = nodo_actual; // guardamos el nodo actual en el nodo anterior para poder mirar el coste
    camino.push(padres[nodo_actual.getId()]);
    nodo_actual = grafo.getNodos()[padres[nodo_actual.getId()]];
    // tengo que añadir el coste de la arista del nodo actual al nodo anterior (voy desde el final al principio)
    coste_total += nodo_anterior.getVecinos().at(nodo_actual.getId());
    
  }
  ss << "Camino hasta el nodo final: ";
  while (!camino.empty()) {
    ss << camino.top() << " -> ";
    camino.pop();
  }
  ss << nodofinal.getId() << std::endl;
  ss << "Coste total: " << coste_total << std::endl;
  return ss.str();
}

void BFS::cabezera(Nodo nodo_inicial, Nodo nodo_final) {
  ss << "Numero de nodos: " << grafo.getNodos().size() << std::endl;
  ss << "Numero de aristas: " << grafo.getNumeroAristas() << std::endl;
  ss << "Nodo inicial: " << nodo_inicial.getId() << std::endl;
  ss << "Nodo final: " << nodo_final.getId() << std::endl;
  ss << "_________________________________________" << std::endl;
  
}

void BFS::Iteracion(Nodo nodo_actual, std::queue<Nodo>& a_inspeccionar, int iteracion) {
  
  ss << "Iteracion: " << iteracion << std::endl;
  ss << "Nodos generados: ";
  for (const auto& vecino : nodo_actual.getVecinos()) {
    ss << vecino.first << " ";
  }
  ss << std::endl;
  ss << "Nodos inspeccionados: ";
  std::queue<Nodo> aux = a_inspeccionar;
  while (!aux.empty()) {
    ss << aux.front().getId() << " ";
    aux.pop();
  }
  ss << std::endl;
  ss << "_________________________________________" << std::endl;
  
}