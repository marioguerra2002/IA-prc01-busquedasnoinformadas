#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "matriz_distancia.h"

class Nodo {
  public:
    Nodo(int id_, MatrizDistancia matriz_);
    int getId() { return id; }
    void operator=(const Nodo& nodo) {
      id = nodo.id;
      vecinos = nodo.vecinos;
      matriz = nodo.matriz;
    }
    void printVecinos() const;
    void printNodo() const;
    const std::map<int, float> getVecinos() { return vecinos; }
  private:
    int id;
    std::map<int, float> vecinos;
    MatrizDistancia matriz;
    
};

