// matriz donde se almacenaran las distancias de los nodos.
// son aristas, por lo que es bidireccional.

#ifndef MATRIZ_DISTANCIA_H
#define MATRIZ_DISTANCIA_H

#include <vector>
#include <iostream>

class MatrizDistancia {
  public:
    MatrizDistancia(int n);
    void setDistancia(int i, int j, int distancia);
    int getDistancia(int i, int j) const;
    int getN() const;
    void print() const;
  private:
    std::vector<std::vector<int>> matriz;
    int n;
};