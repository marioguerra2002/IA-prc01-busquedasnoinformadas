#include "nodo.h"
#include "matriz_distancia.h"
#include <fstream>

class Grafo {
  public:
    Grafo(int, MatrizDistancia);
    void printGrafo();
    void generarDot(const std::string&);
  private:
    std::vector<Nodo> nodos;
    MatrizDistancia matriz;
    int n;
};