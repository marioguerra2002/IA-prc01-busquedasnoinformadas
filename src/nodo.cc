#include "nodo.h"

Nodo::Nodo(int id_, MatrizDistancia matriz_) {
  id = id_;
  matriz = matriz_;
  for (int i = 0; i < matriz.getN(); ++i) {
    if (matriz.getMatriz()[id][i] != -1.0 && i != id) {
      vecinos.insert(std::make_pair(i, matriz.getMatriz()[id][i]));
    }
    // evitar segmentacion fault
    
  }

  
}
void Nodo::printVecinos() const {
  for (const auto& vecino : vecinos) {
    std::cout << "Vecino: " << vecino.first << " Distancia: " << vecino.second << std::endl;
  }
  
}


void Nodo::printNodo() const {
  std::cout << "Nodo: " << id << std::endl;
}
void Nodo::operator=(const Nodo& nodo) {
  id = nodo.id;
  vecinos = nodo.vecinos;
  matriz = nodo.matriz;

}

