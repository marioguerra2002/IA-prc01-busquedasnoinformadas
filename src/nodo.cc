#include "nodo.h"

Nodo::Nodo(int id_, MatrizDistancia matriz_) {
  id = id_;
  matriz = matriz_;
  for (int i = 0; i < matriz.getN(); ++i) {
    if (matriz.getMatriz()[id][i] != -1.0 && i != id) {
      vecinos.insert(std::make_pair(i, matriz.getMatriz()[id][i]));
    }
  }
}
void Nodo::printVecinos() const {
  for (auto it = vecinos.begin(); it != vecinos.end(); ++it) {
    std::cout << "Nodo: " << id << " Vecino: " << it->first << " Distancia: " << it->second << std::endl;
  }
}


void Nodo::printNodo() const {
  std::cout << "Nodo: " << id << std::endl;
}