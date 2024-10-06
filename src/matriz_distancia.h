// matriz donde se almacenaran las distancias de los nodos.
// son aristas, por lo que es bidireccional.

#ifndef MATRIZ_DISTANCIA_H
#define MATRIZ_DISTANCIA_H

#include <vector>
#include <iostream>

class MatrizDistancia {
  public:
    MatrizDistancia(int, std::vector<std::string> input);
    void setMatrizSize(int n);
    
  private:
    float** matriz;
    int n;
};

#endif // MATRIZ_DISTANCIA_H