#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "matriz_distancia.h"

class Nodo {
  public:
    Nodo(int id_, MatrizDistancia matriz_);
    Nodo() {}
    int getId() { return id; }
    void operator=(const Nodo& nodo);
    void printVecinos() const;
    void printNodo() const;
    const std::map<int, float> getVecinos() { return vecinos; }
    bool operator==(const Nodo& nodo) {
      return id == nodo.id;
    }
  private:
    int id;
    std::map<int, float> vecinos;
    MatrizDistancia matriz;
    
};

